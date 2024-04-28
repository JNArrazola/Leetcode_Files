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
    string transformateVectorToKey(vector<int> &permutation){
        string s = "";
        
        for(const int & i : permutation)
            s+=to_string(i);
        return s;
    }

    void backtracking(vector<vector<int>> &answ, vector<int> &nums, vector<int> permutation, unordered_set<string> &perms){
        if(permutation.size() == nums.size()){
            string key = transformateVectorToKey(permutation);
            
            if(perms.find(key) == perms.end()){
                answ.push_back(permutation);
                perms.insert(key);
            }
            else 
                permutation.clear();
            return;
        }

        for (size_t i = 0; i < nums.size(); i++)
            if(nums[i] != -11){
                short temp = nums[i];
                permutation.push_back(nums[i]);
                nums[i] = -11;
                backtracking(answ, nums, permutation, perms);
                nums[i] = temp;
                permutation.pop_back();
            }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> answ;
        unordered_set<string> keys;
        backtracking(answ, nums, {}, keys);
        return answ;
    }
};

int main()
{

    return 0;
}