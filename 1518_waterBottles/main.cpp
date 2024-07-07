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
#pragma GCC target("avx")

#define PI (3.141592);

typedef long long ll;
typedef long l;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

template <typename R>
using st = stack<R>;

static vector<int> nums = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        short answ = 0, filledBottles = numBottles, emptyBottles = 0;

        while (true)
        {
            answ += filledBottles;
            emptyBottles += filledBottles;

            if (emptyBottles / numExchange >= 1)
            {
                filledBottles = emptyBottles / numExchange;
                emptyBottles %= numExchange;
            }
            else
                break;
        }

        return answ;
    }
};

int main()
{

    return 0;
}