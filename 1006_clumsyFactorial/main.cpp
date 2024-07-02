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


// '*', divide '/', add '+', and subtract '-' in this order
class Solution {
private:
    int calculateClumsy(int n, char prevOp){
        if(!n){
            switch (prevOp)
            {
            case '*':
            case '/':
                return 1;
                break;
            case '+':
            case '-':
                return 0;
                break;
            default:
                break;
            }
        }

        switch (prevOp)
        {
        case '*':
            return floor(n/calculateClumsy(--n,'/'));
        case '/':
            return n + calculateClumsy(--n, '+');
        case '+':
            return n - calculateClumsy(--n, '-');
        case '-':
            return n * calculateClumsy(--n, '*');
        default:
            break;
        }
        return 0;
    }
    
public:
    int clumsy(int n) {
        return n * calculateClumsy(--n, '*');
    }
};

int main()
{

    return 0;
}