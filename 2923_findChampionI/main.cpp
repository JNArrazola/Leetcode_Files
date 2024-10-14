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
private:
    int steps(const int &n, int sizeToPaste, int actualVal, bool canPaste, vector<int> &dp){
        if(sizeToPaste > n)
            return 1e6;
        
        if(n == sizeToPaste)
            return 0;

        if(dp[sizeToPaste] != -1)
            return dp[sizeToPaste];

        if(!canPaste)
            return dp[sizeToPaste] = 1 + steps(n, sizeToPaste, actualVal, true, dp);

        return dp[sizeToPaste] = 1 + min(steps(n, sizeToPaste + actualVal * 2, actualVal, canPaste, dp), steps(n, sizeToPaste, sizeToPaste*2, false, dp));
    }
    
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, -1);

        return steps(n, 1, 1,false, dp);
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}