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
    int solve(const int &n, const bool &pickFirst, int idx, const vector<int> &slices, vector<vector<vector<int>>> &dp, int ctr){
        if(idx >= n || ctr == n/3)
            return 0;

        if(idx == n - 1)
            return pickFirst ? 0 : slices[idx];

        if(dp[pickFirst][ctr][idx] != -1)
            return dp[pickFirst][ctr][idx];

        return dp[pickFirst][ctr][idx] = max(solve(n, pickFirst, idx + 1, slices, dp, ctr), slices[idx] + solve(n, pickFirst, idx + 2, slices, dp, ctr + 1));
    }
    
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n/3 + 1, vector<int>(n, -1)));

        return max(solve(n, true, 0, slices, dp, 0), solve(n, false, 1, slices, dp, 0));
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}