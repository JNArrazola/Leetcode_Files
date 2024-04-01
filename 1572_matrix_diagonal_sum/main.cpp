#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int answ = 0, size = mat.size();
        for (size_t i = 0; i < mat.size(); i++) {
    answ += mat[i][i];
    if (i != size - i - 1)
        answ += mat[size - i - 1][i];
}

        
        return answ;
    }
};

int main()
{
    


    return 0;
}