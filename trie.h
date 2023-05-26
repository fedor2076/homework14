#pragma once
#include <iostream>
#include <string>

using namespace std;
const int MaxBranchNum = 26;
//const int MaxWord = 5;
class TrieNode {
public:
    string word;
    int path;  // ������� ��� ��� ��������� ������, ������������ ��� �������� ���������� ����� � ��������� ���������� ������
    int End; // ������, ��������������� ���� ��������
 
    TrieNode* nexts[MaxBranchNum];

    TrieNode()
    {
        word = "";
        path = 0;
        End = 0;
        memset(nexts, NULL, sizeof(TrieNode*) * MaxBranchNum);
    }

};

class TrieTree {
private:
    TrieNode* root;
public:
    TrieTree();
    ~TrieTree();
    void destory(TrieNode* root);


    // ��������� ������ str
    void insert(string str, int n);
   
    // ���������, ��������� �� ������ str, � ���������� ��� ������� ��������� ���
    int search(string str);
    
    // ������������� ��� ���� � ������
    void printAll();
    // ������� ����� � ��������� str
   void printPre(string str);
    // ������� ��� ����� � ������ � ������������������ �������
    void Print(TrieNode* root);
    // ���������� ���������� ���� � ��������� str
    int prefixNumbers(string str);
};
