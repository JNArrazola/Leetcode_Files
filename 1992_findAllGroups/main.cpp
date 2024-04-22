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
    bool isInFarm(vector<vector<int>> &land, int r, int c){
        return r<land.size()&&c<land[0].size();
    }

    void dfs(vector<vector<int>> &land, int r, int c, vector<int> &candidate){
        if(!isInFarm(land, r, c)||land[r][c]!=1) return;

        candidate[2] = max(r, candidate[2]);
        candidate[3] = max(c, candidate[3]);

        land[r][c] = -1;
        
        dfs(land, r + 1, c, candidate);
        dfs(land, r, c + 1, candidate);
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> answ;

        for (size_t i = 0; i < land.size(); i++)
            for (size_t j = 0; j < land[0].size(); j++)
                if(land[i][j]==1){
                    vector<int> candidate(4);

                    candidate[0] = i;
                    candidate[1] = j;
                    candidate[2] = -1000;
                    candidate[3] = -1000;

                    dfs(land, i, j, candidate);
                    answ.push_back(candidate);
                }

        return answ;
    }
};

int main()
{
    vector<vector<int>> land = {{1,1,0,0,0,1}, {1,1,0,0,0,0}};

    Solution s;

    vector<vector<int>> sol = s.findFarmland(land);

    for (size_t i = 0; i < sol.size(); i++)
        {
            for (size_t j = 0; j < sol[0].size(); j++)
                cout << sol[i][j] <<  " ";
            cout << endl;
        }
    return 0;
}