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
    bool isInBoard(vector<vector<int>>& grid, int &n, int &m){
        return n>=0 && m>=0 && n < grid.size() && m < grid[0].size();
    }

    void dfs(vector<vector<int>>& grid, int n, int m, int &sum){
        if(!isInBoard(grid, n, m) || grid[n][m] == 0)
            return;
        sum+=grid[n][m];
        grid[n][m] = 0;
        
        
        dfs(grid, n + 1, m, sum);
        dfs(grid, n - 1, m, sum);
        dfs(grid, n, m + 1, sum);
        dfs(grid, n, m - 1, sum);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;

        for (size_t i = 0; i < grid.size(); i++)
            for (size_t j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(grid, i, j, area);
                    max_area = max(area, max_area);
                }
        
        return max_area;
    }
};

int main()
{

    return 0;
}