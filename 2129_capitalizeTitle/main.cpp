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
public:
    string capitalizeTitle(string t) {
        string answ = "", temp = "";

        for (size_t i = 0; i < t.size(); i++)
        {
            if(t[i] == ' ' || i == t.size() - 1){
                if(i == t.size() - 1)
                    temp+=tolower(t[i]);
                
                if(temp.size() > 2)
                    temp[0] = toupper(temp[0]);
                answ += temp + " ";
                temp = "";
                continue;
            } 
            temp+=tolower(t[i]);
        }
        
        return answ.substr(0, answ.size() - 1);
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}