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
    vector<vector<int>> answ;
    void backtracking(int idx, vector<int> &candidate, vector<int> &candidates, int obj){
        if(!obj){
            answ.push_back(candidate);
            return;
        }

        if(obj < 0)
            return;

        for (size_t i = idx; i < candidates.size(); i++)
        {
            if(i > idx && candidates[i] == candidates[i - 1]) continue;

            if(candidates[i] > obj) continue;

            candidate.push_back(candidates[i]);
            backtracking(i + 1, candidate, candidates, obj - candidates[i]);
            candidate.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        backtracking(0, combination, candidates, target);
        return answ;
    }
};

int main()
{

    return 0;
}