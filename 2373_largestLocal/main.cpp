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
    int pickLargest(vector<vector<int>> &grid, int i, int j){
        int answ = INT32_MIN;

        answ = max(answ, grid[i - 1][j - 1]);
        answ = max(answ, grid[i - 1][j]);
        answ = max(answ, grid[i - 1][j + 1]);
        answ = max(answ, grid[i][j + 1]);
        answ = max(answ, grid[i + 1][j + 1]);
        answ = max(answ, grid[i + 1][j]);
        answ = max(answ, grid[i - 1][j + 1]);
        answ = max(answ, grid[i][j - 1]);
        answ = max(answ, grid[i + 1][j - 1]);
        answ = max(answ, grid[i][j]);
        return answ;
    }
    
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> res(grid.size() - 2, vector<int>(grid.size() - 2, INT32_MIN));

        for (size_t i = 1; i < grid.size() - 1; i++)
            for (size_t j = 1; j < grid.size() - 1; j++)
                res[i-1][j-1] = pickLargest(grid, i, j);
        
        return res;
    }
};

int main()
{

    return 0;
}