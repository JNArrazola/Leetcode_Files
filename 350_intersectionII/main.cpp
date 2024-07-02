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
private:
    vector<int> findIntersectionArr(vector<int> &minor, vector<int> &major){
        vector<int> answ;
        
        int n_1 = minor.size(), n_2 = major.size();
        int i1 = 0, i2 = 0;

        sort(minor.begin(), minor.end());
        sort(major.begin(), major.end());

        while (i1 < n_1 && i2 < n_2)
        {
            if(minor[i1]==major[i2]){
                answ.push_back(minor[i1]);
                i1++;
                i2++;
            } else if(major[i2] < minor[i1])
                i2++;
            else
                i1++;
        }  

        return answ;
    }

public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        return ((nums1.size() < nums2.size()) ? findIntersectionArr(nums1, nums2) : findIntersectionArr(nums2, nums1));
    }
};

int main()
{

    return 0;
}