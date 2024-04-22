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
    int solve(vector<int> &coins, int amount, vector<int>& dp){
        if(amount == 0)
            return 0;
        if(dp[amount]!=INT32_MAX)
            return dp[amount];
        
        int answ = INT32_MAX;
        for (size_t i = 0; i < coins.size(); i++)
        {
            if(amount - coins[i] < 0) break;
            dp[amount] = min(dp[amount], dp[amount - coins[i] + 1]);
        }
        
        

    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT32_MAX); 
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        int answ = solve(coins, amount, dp);
        
        return ((answ!=INT32_MAX) ? answ : -1);
    }
};

int main()
{
    Solution s;

    vector<int> v = {1,2,3};
    s.coinChange(v, 100);

    return 0;
}