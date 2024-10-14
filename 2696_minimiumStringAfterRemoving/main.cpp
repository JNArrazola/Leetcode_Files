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

/* You can apply some operations to this string where, in one operation, you can remove any occurrence of
one of the substrings "AB" or "CD" from s.

Return the minimum possible length of the resulting string that you can obtain. */

class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (size_t i = 0; i < s.size(); i++)
        {
            if(!st.empty() && s[i] == 'B' && st.top() == 'A'){
                st.pop();
            } else if(!st.empty() && s[i] == 'D' && st.top() == 'C'){
                st.pop();
            } else 
                st.push(s[i]);
        }
        return st.size();
    }
};

int main()
{

    return 0;
}