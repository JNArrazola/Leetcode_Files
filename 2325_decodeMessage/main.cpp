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
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;

        int ctr = 0;

        for (size_t i = 0; i < key.size(); i++)
        {
            if(key[i] == ' ') continue;

            if(mp.find(key[i]) == mp.end())
                mp[key[i]] = 'a' + ctr++;
        }
        
        string answ = "";
        for (size_t i = 0; i < message.size(); i++)
        {
            if(message[i] == ' ')
                answ+=" ";
            else 
                answ+=mp[message[i]];
        }
        
        return answ;
    }
};

int main()
{

    return 0;
}