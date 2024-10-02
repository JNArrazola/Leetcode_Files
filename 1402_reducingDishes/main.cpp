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
    int solve(int idx, int pick, int ctr, vector<int>& satisfaction, vector<vector<int>>& dp){
        if(idx == satisfaction.size())
            return 0;

        if(dp[pick][idx] != -1)
            return dp[pick][idx];
        
        if(pick)    
            return dp[pick][idx] = max(satisfaction[idx] * ctr + solve(idx + 1, pick, ctr + 1, satisfaction, dp), 0);
        
        return dp[pick][idx] = max(satisfaction[idx] * ctr + solve(idx + 1, 1, ctr+1, satisfaction, dp), max(solve(idx + 1, 0, ctr, satisfaction, dp), 0));
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(2, vector<int>(satisfaction.size(), -1));

        return solve(0, 0, 0, satisfaction, dp);
    }
};

int main()
{

    return 0;
}