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
    int solve(int i, int j, int lastVal, vector<vector<int>> &dp, vector<vector<int>>& grid){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool flag = lastVal == INT32_MAX;
        if(lastVal == INT32_MAX)
            lastVal = grid[i][j];
        else if(lastVal >= grid[i][j])
            return 0;

        return dp[i][j] = (flag ? 0 : 1) + max(solve(i - 1, j + 1, grid[i][j], dp, grid), max(solve(i, j + 1, grid[i][j], dp, grid), solve(i + 1, j + 1, grid[i][j], dp, grid)));
    }
    
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

        int answ = INT32_MIN;
        for (size_t i = 0; i < grid.size(); i++){
            answ = max(solve(i, 0, INT32_MAX, dp, grid), answ);
        }
        return answ;
    }
};

int main()
{

    return 0;
}