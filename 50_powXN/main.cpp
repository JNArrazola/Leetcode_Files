#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        } else if(n==1){
            return x;
        }
        
        int flag = 0;
        
        if(n<0){
            n*=-1;
            flag = 1;
        }
        
        double suma = 0;
        for (size_t i = 0; i <= n; i++)
        {
            suma += x*n;
        }

        if(flag){
            return 1/suma;
        } else {
            return suma;
        }
    }
};

int main()
{
    Solution solucion;
    cout << solucion.myPow(2,3) << endl;
    
    return 0;
}
