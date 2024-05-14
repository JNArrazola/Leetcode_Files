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
    bool isInBoard(int i, int j, vector<vector<int>>& grid){
        return i >= 0 && j >= 0 &&  i < grid.size() && j < grid[0].size();
    }

    void backTracking(vector<vector<int>>& grid, int value, int i, int j, int &answ){
        if(!isInBoard(i,j,grid)||grid[i][j]==0||grid[i][j]==-1){
            answ = max(answ, value);
            return;
        }
        int temp = grid[i][j];

        value+=grid[i][j];
        grid[i][j] = -1;
        backTracking(grid, value, i+1, j, answ);
        backTracking(grid, value, i-1, j, answ);
        backTracking(grid, value, i, j+1, answ);
        backTracking(grid, value, i, j-1, answ);
        grid[i][j] = temp;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int answ = 0;
        for (size_t i = 0; i < grid.size(); i++)
            for (size_t j = 0; j < grid[0].size(); j++)
                if(grid[i][j]!=0)
                    backTracking(grid, 0, i, j, answ);
        return answ;
    }
};

int main()
{

    return 0;
}