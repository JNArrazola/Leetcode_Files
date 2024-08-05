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
    vector<string> summaryRanges(vector<int>& nums) {
        if(!nums.size())
            return {};

        vector<string> answ;

        int startNumber = nums[0], lastNumber = nums[0], lastInsertedNumber = INT32_MIN;
        
        for (size_t i = 1; i < nums.size(); i++)
        {
            if(lastNumber + 1 == nums[i]){
                lastNumber = nums[i];
            } else {
                if(startNumber == lastNumber)
                    answ.push_back(to_string(startNumber));
                else 
                    answ.push_back(to_string(startNumber) + "->" + to_string(lastNumber));
                lastInsertedNumber = lastNumber;
                startNumber = nums[i];
                lastNumber = nums[i];
            }
        }
        if(startNumber != lastInsertedNumber){
            if(startNumber == lastNumber)
                    answ.push_back(to_string(startNumber));
                else 
                    answ.push_back(to_string(startNumber) + "->" + to_string(lastNumber));
        }

        return answ;
    }
};

int main()
{

    return 0;
}