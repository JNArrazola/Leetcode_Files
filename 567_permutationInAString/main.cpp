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
    void check(const int &idx, int &ctr, unordered_map<char, int> &hm1, unordered_map<char, int> &hm2, unordered_set<char> &st, const string &s){
        if(hm1.find(s[idx]) != hm1.end()){
            if(hm1[s[idx]] == hm2[s[idx]] && st.find(s[idx]) == st.end()){
                ctr++;
                st.insert(s[idx]);
            } else if(st.find(s[idx]) != st.end()){
                ctr--;
                st.erase(s[idx]);
            }
        }
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        
        unordered_map<char, int> hm1, hm2;
        unordered_set<char> st;

        int ctr1 = 0, ctr2 = 0, i = 0, j = 0;
        for(const char &c : s1){
            if(hm1.find(c) == hm1.end())
                ctr1++;
            hm1[c]++;
        }

        while (j < s1.size())
        {
            hm2[s2[j]]++;

            check(j, ctr2, hm1, hm2, st, s2);

            if(ctr1 == ctr2)
                return true;
            j++;
        }
        
        while (j < s2.size())
        {
            hm2[s2[i]]--;
            hm2[s2[j]]++;

            check(i, ctr2, hm1, hm2, st, s2);
            check(j, ctr2, hm1, hm2, st, s2);

            if(ctr1 == ctr2)
                return true;

            i++;
            j++;
        }
        
        return false;
    }
};

int main()
{
    Solution s;

    cout << s.checkInclusion("abc", "cccccbabbbaaaa") << endl;
    

    return 0;
}