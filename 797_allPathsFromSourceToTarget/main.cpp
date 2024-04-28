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
    void dfs(vector<vector<int>> &answ ,vector<int> path, vector<vector<int>> &graph, int node, int objective){
        path.push_back(node);

        if(node == objective){
            answ.push_back(path);
            path.pop_back();
            return;
        }

        for (size_t i = 0; i < graph[node].size(); i++)
            dfs(answ, path, graph, graph[node][i], objective);
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> answ;
        dfs(answ, {}, graph, 0, graph.size() - 1);
        return answ;
    }
};

int main()
{

    return 0;
}