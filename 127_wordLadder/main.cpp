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
private: 
    void makeRegister(pair<string, int> &candidate, unordered_set<string> &dictionary, queue<pair<string, int>> &bfs){
        if(dictionary.find(candidate.first) != dictionary.end()){
            bfs.push({candidate.first, candidate.second + 1});
            dictionary.erase(candidate.first);
        }
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dictionary = {wordList.begin(), wordList.end()};

        queue<pair<string, int>> bfs;
        bfs.push({beginWord, 1});
        dictionary.erase(beginWord);

        while (!bfs.empty())
        {
            pair<string, int> top = bfs.front();

            if(top.first == endWord)
                return top.second;
            
            for (size_t i = 0; i < endWord.size(); i++){
                char temp = top.first[i];
                for (size_t j = 0; j < 26; j++){
                    top.first[i] = 'a' + j;
                    makeRegister(top, dictionary, bfs);
                }
                top.first[i] = temp;
            }
            bfs.pop();
        }
        return 0;
    }
};

int main()
{
    string a = "hit";
    string b = "cog";
    vector<string> wl = {"hot","dot","dog","lot","log","cog"};

    Solution s;

    cout << s.ladderLength(a, b, wl) << endl;

    return 0;
}