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
    void backtracking(vector<int> candidate, vector<vector<int>> &answ, int index, vector<int> &nums){
        if(index == nums.size()){
            answ.push_back(candidate);
            return;
        }

        candidate.push_back(nums[index]);
        backtracking(candidate, answ, index + 1, nums);

        candidate.pop_back();
        backtracking(candidate, answ, index + 1, nums);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answ; 
        backtracking({}, answ, 0, nums);
        return answ;
    }
};

int main()
{

    return 0;
}