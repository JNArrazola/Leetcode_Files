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
    int sz;

    bool isSafe(vector<string> &board, int &x, int &y){
        short i = x, j = y;

        --i;
        --j;
        while (i >= 0 && j>=0)
            if(board[i--][j--] == 'Q')
                return false;

        i = x, j = y;

        --i;
        ++j;
        while (i >= 0 && j < sz)
            if(board[i--][j++] == 'Q')
                return false;
        
        i = x, j = y;
        --i;
        while (i >= 0)
            if(board[i--][j] == 'Q')
                return false;
        
        return true;
    }
    
    void backtracking(vector<string> &board, vector<vector<string>> &answ, int row){
        if(row == sz){
            answ.push_back(board);
            return;
        }

        for (int i = 0; i < sz; i++)
        {
            if(board[row][i] == '.' && isSafe(board, row, i)){
                board[row][i] = 'Q';
                backtracking(board, answ, row + 1);
                board[row][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        string s = "";
        for (size_t i = 0; i < n; i++)
            s+=".";
        vector<string> board(n, s);
        
        sz = n;

        vector<vector<string>> answ;
        backtracking(board, answ, 0);
        return answ;
    }
};

int main()
{

    return 0;
}