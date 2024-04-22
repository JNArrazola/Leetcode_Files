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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> v(n, vector<int>());
        vector<bool> viz(n, false);

        for (size_t i = 0; i < edges.size(); i++)
        {
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        q.push(source);
        viz[source] = true;

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();

            if(vertex == destination)
                return 1;
            
            for (size_t i = 0; i < v[vertex].size(); i++)
            {
                if(!viz[v[vertex][i]]){
                    q.push(v[vertex][i]);
                    viz[v[vertex][i]] = true;
                }
            }
        }
        return 0;
    }
};

int main()
{

    return 0;
}