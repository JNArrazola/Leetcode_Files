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

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();


class Solution {
private:
    int sum(int x, int y, vector<vector<int>>& matrix){
        if(y < 0 || y == matrix[0].size())
            return 1e6;

        return matrix[x][y];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        if(n == 1)
            return matrix[0][0];

        for (size_t i = 1; i < n; i++)
            for (size_t j = 0; j < n; j++)
                if(!j)
                    matrix[i][j] =  matrix[i][j] + min(sum(i-1, j, matrix), sum(i-1, j+1, matrix));
                else if(j == n - 1)
                    matrix[i][j] = matrix[i][j] + min(sum(i-1, j-1, matrix), sum(i-1, j, matrix)); 
                else 
                    matrix[i][j] = matrix[i][j] + min(sum(i-1, j-1, matrix), min(sum(i-1, j, matrix), sum(i-1, j+1, matrix)));
        int answ = INT32_MAX;

        for (size_t i = 0; i < n; i++)
            answ = min(answ, matrix[n - 1][i]);

        return answ;
    }   
};

int main()
{

    return 0;
}