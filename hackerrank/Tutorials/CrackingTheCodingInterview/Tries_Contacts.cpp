//https://www.hackerrank.com/challenges/ctci-contacts
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const size_t ALPHABET_NUM = 'z'-'a'+1;
struct TrieNode 
{
    struct TrieNode *children[ALPHABET_NUM];
    size_t count;
    bool isLeaf;
};

static struct TrieNode *createNode()
{
    struct TrieNode* node = new TrieNode();
    if (node != nullptr)
    {
        for (size_t i = 0; i < ALPHABET_NUM; ++i )
        {
            node->children[i] = nullptr;
            node->isLeaf = false;
            node->count = 0;
        }
    }
    return node;
}

static void add(TrieNode* const root, const std::string& key)
{
    if(root == nullptr || key.length() == 0)
    {
        return;
    }   
    TrieNode* temp = root;
    for (size_t i = 0; i < key.length(); ++i )
    {
        size_t idx = key.at(i) - 'a';
        if(temp->children[idx] == nullptr)
        {
            temp->children[idx] = createNode();
        }
        temp->children[idx]->count += 1;
        temp = temp->children[idx];
    }
    temp->isLeaf = true; //last Node
}


static size_t findPartialUtil(const TrieNode* const node)
{
    if(node == nullptr)
    {
        return 0;
    }
    size_t num = 0;
    
    if(node->isLeaf == true)
    {
        num += 1;
    }
    
    for (size_t i = 0; i < ALPHABET_NUM; ++i )
    {
        num += findPartialUtil(node->children[i]);
    }
    return num;  
}

static size_t findPartial(TrieNode* const root, const std::string& partial)
{
    if(root == nullptr || partial.length() == 0)
    {
        return 0;
    }   
    TrieNode* temp = root;
    for (size_t i = 0; i < partial.length(); ++i )
    {
        size_t idx = partial.at(i) - 'a';
        if(temp->children[idx] == nullptr)
        {
            return 0;
        }
        temp = temp->children[idx];
    }
    return temp->count;
    //return findPartialUtil(temp); //search for full words ended by the leaf
}

int main(){
    int n;
    cin >> n;
    TrieNode *root = createNode();
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if(op == "add")
        {
            add(root, contact);            
        }
        else if(op == "find")
        {
            cout<<findPartial(root, contact)<<endl;    
        }
    }
    return 0;
}
