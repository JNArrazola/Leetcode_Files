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
    void sieveOfErathostenes(vector<bool> &isPrime){
        int n = isPrime.size();
        
        isPrime[0] = false;
        isPrime[1] = false;
        for (size_t i = 2; i*i < n; i++)
            for (size_t j = i*i; j < n; j+=i)
                isPrime[j] = false;
    }
    
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        sieveOfErathostenes(isPrime);

        vector<int> answ = {-1, -1}, container = {-1, -1};
        int oldResult = INT32_MAX;
        for (size_t i = left; i <= right; i++)
        {
            if(!isPrime[i]) continue;

            if(isPrime[i]&&container[0] == -1)
                container[0] = i;
            
            else if(isPrime[i]&&container[1] == -1)
                container[1] = i;

            if(container[0] == - 1||container[1]==-1)
                continue;

            int subs = container[1] - container[0];
            if(subs<=0) continue;

            if(subs<=2)
                return container;
            else if(subs < oldResult){
                answ[0] = container[0];
                answ[1] = container[1];
                oldResult = subs;
            }

            container[0] = container[1];
            container[1] = i;
        }
        return answ;
    }
};

int main()
{
    Solution s;

    vector<int> answ = s.closestPrimes(10, 100);


    return 0;
}