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
    void changeDirection(int &i, int &j){
        if(i == -1 && j == 1){
            i = 1;
            j = -1;
        } else {
            i = -1;
            j = 1;
        }
    }
    
    bool isInBoard(int &x, int &y, vector<vector<int>>& mat){
        return x>=0&&y>=0&&x < mat.size()&& y < mat[0].size();
    }

public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> answ;
        bool foundNumber = false;   
        int dirX = -1, dirY = 1, posX = 0, posY = 0, numberOfItems = mat.size() * mat[0].size();

        while (answ.size() != numberOfItems)
        {
            if(!isInBoard(posX, posY, mat)){
                if(!foundNumber){
                    posX+=dirX;
                    posY+=dirY;
                }

                
                if(foundNumber){
                    changeDirection(dirX, dirY);
                    foundNumber = false;
                }
                continue;
            }
            foundNumber = true;
            answ.push_back(mat[posX][posY]);
            posX+=dirX;
            posY+=dirY;
        }
        
        return answ;
    }
};

int main()
{
    vector<vector<int>> vt = {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution s;

    vector<int> answ = s.findDiagonalOrder(vt);

    for(const int &i : answ)
        cout << i << endl;

    return 0;
}