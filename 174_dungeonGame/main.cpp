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
    int solve(int x, int y, int health, int absoluteMinimium, vector<vector<int>>& dungeon, vector<vector<int>>& dp){
        if(x == dungeon.size() || y == dungeon[0].size())
            return 1e6;
        
        if(dp[x][y] != -1)
            return dp[x][y];

        health+=dungeon[x][y];

        absoluteMinimium = min(absoluteMinimium, abs(health));

        if(x == dungeon.size() - 1 && y == dungeon[0].size() - 1) 
            return dp[x][y] = absoluteMinimium > 0 ? 1e6 : abs(absoluteMinimium);
        
        return dp[x][y] = min(solve(x + 1, y, health, absoluteMinimium, dungeon, dp), solve(x, y+1, health, absoluteMinimium, dungeon, dp));
    }
    
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, 0, INT32_MAX, dungeon, dp);
    }
};

int main()
{

    return 0;
}