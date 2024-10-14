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


class Solution {
private:  
    vector<vector<char>> board;
    bool validateWin(int ctr, const pair<int, int> coords , const pair<int,int> dir, char obj){
        if(coords.first < 0 || coords.first == 3 || coords.second < 0 || coords.second == 3)
            return false;
        
        if(board[coords.first][coords.second] != obj)
            return false;
        ctr++;

        if(ctr == 3)
            return 1;  

        return validateWin(ctr, {coords.first + dir.first, coords.second + dir.second}, {dir.first, dir.second}, obj);
    }
    
    bool checkWins(char obj){
        // Diagonals
        if(board[0][0] == obj)
            if(validateWin(0, {0,0}, {1,1}, obj))
                return true;

        if(board[0][2] == obj)
            if(validateWin(0, {0,2}, {1, -1}, obj))
                return true;

        // horizontal
        for (size_t i = 0; i < 3; i++)
            if(board[i][0] == obj)
                if(validateWin(0, {i, 0}, {0, 1}, obj))
                    return true;

        // vertical
        for (size_t i = 0; i < 3; i++)
            if(board[0][i] == obj)
                if(validateWin(0, {0, i}, {1, 0}, obj))
                    return true;

        return false;
    }

    void printBoard(){
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

public:
    
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, '.'));
        this->board = board;
        
        bool turnX = true;
        int ctrMove = 0;

        while (ctrMove < moves.size())
        {
            if(turnX)
                this->board[moves[ctrMove][0]][moves[ctrMove][1]] = 'X';
            else 
                this->board[moves[ctrMove][0]][moves[ctrMove][1]] = 'O';

            if(checkWins((turnX ? 'X' : 'O')))
                return ((turnX ? "A" : "B"));

            turnX = !turnX;
            ctrMove++;
        }
        
        return ctrMove == 9 ? "Draw" : "Pending";
    }
};

int main()
{

    return 0;
}