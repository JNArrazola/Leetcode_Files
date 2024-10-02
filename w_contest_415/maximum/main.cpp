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
private:
    long long solve(vector<int>& a, vector<int>& b, int idx1, int idx2, vector<vector<long long>> &dp){
        if(idx1 == a.size())
            return 0;
        if(idx2 == b.size())
            return -1e6;

        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];


        long long take = (long long)a[idx1]*b[idx2] + (long long)solve(a, b, idx1 + 1, idx2 + 1, dp);
        long long dont_take = (long long)solve(a, b, idx1, idx2+1, dp);

        return dp[idx1][idx2] = max(take, dont_take);
    }
    
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>> dp(5, vector<long long>(b.size(), -1));
        return solve(a, b, 0, 0, dp);
    }
};

int main()
{

    return 0;
}