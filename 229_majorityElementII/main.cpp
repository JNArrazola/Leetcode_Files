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


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = floor(nums.size()/3), fi = 0;
        vector<int> answ;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if(i + 1 == nums.size() || nums[i + 1] != nums[fi]){
                if(i + 1 - fi > n)
                    answ.push_back(nums[fi]);
                
                fi = i+1;
            }
        }
        
        return answ;
    }
};

int main()
{

    return 0;
}