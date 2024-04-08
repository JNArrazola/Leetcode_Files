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
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int answ = 0, odd = INT32_MIN;

        for (size_t i = 0; i < s.size(); i++)
            mp[s[i]]++;
        
        for(const auto & i : mp)
            if(((i.second)%2)) odd = max(odd, i.second);
            else answ+=i.second;

        if(odd!=INT32_MIN) answ+=odd;
        return answ;
    }
};

int main()
{

    return 0;
}