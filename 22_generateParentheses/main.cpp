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
    void backtracking(vector<string> &answ, string candidate, short open, short close, int n){
        if(candidate.length() == n*2){
            answ.push_back(candidate);
            return;
        }
        
        if(open < n) backtracking(answ, candidate + "(", open + 1, close, n);
        if(close < open) backtracking(answ, candidate + ")", open, close + 1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answ;
        backtracking(answ, "", 0, 0, n);
        return answ;
    }
};

int main()
{

    return 0;
}