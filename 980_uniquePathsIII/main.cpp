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
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool isInBoard(vector<vector<int>> &grid, int row, int col){
        return row>=0&&col>=0&&row<grid.size()&&col<grid[0].size();
    }

    void dfs(vector<vector<int>> &grid, int row, int col, int ctrNoObstacle, int &ctrEmpty, int &answ){
        if(!isInBoard(grid, row, col)||grid[row][col] == -1)
            return;

        if(grid[row][col] == 2){
            cout << "llegue" << endl;
            cout << ctrNoObstacle << endl;
            cout << ctrEmpty << endl;
            cout << endl;
            if(ctrEmpty - 1 == ctrNoObstacle)
                answ++;
            return;
        }

        int temp = grid[row][col];
        grid[row][col] = -1;
        for(const vector<int> &v : dir)
            dfs(grid, row + v[0], col + v[1], ctrNoObstacle + 1, ctrEmpty, answ);
        
        grid[row][col] = temp;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ctrEmpty = 0, row = 0, col = 0, answ = 0;

        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1){
                    row = i;
                    col = j;
                } else if(grid[i][j] == 0)
                    ++ctrEmpty;
            }
        }
        
        dfs(grid, row, col, 0, ctrEmpty, answ);
        return answ;
    }
};

int main()
{

    return 0;
}