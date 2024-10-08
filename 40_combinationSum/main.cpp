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
    vector<vector<int>> answ;
    void backtracking(int target, vector<int>& comb, vector<int> &candidates, int start){
        if(!target){
            answ.push_back(comb);
            return;
        }

        for (size_t i = start; i < candidates.size(); i++)
        {
            if(candidates[i] > target) continue;
            comb.push_back(candidates[i]);
            backtracking(target - candidates[i], comb, candidates, i);
            comb.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        backtracking(target, comb, candidates, 0);
        return answ;
    }
};

int main()
{

    return 0;
}