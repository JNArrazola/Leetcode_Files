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
#include <deque>
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
    vector<int> nums;
    int n;
    void tree(int num){
        if(num > n)
            return;

        nums.push_back(num);

        for (size_t i = 0; i < 10; i++)
            tree(num*10 + i);
    }
    
public:
    vector<int> lexicalOrder(int n) {
        this->n = n;

        for (size_t i = 1; i < 10; i++)
            tree(i);
        
        return nums;
    }
};

int main()
{

    return 0;
}