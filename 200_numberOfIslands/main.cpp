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
    bool isInMatrix(vector<vector<char>> &grid, int posX, int posY){
        return posX >= 0&&posY>=0&&posX < grid.size()&&posY < grid[0].size();
    }

    void mitigateAdjacentCells(vector<vector<char>> &grid, int posX, int posY){
        if(!isInMatrix(grid, posX, posY))
            return;
        if(grid[posX][posY]!='1')
            return;
        
        grid[posX][posY] = 'x';

        mitigateAdjacentCells(grid, posX, posY + 1);
        mitigateAdjacentCells(grid, posX, posY - 1);
        mitigateAdjacentCells(grid, posX + 1, posY);
        mitigateAdjacentCells(grid, posX - 1, posY);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int answ = 0;

        for (size_t i = 0; i < grid.size(); i++)
            for (size_t j = 0; j < grid[0].size(); j++)
                if(grid[i][j]=='1'){
                    answ++;
                    mitigateAdjacentCells(grid, i, j);
                }
            
        return answ;
    }
};

int main()
{

    return 0;
}