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
    int solve(int amount, const vector<int> &coins, vector<int> &dp){
        if(!amount)
            return 0;

        if(dp[amount] != -1)
            return dp[amount];

        int answ = 1e6;
        for (size_t i = 0; i < coins.size(); i++)
            if(amount - coins[i] >= 0)
                answ = min(answ, 1 + solve(amount - coins[i], coins, dp));
        return dp[amount] = answ;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int answ = solve(amount, coins, dp);
        return answ >= 1e6 ? -1 : answ;
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}