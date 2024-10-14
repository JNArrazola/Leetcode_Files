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
    TrieNode* child[26];
    bool endWord;
    
    TrieNode(){
        endWord = false;

        for (size_t i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class MagicDictionary {
private:    
    TrieNode *root;

    void buildWord(const string &s){
        TrieNode *curr = root;

        for(const char &c : s){
            if(!curr->child[c - 'a']) curr->child[c - 'a'] = new TrieNode();
            curr = curr->child[c - 'a'];
        }
        curr->endWord = true;
    }
    
    bool searchWithChange(const string &s, TrieNode *nd, const int idx, bool madeChange){
        if(!nd)
            return false;
        
        TrieNode *curr = nd;

        for (int i = idx; i < s.size(); i++){
            if(!madeChange){
                for (int j = 0; j < 26; j++)
                    if(curr->child[j] && j != s[i] - 'a')
                        if(searchWithChange(s, curr->child[j], i + 1, true))
                            return true;
            } 
            if(curr->child[s[i] - 'a']) curr = curr->child[s[i] - 'a'];
            else return false;
        }
        
        return curr->endWord && madeChange;
    }

public:
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for(const string &s : dictionary)
            buildWord(s);
    }
    
    bool search(string searchWord) {
        return searchWithChange(searchWord, root, 0, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main()
{
    MagicDictionary* mg = new MagicDictionary();
    mg->buildDict({"hello","leetcode"});



    return 0;
}