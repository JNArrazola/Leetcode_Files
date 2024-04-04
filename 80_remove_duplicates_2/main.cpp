#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;

        for(const int &number : nums){
            if(i==0||i==1||nums[i-2]!=number){
                nums[i++] = number;
            }
        }
        
        return i;
    }
};

int main()
{
    Solution solucion;

    vector<int> numeros = {1,1,1,2,2,3};

    cout << solucion.removeDuplicates(numeros) << endl;
    
    return 0;
}
