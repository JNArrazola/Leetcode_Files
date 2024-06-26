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

unordered_map<int, int> memo;

int calculateMinimiumCoins(vector<int> &denominations, int amount){
    if(amount == 0)
        return amount;
    if(memo.find(amount)!=memo.end())
        return memo[amount];

    int answ = INT16_MAX;
    for (size_t i = 0; i < denominations.size(); i++)
        if(amount - denominations[i] >= 0)
            answ = min(answ, calculateMinimiumCoins(denominations, amount - denominations[i]) + 1);
    
    return memo[amount] = answ;
}


int main()
{
    vector<int> denominations = {5};
    cout << calculateMinimiumCoins(denominations, 133) << endl;

    return 0;
}