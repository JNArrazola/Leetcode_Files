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
#include <set>
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

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
private:
    bool solve(unordered_map<int, char> &hm, string &word){
        unordered_map<char, char> relation;
        unordered_set<char> mapped_chars;

        for (int i = 0; i < word.size(); i++)
            if(relation.find(word[i]) == relation.end() && mapped_chars.find(hm[i]) == mapped_chars.end()){
                relation[word[i]] = hm[i];
                mapped_chars.insert(hm[i]);
            }
            else if(relation[word[i]] != hm[i])
                return false;

        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        unordered_map<int, char> hm;

        for (int i = 0; i < pattern.size(); i++)
            hm[i] = pattern[i];

        vector<string> answ;
        for (size_t i = 0; i < words.size(); i++)
            if(solve(hm, words[i]))
                answ.push_back(words[i]);
        
        return answ;
    }
};

int main()
{

    return 0;
}