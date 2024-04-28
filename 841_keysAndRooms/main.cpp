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
    void dfs(unordered_set<int> &visited, int actualRoom, vector<vector<int>> &rooms){
        if(visited.find(actualRoom)!=visited.end())
            return;

        visited.insert(actualRoom);
        for (size_t i = 0; i < rooms[actualRoom].size(); i++)
            dfs(visited, rooms[actualRoom][i], rooms);
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        dfs(visited, 0, rooms);
        return visited.size() == rooms.size();
    }
};

int main()
{

    return 0;
}