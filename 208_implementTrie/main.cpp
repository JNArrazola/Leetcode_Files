#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <array>
#include <set>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <deque>
#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("03")
#pragma GCC target ("avx")

#define PI (3.141592);

typedef long long ll;
typedef long l;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

template <typename R>
using st = stack<R>;

class TrieNode{
public:
    TrieNode *child[26];
    bool endWord = false;

    TrieNode(){
        for (size_t i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;

        for(const char &c : word){
            if(curr->child[c - 'a']) curr = curr->child[c - 'a'];
            else {
                curr->child[c - 'a'] = new TrieNode();
                curr = curr->child[c - 'a'];
            }
        }

        curr->endWord = true;
    }
    
    bool searchWithPreffix(const string &word, const bool &lForPreffix){
        TrieNode *curr = root;

        for(const char &c : word){
            if(!curr->child[c - 'a']) return false;
            curr = curr->child[c - 'a'];
        }

        if(lForPreffix) return true;
        
        return curr->endWord;
    }

    bool search(string word) {
        return searchWithPreffix(word, false);
    }
    
    bool startsWith(string prefix) {
        return searchWithPreffix(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{

    return 0;
}