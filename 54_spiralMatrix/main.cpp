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
    bool isInBoard(int posX, int posY, vector<vector<int>> &matrix){
        return posX>=0&&posY>=0&&(posX<=matrix.size() - 1)&&(posY<=(matrix[0].size() - 1));
    }
    
    void generateAnsw(vector<vector<int>> &matrix,vector<int> &answ,int posX, int posY, int dirX, int dirY, int counterItr){
        answ.push_back(matrix[posX][posY]);
        matrix[posX][posY] = -100;

        if((counterItr + 1)==(matrix.size()*matrix[0].size()))
            return;
        

        if(isInBoard(posX + dirX, posY + dirY, matrix)&&matrix[posX+dirX][posY+dirY]!=-100){
            generateAnsw(matrix, answ, posX + dirX, posY + dirY, dirX, dirY, counterItr + 1);
        } else {
            int newDirX, newDirY; 
            if(dirX==0&&dirY==1){
                newDirX = 1;
                newDirY = 0;
            } else if(dirX==1&&dirY==0){
                newDirX = 0;
                newDirY = -1;
            } else if(dirX==0&&dirY==-1){
                newDirX = -1;
                newDirY = 0;
            } else if(dirX==-1&&dirY==0){
                newDirX = 0;
                newDirY = 1;
            }
            generateAnsw(matrix, answ, posX + newDirX, posY + newDirY, newDirX, newDirY, counterItr + 1);
        }
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answ;

        generateAnsw(matrix, answ, 0, 0, 0, 1, 0);
        return answ;
    }
};

int main()
{

    return 0;
}