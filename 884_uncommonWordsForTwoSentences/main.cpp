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

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        int start = 0;
        unordered_map<string, int> mp;
        vector<string> answ;

        s1+=" "; 
        s2+=" "; 

        for (size_t i = 0; i < s1.size(); i++)
        {
            if(s1[i] == ' '){
                mp[s1.substr(start, i - start)]++;
                start = i + 1;
            }
        }

        start = 0;
        for (size_t i = 0; i < s2.size(); i++)
        {
            if(s2[i] == ' '){
                mp[s2.substr(start, i - start)]++;
                start = i + 1;
            }
        }

        for(auto itr : mp)
            if(itr.second == 1)
                answ.push_back(itr.first);

        return answ;
    }
};

int main()
{

    return 0;
}