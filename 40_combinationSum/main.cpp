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
    void backtracking(vector<vector<int>> &answ, vector<int> &candidates, int number, vector<int> &possibleAnswer){
        if(number == 0){
            answ.push_back(possibleAnswer);
            return;
        }

        for (size_t i = 0; i < candidates.size(); i++)
            if(candidates[i] != -1 && number - candidates[i] >= 0){
                int temp = candidates[i];
                possibleAnswer.push_back(candidates[i]);
                candidates[i] = -1;
                backtracking(answ, candidates, number - temp, possibleAnswer);
                possibleAnswer.pop_back();
                candidates[i] = temp;
            }
        
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answ;
        vector<int> possibleAnswer;
        sort(candidates.begin(), candidates.end());
        backtracking(answ, candidates, target, possibleAnswer);
        return answ;
    }
};

int main()
{

    return 0;
}