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

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
private:
    void backtrack(vector<vector<int>> &answ, vector<int> permutation, short index){
        if(index == permutation.size()){
            answ.push_back(permutation);
            return;
        }

        for (size_t i = index; i < permutation.size(); i++)
        {
            swap(permutation[index], permutation[i]);
            backtrack(answ, permutation, index + 1);
            swap(permutation[index], permutation[i]);
        }
        
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answ;
        vector<int> permutation = {nums.begin(), nums.end()};
        backtrack(answ, permutation, 0);
        return answ;
    }
};


int main()
{
    Solution s;

    vt<int> v = {1};
    vector<vector<int>> a = s.permute(v);

    return 0;
}