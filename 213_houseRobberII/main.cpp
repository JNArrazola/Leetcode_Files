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
    int n;
    int solve(vector<int>& nums, int index, vector<vector<int>>& dp, bool tookFirst){
        if(index>=n)
            return 0;

        if(index == n - 1)
            return dp[index][tookFirst] = (tookFirst) ? 0 : nums[index];
        
        if(dp[index][(tookFirst) ? 1 : 0] != -1)
            return dp[index][tookFirst];

        return dp[index][tookFirst] = max(nums[index] + solve(nums, index + 2, dp, tookFirst), solve(nums, index + 1, dp, tookFirst));
    }
    
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return max(solve(nums, 1, dp, false), nums[0] + solve(nums, 2, dp, true));
    }
};

int main()
{

    return 0;
}