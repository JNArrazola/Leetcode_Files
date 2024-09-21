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
    private: 
    void getSum(vector<int> &v, int &sum, int localSum, int &n, bool &found, unordered_set<int> &visited){
        if(found)
            return;

        if(v.size() >= n){
            if(localSum == sum)
                found = true;
            return;
        }

        for (size_t i = 1; i <= 6; i++)
        {
            int numberToSearch = localSum + i;

            if(visited.find(sum - numberToSearch) != visited.end())
                continue;

            v.push_back(i);
            getSum(v, sum, numberToSearch, n, found, visited);
            visited.insert(sum - numberToSearch);

            if(!found)
                v.pop_back();
            else
                break;
        }
    }

public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;

        for(const int &i : rolls)
            sum+=i;
        
        int sumToGet = mean*(n+rolls.size()) - sum;

        if (sumToGet < n || sumToGet > 6 * n) 
            return {};         
        
        unordered_set<int> visited;
        vector<int> answ;
        bool found = 0;

        cout << n << endl;
        cout << sumToGet << endl;
        getSum(answ, sumToGet, 0, n, found, visited);

        return (found) ? answ : vector<int>{};
    }
};

int main()
{

    return 0;
}