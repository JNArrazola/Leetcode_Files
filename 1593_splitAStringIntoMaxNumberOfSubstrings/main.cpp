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

class Solution {
private:
    int solve(const string &s, int idx, unordered_set<string> &st){
        if(idx == s.size())
            return st.size();
        
        string str = "";
        int answ = 1;
        for (size_t i = idx; i < s.size(); i++)
        {
            str+=s[i];
            if(st.find(str) != st.end())
                continue;
            
            st.insert(str);
            answ = max(answ, solve(s, i + 1, st));

            st.erase(str);
        }
        
        return answ;
    }
    
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return solve(s, 0, st);
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}