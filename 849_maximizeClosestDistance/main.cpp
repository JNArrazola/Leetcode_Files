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
public:
    int maxDistToClosest(vector<int>& seats) {
        cin.tie(nullptr);
        ios_base::sync_with_stdio(false);
        
        int longestDistance = 1, fIdx = 0;

        for (int i = 0; i < seats.size(); i++)
        {
            if(!seats[i]){
                int tempIndex = i, calculatedDistance;

                while (i < seats.size() && !seats[i])
                    i++;
                
                bool f = (!tempIndex || i == seats.size());
                int distance = ((i - tempIndex)/(f ? 1 : 2) + (f ? 0 : (!((i - tempIndex)%2) ? 0 : 1)));
                if(distance > longestDistance)
                    longestDistance = max(distance, longestDistance);
            }
        }
        
        return longestDistance;
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}