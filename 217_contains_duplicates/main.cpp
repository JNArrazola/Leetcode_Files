#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> conjunto;

        for(const int& num : nums){
            if(conjunto.find(num)!=conjunto.end()){
                return 1;
            } else {
                conjunto.insert(num);
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4};

    cout << s.containsDuplicate(nums) << endl;

    return 0;
}