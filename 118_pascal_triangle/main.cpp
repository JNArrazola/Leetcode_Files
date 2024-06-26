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
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle = {{1}};
        if(numRows==1)
            return triangle;
        triangle.push_back({1,1});
        if(numRows==2)  
            return triangle;

        int ctr = 1;
        numRows--;
        while (ctr < numRows)
        {
            vector<int> row;
            row.push_back(1);
            for (size_t i = 0; i < triangle[ctr].size() - 1; i++)
                row.push_back(triangle[ctr][i] + triangle[ctr][i + 1]);
            row.push_back(1);
            triangle.push_back(row);
            ctr++;
        }
        
    return triangle;
    }
};

int main()
{

    return 0;
}