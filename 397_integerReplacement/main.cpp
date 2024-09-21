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
private:
    unordered_map<long, long> memo;
    int solve(long n){
        if(memo.find(n) != memo.end())
            return memo[n];

        if(n == 1)
            return 0;

        if(!(n%2))
            return memo[n] = 1 + solve(n/2);
        
        return memo[n] = min(1 + solve(n-1), 1+solve(n+1));
    }
public:
    int integerReplacement(int n) {
        return solve(n);
    }
};

int main()
{

    return 0;
}