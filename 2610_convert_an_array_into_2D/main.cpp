#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> counter;
        vector<vector<int>> answ = {};

        for(const int &num : nums){
            if(counter[num]<answ.size())
                answ[counter[num]].push_back(num);
            else 
                answ.push_back({num});
            
            counter[num]++;
        }
        return answ;
    }
};

int main()
{
    


    return 0;
}