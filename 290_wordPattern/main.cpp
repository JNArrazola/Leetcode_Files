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
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        unordered_map<char, string> hm;
        unordered_set<string> mappedWords;

        string formedWord = "";
        for(const char &c : s)
            if(c == ' '){
                words.push_back(formedWord);
                formedWord = "";
            } else 
                formedWord+=c;
        
        words.push_back(formedWord);

        if(pattern.length() != words.size())
            return false;
        
        for (size_t i = 0; i < words.size(); i++)
        {
            if(hm.find(pattern[i])==hm.end()){
                if(mappedWords.find(words[i])!=mappedWords.end())
                    return false;

                hm[pattern[i]] = words[i];
                mappedWords.insert(words[i]);
            }
            else if(hm[pattern[i]] != words[i])
                return false;
        }
        
        return true;
    }
};

int main()
{

    return 0;
}