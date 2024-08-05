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
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> hm;

        for(const string &i : arr)
            hm[i]++;
        
        short ctr = 0;

        for(const string &i : arr)
            if(hm[i] == 1){
                ++ctr;
                if(ctr == k)
                    return i;
            }

        return "";
    }
};

int main()
{

    return 0;
}