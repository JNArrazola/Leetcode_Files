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
#pragma GCC target("avx")

#define PI (3.141592);

typedef long long ll;
typedef long l;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

template <typename R>
using st = stack<R>;

static vector<int> nums = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
private:
    vector<vector<int>> answ;
    unordered_set<string> ids;
    void backtracking(vector<int> &nums, vector<int> &possibleAnsw, int number, int position){
        
        if(possibleAnsw.size() == 3){
            string id = "";
            for(const int & n : possibleAnsw)
                id+=to_string(n);
            
            if(ids.find(id) != ids.end())
                return;
            ids.insert(id);
            if(!number)
                answ.push_back(possibleAnsw);
            return;
        }

        int lastNumber;
        for (size_t i = position; i < nums.size(); i++)
        {
            lastNumber = nums[i];
            possibleAnsw.push_back(nums[i]);
            backtracking(nums, possibleAnsw, number + nums[i], i + 1);
            possibleAnsw.pop_back();
            
            if(lastNumber)
                while (i < nums.size() - 1 && lastNumber == nums[i + 1])
                    i++;
        }
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<int> possibleAnsw = {};
        backtracking(nums, possibleAnsw, 0, 0);
        return answ;
    }
};

int main()
{

    return 0;
}