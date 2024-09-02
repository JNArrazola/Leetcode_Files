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
    int differenceOfSum(vector<int>& nums) {
        int digitSum = 0, elementSum = 0;

        for(const int & i : nums){
            int temp = i;

            while (temp >= 10)
            {
                digitSum+=temp%10;
                temp/=10;
            }
            digitSum+=temp;
            
            elementSum+=i;
        }
        
        return abs(elementSum - digitSum);
    }
};

int main()
{

    return 0;
}