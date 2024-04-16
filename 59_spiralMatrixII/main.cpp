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
    bool isInBoard(vector<vector<int>> &matrix, int posRow, int posColumn){
        return posRow>=0&&posColumn>=0&&posRow < matrix.size()&&posColumn < matrix[0].size();
    }

    void fillMatrix(vector<vector<int>> &matrix, int counter, int posRow, int posColumn, int dirRow, int dirColumn){
        if(!isInBoard(matrix, posRow, posColumn)||
        matrix[posRow][posColumn]!=-1)
            return;
        
        matrix[posRow][posColumn] = counter++;
        if(isInBoard(matrix, posRow + dirRow, posColumn + dirColumn)&&matrix[posRow + dirRow][posColumn + dirColumn]==-1)
            fillMatrix(matrix, counter, posRow + dirRow, posColumn + dirColumn, dirRow, dirColumn);
        else {
            if(dirRow==0&&dirColumn==1){
                dirRow = 1;
                dirColumn = 0; 
            } else if(dirRow == 1&&dirColumn == 0){
                dirRow = 0;
                dirColumn = -1;
            } else if(dirRow == 0&&dirColumn == -1){
                dirRow = -1;
                dirColumn = 0;
            } else if(dirRow == -1&&dirColumn == 0){
                dirRow = 0;
                dirColumn = 1;
            }
            fillMatrix(matrix, counter, posRow + dirRow, posColumn + dirColumn, dirRow, dirColumn);
        }

        return;
    }

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        fillMatrix(matrix, 1, 0, 0, 0, 1);
        
        return matrix;
    }
};

int main()
{
    Solution s;

    s.generateMatrix(3);
    return 0;
}