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
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> answ;
        queue<int> positive;
        queue<int> negative;

        for (size_t i = 0; i < nums.size(); i++)
            if(nums[i]>=0) positive.push(nums[i]);
            else negative.push(nums[i]);
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            if(!(i%2)){
                answ.push_back(positive.front());
                positive.pop();
            } else {
                answ.push_back(negative.front());
                negative.pop();
            }
        }
        return answ;
    }
};

int main()
{

    return 0;
}