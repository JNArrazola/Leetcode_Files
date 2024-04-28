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
    bool binarySearch(vector<vector<int>> &matrix, int lowerBound, int upperBound, int &target){
        if(lowerBound<=upperBound){
            int middle = lowerBound + (upperBound - lowerBound)/2;
            int row = middle/matrix[0].size(), col = middle%matrix[0].size();;
            
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                return binarySearch(matrix, middle + 1, upperBound, target);
            else 
                return binarySearch(matrix, lowerBound, middle - 1 , target);
        }
        return false;
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return binarySearch(matrix, 0, matrix.size() * matrix[0].size(), target);
    }
};

int main()
{
    vector<vector<int>> mat(4, vector<int>(5));

    int ctr = 0;
    for (size_t i = 0; i < mat.size(); i++)
        for (size_t j = 0; j < mat[0].size(); j++)
            mat[i][j] = ctr++;
    
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[0].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    
    int n = mat.size() * mat[0].size();
    n/=2;
    cout << mat[2][0] << endl;
    // 2 - 0

    cout << n/mat[0].size() << endl;
    cout << n%mat[0].size() << endl;
    
    cout << mat[n/mat[0].size()][n%mat[0].size()] << endl;
    return 0;
}