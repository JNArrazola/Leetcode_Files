#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
private:
    unordered_map<int, int> memo;
    int aux(int pos, vector<int> &cost){
        if(pos>=cost.size()) return 0;
        if(memo.find(pos)!=memo.end()) return memo[pos];
        
        int oneStep = cost[pos] + aux(pos+1, cost); 
        int twoStep = cost[pos] + aux(pos+2, cost); 

        int result = min(oneStep, twoStep);
        return memo[pos] = result;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int answ = INT32_MAX;
        int it0 = aux(0, cost);
        int it1 = aux(1, cost);
        return min(it0, it1);
    }
};

int main()
{

    return 0;
}