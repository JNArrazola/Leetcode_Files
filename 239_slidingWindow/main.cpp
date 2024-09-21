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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> answ;

        int i = 0,  j = i;

        while (j < k)
        {
            if(dq.empty())
                dq.push_back(nums[j]);
            else if(nums[j] > dq.back()) {
                while (!dq.empty() && nums[j] > dq.back())
                    dq.pop_back();
                dq.push_back(nums[j]); 
            } else 
                dq.push_back(nums[j]);
            j++;
        }
        
        answ.push_back(dq.front());
        while (j < nums.size())
        {
            if(nums[i++] == dq.front())
                dq.pop_front();
            
            if(nums[j] > dq.back()){
                while (!dq.empty() && nums[j] > dq.back())
                    dq.pop_back();
            }
            dq.push_back(nums[j]);

            answ.push_back(dq.front());
            ++j;
        }
        
        return answ;
    }
};

int main()
{

    return 0;
}