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
    int findTheWinner(int n, int k) {
        vector<short> v(n);

        for (short i = 0; i < n; i++)
            v[i] = i;
        
        short index = 0, reps = 1;

        while (v.size() != 1)
        {
            if(reps == k){
                v.erase(v.begin() + index);
                reps = 1;
            } else {
                reps++;
                index++;
            }

            if(index >= v.size())
                index = 0;
        }
        
        return v[0] + 1;
    }
};

int main()
{

    return 0;
}