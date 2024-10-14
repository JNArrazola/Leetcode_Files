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
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size(), i = 0, j = n - 1;
        long long lastSum, answ = 0;
        sort(skill.begin(), skill.end());

        lastSum = skill[i] + skill[j];
        answ+=(skill[i++]*skill[j--]);

        while (i < j)
            if(skill[i] + skill[j] == lastSum)
                answ+=(skill[i++]*skill[j--]);
            else 
                return -1;

        return answ;
    }
};

int main()
{

    return 0;
}