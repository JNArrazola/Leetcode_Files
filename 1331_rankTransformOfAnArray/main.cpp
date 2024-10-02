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
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> cpy = arr;
        unordered_map<int, int> rankings;
        int ctr = 1;

        sort(cpy.begin(), cpy.end());

        for(const int & i : cpy)
            if(rankings.find(i) == rankings.end())
                rankings[i] = ctr++;

        for (size_t i = 0; i < arr.size(); i++)
            arr[i] = rankings[arr[i]];

        return arr;
    }
};

int main()
{

    return 0;
}