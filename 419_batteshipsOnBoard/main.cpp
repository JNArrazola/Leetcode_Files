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
    bool isInMatrix(vector<vector<char>> &board, int posX, int posY){
        return (posX >= 0&&posY >= 0&&posX < board.size()&&posY < board[0].size());
    }
    
    void mitigateAdjacentCells(vector<vector<char>> &board, int posX, int posY, int dirX, int dirY){
        if(!isInMatrix(board, posX, posY))
            return;
        if(board[posX][posY]!='X')
            return;

        board[posX][posY] = 'O';

        mitigateAdjacentCells(board, posX + dirX, posY + dirY, dirX, dirY);
    }

    void lookForDirection(vector<vector<char>> &board, int posX, int posY){
        board[posX][posY] = 'O';

        if(isInMatrix(board, posX, posY + 1)&&board[posX][posY+1]=='X')
            mitigateAdjacentCells(board, posX, posY + 1, 0, 1);
        else if(isInMatrix(board, posX+1, posY)&&board[posX+1][posY]=='X')
            mitigateAdjacentCells(board, posX + 1, posY, 1, 0);
        return;
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        int answ = 0;

        for (size_t i = 0; i < board.size(); i++)
            for (size_t j = 0; j < board[0].size(); j++)
                if(board[i][j]=='X'){
                    answ++;
                    lookForDirection(board, i, j);
                }   
        return answ;
    }
};

int main()
{

    return 0;
}