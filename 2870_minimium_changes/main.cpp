#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> counter;
        int answ = 0;
        
        for (size_t i = 0; i < nums.size(); i++)
            counter[nums[i]]++;
        
        for(auto num : counter){
            if(num.second%3&&num.second%2) return -1;
            
            if(!(num.second%3)) answ+=(num.second/3);
            if(!(num.second%2)) answ+=(num.second/2);
        }

        return answ;
    }
};

int main()
{
    


    return 0;
}