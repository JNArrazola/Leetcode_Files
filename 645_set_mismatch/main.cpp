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
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> answ(2);
 
        for(const int & n : nums) mp[n]++;
        
        for (size_t i = 1; i <= nums.size(); i++)
        {
            if(mp[i]==0) answ[1] = i;
            if(mp[i]==2) answ[0] = i;
        }
        return answ;
    }
};

int main()
{

    return 0;
}