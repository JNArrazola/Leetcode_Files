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
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0, answ = -1;
        unordered_map<int, int> mp;


        while (j != nums.size() - 1)
        {
            if(mp[nums[j]] < k){
                mp[nums[j++]]++;
                answ = max(answ, j - i);
            } else if(mp[nums[j]] >= k){
                mp[nums[i++]]--;
            } else 
                i++;
        }        
        return answ;
    }
};

int main()
{

    return 0;
}