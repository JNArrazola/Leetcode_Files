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

#define PI (3.141592);
#define e (2.7182);

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
    bool isInBoard(vector<vector<char>> board, int posX, int posY){
        return posX>=0&&posY>=0&&posX <= (board.size() - 1)&&posY <= (board[0].size() - 1);
    }

    bool search(vector<vector<char>> &board, int posX, int posY, int indexOfWord, string word){
         if(indexOfWord==word.size())
                return true;
        
        if(!isInBoard(board, posX, posY))
            return false;

        if(board[posX][posY]==word[indexOfWord++]){
            board[posX][posY] = ' ';

           

            return search(board, posX - 1, posY - 1, indexOfWord, word)||
            search(board, posX - 1, posY, indexOfWord, word)||
            search(board, posX - 1, posY + 1, indexOfWord, word)||
            search(board, posX, posY + 1, indexOfWord, word)||
            search(board, posX + 1, posY + 1, indexOfWord, word)||
            search(board, posX + 1, posY, indexOfWord, word)||
            search(board, posX + 1, posY - 1, indexOfWord, word)||
            search(board, posX, posY - 1, indexOfWord, word);
        }

        return false;
    }

    bool aux(vector<vector<char>> board, int posX, int posY, int indexOfWord, string word){
        return search(board, posX, posY, indexOfWord, word);
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (size_t i = 0; i < board.size(); i++)
            for (size_t j = 0; j < board[0].size(); j++)
                if(board[i][j]==word[0]&&aux(board, i, j, 0, word))
                    return true;

        return false;
    }
};

int main()
{

    return 0;
}