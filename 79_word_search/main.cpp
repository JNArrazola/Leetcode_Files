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
    bool isInBoard(vector<vector<char>> board ,int posX, int posY){
        return posX>=0&&posY>=0&&posX<=(board.size()-1)&&posY<=(board[0].size());
    }

    bool search(vector<vector<char>> board,int posX, int posY, int dirX, int dirY, string word, int index){
        if(index==(word.size()))
            return true;


        if(board[posX][posY]==word[index]){
            if(isInBoard(posX + 1, posY - 1))
        }

        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        return false;
    }
};

int main()
{
    string w = "perro";
    cout << w.size() << endl;

    return 0;
}