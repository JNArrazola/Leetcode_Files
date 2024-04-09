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
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ctr = 0;

        do
        {
            for (size_t i = 0; i < tickets.size(); i++)
            {
                if(tickets[i]!=0){
                    ctr++;
                    tickets[i]--;
                }

                if(k==i&&!tickets[k]) break;
            }
        } while (tickets[k]!=0);
        
        return ctr;
    }
};

int main()
{

    return 0;
}