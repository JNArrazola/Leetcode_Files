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
        unordered_map<string, char> mp;

        int ctrWord = 0;

        string formedWord = "";
        for (size_t i = 0; i < s.size(); i++)
        {
            if(s[i] == ' '||i == s.size() - 1){
                if(i == s.size() - 1)
                    formedWord+=s[i];

                if(mp.find(formedWord) != mp.end())
            }
        }
        
        return true;
    }
};

int main()
{

    return 0;
}