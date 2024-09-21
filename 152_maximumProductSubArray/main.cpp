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
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];

        int answ = 0, prod1 = 1, prod2 = 1, n = nums.size();

        for (size_t i = 0; i < n; i++)
        {   
            prod1 *= nums[i];
            prod2 *= nums[n - i -1];

            answ = max(prod1, max(prod2, answ));

            if(!prod1) prod1 = 1;
            if(!prod2) prod2 = 1;
        }
        
        return answ;
    }
};

int main()
{

    return 0;
}