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
    int size;

    void solve(int pos, int lastNumber, bool &hl, int ctr, int &answ, vector<int>& rating){
        if(ctr == 3){
            answ++;
            return;
        }

        for (short i = pos; i < size; i++)
        {
            bool eval = (hl) ? lastNumber > rating[i] : lastNumber < rating[i];

            if(eval)
                solve(i + 1, rating[i], hl, ctr + 1, answ, rating);
        }
    }
public:
    int numTeams(vector<int>& rating) {
        int answ = 0;
        size = rating.size();

        for (short i = 0; i < size; i++)
        {
            bool v = true;
            solve(i + 1, rating[i], v, 1, answ, rating);

            v = false;
            solve(i + 1, rating[i], v, 1, answ, rating);
        }
        
        return answ;
    }
};

int main()
{

    return 0;
}