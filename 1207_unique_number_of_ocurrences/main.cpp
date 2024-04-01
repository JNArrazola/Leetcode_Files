#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef long long ll;

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

ll fibonacci(ll n, vector<ll> &dp){
    if(dp[n]!=-1) return dp[n];
    if(n==0||n==1) return 1;

    return dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> dp(n+1, -1);
    cout << fibonacci(n, dp) << endl;

    return 0;
}