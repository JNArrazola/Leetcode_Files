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
    int canSum(int x, int y, vector<vector<int>>& grid){
        if(y < 0 || y == n)
            return 1e6;

        return grid[x][y];
    }
    


public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        this->n = grid.size();

        if(n == 1)
            return grid[0][0];

        for (size_t i = 0; i < n; i++)
            for (size_t j = 1; j < n; j++)
                for (size_t k = i; k < n; k++)
                    grid[j][k] = grid[j][k] + min(canSum(j - 1, k, grid), canSum(j-1, k+1, grid));
        

        int answ = INT32_MAX;

        for (size_t i = 0; i < n; i++)
            answ = min(answ, grid[n - 1][i]);
        
        return answ;
    }
};

int main()
{

    return 0;
}