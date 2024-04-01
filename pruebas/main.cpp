#include <iostream>
#include <vector>
using namespace std;

long fibonnacci(long n, vector<long> &dp){
    if(dp[n]!=-1) return dp[n];
    if(n==0) return 0;
    if(n==1) return 1;

    return dp[n] = fibonnacci(n-1, dp) + fibonnacci(n-2, dp);
}

int main()
{
    long n = 100;
    vector<long> dp(n+1, -1);

    cout << fibonnacci(n, dp) << endl;
    return 0;
}