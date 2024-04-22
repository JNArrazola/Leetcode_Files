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
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> res = {restricted.begin(), restricted.end()};
        if(res.find(0)!=res.end())
            return 0;
        
        vector<vector<int>> adj(n, vector<int>());
        vector<int> viz(n, false); 
        for (size_t i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int answ = 1;
        queue<int> bfs;
        bfs.push(0);
        viz[0] = true;

        while (!bfs.empty())
        {
            int actual = bfs.front();
            bfs.pop();

            for (size_t i = 0; i < adj[actual].size(); i++)
                if(res.find(adj[actual][i]) == res.end() && !viz[adj[actual][i]]){
                    answ++;
                    bfs.push(adj[actual][i]);
                    viz[adj[actual][i]] = true;
                }
        }
        
        return answ;
    }
};

int main()
{
    
    return 0;
}