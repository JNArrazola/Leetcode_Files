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
    vector<pair<int, int>> dir = {{-1, 0},{0, 1},{1,0},{0, -1}};

    bool isInBoard(vector<vector<char>> &board, short row, short col){
        return row>=0&&col>=0&&row<board.size()&&col<board[0].size();
    }
    
    bool lookForWord(vector<vector<char>> &board, short row, short col, short index, short &indexWord, string &answ){
        if(index == indexWord)
            return true;
        if(!isInBoard(board, row, col)||board[row][col]!= answ[index])
            return false;

        char temp = board[row][col];
        board[row][col] = '0';

        for (size_t i = 0; i < dir.size(); i++)
            if(lookForWord(board, row + dir[i].first, col + dir[i].second, index + 1, indexWord, answ))
                return true;
        board[row][col] = temp;
        return false;
    }

    
public:
    bool exist(vector<vector<char>>& board, string word) {
        short s = word.size();
        
        for (size_t i = 0; i < board.size(); i++)
            for (size_t j = 0; j < board[0].size(); j++)
                if(board[i][j] == word[0])
                    if(lookForWord(board, i, j, 0, s, word))
                        return true;
        return false;
    }
};

int main()
{
    string a = "Joshua";

    cout << a.size() << endl;

    return 0;
}