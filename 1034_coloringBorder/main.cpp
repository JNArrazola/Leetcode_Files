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
    bool isInBoard(vector<vector<int>>& grid, int &row, int &col){
        return row>=0&&col>=0&&row<grid.size()&&col<grid[0].size();
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, pair<int, int> pos, pair<int, int> lastPos, int &number, int &color){
        if(!isInBoard(grid, pos.first, pos.second)||(grid[pos.first][pos.second]!=number && grid[pos.first][pos.second]!=color )){
            grid[lastPos.first][lastPos.second] = color;
            return;
        }

        if(visited[pos.first][pos.second])
            return;
        
        visited[pos.first][pos.second] = true;

        dfs(grid, visited, {pos.first+1, pos.second}, pos, number, color);
        dfs(grid, visited, {pos.first-1, pos.second}, pos, number, color);
        dfs(grid, visited, {pos.first, pos.second+1}, pos, number, color);
        dfs(grid, visited, {pos.first, pos.second-1}, pos, number, color);
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int numberToLookFor = grid[row][col];

        dfs(grid, visited, {row, col}, {row, col}, numberToLookFor, color);
        return grid;
    }
};

int main()
{

    return 0;
}