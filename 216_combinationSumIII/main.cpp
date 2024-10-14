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
    int k;
    
    void solve(int target, int idx, vector<int> &candidate, vector<vector<int>> &answ){
        if(candidate.size() == k){
            if(!target)
                answ.push_back(candidate);
            return;
        }

        for (size_t i = idx; i <= 9; i++)
        {
            if(target - i < 0) continue;
            candidate.push_back(i);
            solve(target - i, i + 1, candidate, answ);
            candidate.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if((k*(k+1))/2 > n)
            return {};
        
        
        this->k = k;
        vector<int> candidate;
        vector<vector<int>> answ;

        solve(n, 1, candidate, answ);
        return answ;
    }
};

int main()
{

    return 0;
}