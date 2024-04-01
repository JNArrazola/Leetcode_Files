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

#define PI (3.141592);
#define e (2.7182);

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
    int countPrimes(int n) {
        int numbers[n + 1];
        memset(numbers, 1, (n + 1)*sizeof(int));

        for (size_t i = 2; i*i < n; i++)
            for (size_t j = i*i; j < n; j+=i)
                numbers[j] = 0; 
        
        int ctr = 0;
        
        for (size_t i = 2; i < n; i++)
            if(numbers[i]) 
                ctr++;
        return ctr;
    }
};

int main()
{
    Solution s;

    cout << s.countPrimes(2e6) << endl;
    return 0;
}