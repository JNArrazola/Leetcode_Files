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
    vector<string> stringSequence(string target) {
        vector<string> answ;

        string str = "";
        for(const char &c : target){
            string temp;
            for (int i = 0; i + 'a' <= c; i++)
            {
                temp = str;
                temp+=(i+'a');
                answ.push_back(temp);
            }
            str = temp;
        }
        return answ;
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}