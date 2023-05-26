#include "trie.h"
TrieTree::TrieTree()
{
    root = new TrieNode();
}


TrieTree::~TrieTree()
{
    destory(root);
}

void TrieTree::destory(TrieNode* root)
{
    if (root == nullptr)
        return;
    for (int i = 0; i < MaxBranchNum; i++)
    {
        destory(root->nexts[i]);
    }
    delete root;
    root = nullptr;
}


void TrieTree::insert(string str, int n)
{
    if (str == "")
        return;
    string buf = str;

    TrieNode* node = root;
    int index = 0;
    for (int i = 0; i < buf.length(); i++)
    {
        index = buf[i] - 'a';
        if (node->nexts[index] == nullptr)
        {
            node->nexts[index] = new TrieNode();
        }
        node = node->nexts[index];
        node->path++;// Через этот узел есть путь
    }
    node->End++;
    node->word = str;
}
int TrieTree::search(string str)
{
    if (str == "")
        return 0;

    string buf = str;
    TrieNode* node = root;
    int index = 0;
    for (int i = 0; i < buf.length(); i++)
    {
        index = buf[i] - 'a';
        if (node->nexts[index] == nullptr)
        {
            return 0;
        }
        node = node->nexts[index];
    }
    if (node != nullptr)
    {
        return node->End;
    }
    else
    {
        return 0;
    }
}
int TrieTree::prefixNumbers(string str)
{
    if (str == "")
        return 0;

    string buf = str;
    TrieNode* node = root;
    int index = 0;
    for (int i = 0; i < buf.length(); i++)
    {
        index = buf[i] - 'a';
        if (node->nexts[index] == nullptr)
        {
            return 0;
        }
        node = node->nexts[index];
    }
    return node->path;
}
void TrieTree::printPre(string str)
{
    if (str == "")
        return;
    int k = 1;
    string buf = str;
    TrieNode* node = root;
    int index = 0;
    for (int i = 0; i < buf.length(); i++)
    {
        index = buf[i] - 'a';
        if (node->nexts[index] == nullptr)
        {
            return;
        }
        node = node->nexts[index];

    }
   
    Print(node);

}
void TrieTree::Print(TrieNode* node)
{
    if (node == nullptr)
        return;
   
    if (node->word != "")
    {
        cout << node->word << endl;
     }

    for (int i = 0; i < MaxBranchNum; i++)
    {
        if (node->nexts != nullptr) 
        {
            Print(node->nexts[i]);
        }
    }

}
void TrieTree::printAll()
{
   
    Print(root);
}

