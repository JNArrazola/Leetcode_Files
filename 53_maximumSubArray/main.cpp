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
    int solve(vector<int> &nums, int index, bool pick, vector<vector<int>> &dp){
        if(index>=nums.size())
            return pick ? 0 : -1e5;
        
        if(dp[pick][index]!=-1)
            return dp[pick][index];

        if(pick)
            return dp[pick][index] = max(0, nums[index] + solve(nums, index + 1, true, dp));
        
        return dp[pick][index] = max(solve(nums, index + 1, false, dp), nums[index] + solve(nums, index+1, true, dp));
    }
    
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(nums.size(), -1));
        return solve(nums, 0, false, dp);
    }
};

int main()
{

    return 0;
}