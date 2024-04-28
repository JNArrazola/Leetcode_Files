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
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty())
            return ((n == 1) ? 1 : -1);
        

        unordered_map<int, int> isTrusted;
        unordered_map<int, int> trusts;

        for(const vector<int> & v : trust){
            trusts[v[0]]++;
            isTrusted[v[1]]++;
        }

        for(auto a : isTrusted)
            if(isTrusted[a.first] == n - 1 && !trusts[a.first]) 
                return a.first;

        return -1;
    }
};

int main()
{

    return 0;
}