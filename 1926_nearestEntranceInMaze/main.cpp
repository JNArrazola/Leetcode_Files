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
    bool isInBoard(vector<vector<char>>& maze, int &x, int &y){
        return x>=0&&y>=0&&x<maze.size()&&y<maze[0].size();
    }
    
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        maze[entrance[0]][entrance[1]] = '*';
        queue<pair<int, int>> coords;
        coords.push({entrance[0], entrance[1]});
        int itr = 0;

        while (!coords.empty())
        {
            int size = coords.size();

            for (size_t i = 0; i < size; i++)
            {
                pair<int, int> pr = coords.front();

                if(!isInBoard(maze, pr.first + 1, pr.second)&&maze[pr.first+1][pr.second])

            }
            

            itr++;
        }
        

    }
};

int main()
{

    return 0;
}