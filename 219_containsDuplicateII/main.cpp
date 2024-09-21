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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        
        if(k >= nums.size()){
            for (size_t i = 0; i < nums.size(); i++)
                if(nums[i] == nums[0])
                    return true;
            return false;
        }
        
        int i = 0, j = i + 1;

        while (j <= k)
            if(nums[i] == nums[j++]){
                cout << "es igual en " << --i << " " << --j << endl;
                return true;
            }
        
        while (j < nums.size())
            if(nums[i++] == nums[j++]){
                cout << "es igual en " << --i << " " << --j << endl;
                return true;
            }
        
        return false;
    }
};

int main()
{

    return 0;
}