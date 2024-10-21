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
    bool found = false;

    bool solve(int index, vector<int> &arr){
        if(index < 0 || index >= arr.size())
            return false;
        
        if(found) return true;

        if(arr[index] == -1)
            return false;
        
        if(!arr[index]){
            found = true;
            return true;
        }

        int val = arr[index];
        arr[index] = -1;
        return solve(index + val, arr) || solve(index - val, arr);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        return solve(start, arr);
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}