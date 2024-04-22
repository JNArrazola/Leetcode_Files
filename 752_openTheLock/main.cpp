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
#pragma GCC target("avx")

#define PI (3.141592);

typedef long long ll;
typedef long l;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

template <typename R>
using st = stack<R>;

static vector<int> nums = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> deadSet;

        for (const string &i : deadends)
            deadSet.insert(i);

        if (deadSet.find(target) != deadSet.end())
            return -1;
        else if(target == "0000")
            return 0;

        queue<pair<string, int>> ends;
        unordered_set<string> viz;
        ends.push({"0000", 0});
        viz.insert(ends.front().first);

        while (!ends.empty())
        {
            pair<string, int> actualItem = ends.front();
            ends.pop();

            if (deadSet.find(actualItem.first) != deadSet.end())
                continue;

            if (target == actualItem.first)
                return actualItem.second;

            string actualString = actualItem.first;

            for (size_t i = 0; i < target.size(); i++)
            {
                string copyString = actualString;
                copyString[i] = ((copyString[i] == '9') ? '0' : (copyString[i] + 1));

                if (viz.find(copyString) == viz.end())
                {
                    ends.push({copyString, actualItem.second + 1});
                    viz.insert(copyString);
                }
            }

            for (size_t i = 0; i < target.size(); i++)
            {
                string copyString = actualString;
                copyString[i] = ((copyString[i] == '0') ? '9' : (copyString[i] - 1));

                if (viz.find(copyString) == viz.end())
                {
                    ends.push({copyString, actualItem.second + 1});
                    viz.insert(copyString);
                }
            }
        }
        return -1;
    };
};

int main()
{
    Solution s;
    vt<string> v = {"0201", "0101", "0102", "1212", "2002"};

    int sol = s.openLock(v, "0202");
    cout << sol << endl;
    return 0;
}