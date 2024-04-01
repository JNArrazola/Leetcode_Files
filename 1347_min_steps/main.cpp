#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int answ = 0;
        unordered_map<int, int> charS;
        for (size_t i = 0; i < s.size(); i++)
        {
            charS[s[i]]++;
            charS[s[i]]--;
        }
        
        for(auto c : charS){
            if(c.second>0) answ+=c.second;
        }
        return answ;
    }
};

int main()
{
    Solution s;
    s.minSteps("practice", "leetcode");


    return 0;
}