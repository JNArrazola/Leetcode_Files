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
    int solve(int x, int y, int &ctr, vector<vector<int>>& grid){
        if(x < 0 ||  y < 0 || x == grid.size() || y == grid[0].size() || grid[x][y] == -1)
            return 0;
        
        if(grid[x][y] == 2)
            return (!ctr) ? 1 : 0;
        
        int tmp = grid[x][y];
        grid[x][y] = -1;
        
        ctr--;
        int paths = solve(x-1, y, ctr, grid) + solve(x, y - 1, ctr, grid) + solve(x, y + 1, ctr, grid) + solve(x+1, y, ctr, grid);
        ctr++;
        grid[x][y] = tmp;
        return paths;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int idx = -1, idy = -1, ctr = 0;

        for (size_t i = 0; i < grid.size(); i++)
            for (size_t j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1){
                    idx = i;
                    idy = j;
                    ctr++;
                } else if(!grid[i][j])
                    ctr++;

        return solve(idx, idy, ctr, grid);
    }
};

int main()
{

    return 0;
}