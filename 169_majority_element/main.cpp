#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, counter = 0;

        for(const int &c : nums){
            if(!counter) candidate = c;

            if(c == candidate) counter++;
            else counter--;
        }

        return candidate;
    }
};

int main()
{
    


    return 0;
}