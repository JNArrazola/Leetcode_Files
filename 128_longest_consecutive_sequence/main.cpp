#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        } 
        
        sort(nums.begin(),nums.end());

        int counter = 0, maximo = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i]==nums[i-1]) continue;

            if(nums[i]==(nums[i-1]+1)){
                counter++;
            } else {
                maximo = max(counter + 1, maximo);
                counter = 0;
            }
        }
        
        return max(maximo, counter + 1);
    }
};

int main()
{
    Solution solucion;

    vector<int> vector = {100,4,200,1,3,2};

    cout << solucion.longestConsecutive(vector) << endl;
    
    return 0;
}
