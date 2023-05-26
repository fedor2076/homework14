#pragma once
#include <iostream>
#include <string>

using namespace std;
const int MaxBranchNum = 26;
//const int MaxWord = 5;
class TrieNode {
public:
    string word;
    int path;  // Сколько раз был пересечен символ, используется для подсчета количества строк с префиксом символьной строки
    int End; // Строка, заканчивающаяся этим символом
 
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


    // Вставляем строку str
    void insert(string str, int n);
   
    // Проверяем, появилась ли строка str, и возвращаем как префикс несколько раз
    int search(string str);
    
    // Распечатываем все узлы в дереве
    void printAll();
    // Вывести слова с префиксом str
   void printPre(string str);
    // Выводим все слова с корнем в лексикографическом порядке
    void Print(TrieNode* root);
    // Возвращает количество слов с префиксом str
    int prefixNumbers(string str);
};
