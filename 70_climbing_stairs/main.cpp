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
    int solve(int n, vector<int> &memo){
        if(n<0) return 0;
        if(n==0) return 1;
        if(memo[n]!=-1) return memo[n];
        return memo[n] = solve(n-1, memo) + solve(n-2, memo); 
    }
public:
    int climbStairs(int n) {
        int answ = 0;
        vector<int> memo(n + 1, (-1));
        
        return solve(n, memo);
    }
};

int main()
{   
    Solution s;
    cout << s.climbStairs(3) << endl;
    return 0;
}