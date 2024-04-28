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

class Solution
{
private:
    unordered_map<int, int> mp;

    void backtracking(vector<vector<int>> &answ, int actualSum, vector<int> &candidate, int index, vector<int> &nums)
    {
        if(candidate.size() == 2){

            if(mp[actualSum * (-1)] != 0){
                candidate.push_back(mp[(-1)*actualSum]);
                answ.push_back(candidate);
            }
            return;
        }

        if (index == nums.size())
            return;

        for (size_t i = index; i < nums.size(); i++)
        {
            candidate.push_back(nums[i]);
            mp[nums[i]]--;
            backtracking(answ, actualSum + nums[i], candidate, i + 1, nums);

            if (i < nums.size() - 1 && nums[i + 1] == nums[i])
            {
                while (i < nums.size() - 1 && nums[i + 1] == nums[i]){
                    i++;
                    mp[nums[i]]--;
                }
            }
            candidate.pop_back();
        }
    }

public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> answ;
        vector<int> candidate;
        sort(nums.begin(), nums.end());

        for(const int &i : nums)
            mp[i]++;
        

        backtracking(answ, 0, candidate, 0, nums);
        return answ;
    }
};

int main()
{

    return 0;
}