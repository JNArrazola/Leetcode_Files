#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int calculateMax(vector<vector<int>> &nums){
        int maximo = -1;

        for (int i = 0; i < nums.size(); i++) maximo = max(maximo, (int)nums[i].size());

        return maximo;        
    }

    void resizearMatriz(vector<vector<int>> &nums, int maximo){
        for (int i = 0; i < nums.size(); i++) {
            nums[i].resize(maximo);
        }
    }

    void pushear(vector<vector<int>> &nums, vector<int> &p){
        int j, k;
        for (size_t i = 0; i < nums.size(); i++)
        {
            j = i;
            k = i;

            while (j>=0&&k>=0)
            {
                p.push_back(nums[j][k]);
                j--;
                k++;
            }
        }
        for(const int & num : p){
            cout << num << endl;
        }
    }

public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
        vector<int> p;
        int max = calculateMax(nums);
        resizearMatriz(nums, max);
        pushear(nums, p);

        return p;
    }
};

int main()
{
    Solution solucion;
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    
    solucion.findDiagonalOrder(nums);
    return 0;
}
