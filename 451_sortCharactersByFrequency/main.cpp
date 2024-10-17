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
    unordered_map<char, int>  hm;
public:
    string frequencySort(string s) {
        for(const char &c : s)
            hm[c]++;

        priority_queue<pair<int, char>> pq;

        for(auto &p : hm)
            pq.push({p.second, p.first});

        string answ = "";
        while (!pq.empty())
        {
            auto freq = pq.top();
            answ.append(freq.first, freq.second);
            pq.pop();
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