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
using namespace std;

#define PI (3.141592);
#define e (2.7182);

typedef long long ll;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for (size_t i = 0; i < prices.size() - 1; i++)
        {
            for (size_t j = i + 1; j < prices.size(); j++)
                if(prices[i]>=prices[j]) {
                    prices[i]-=prices[j];
                    break;
                }
        }
        return prices;
    }
};

int main()
{

    return 0;
}