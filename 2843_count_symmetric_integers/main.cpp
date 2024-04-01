#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int answ = 0;

        for (size_t i = low; i <= high; i++)
        {
            string number = to_string(i);
            int cOne = 0, cTwo = 0, size = number.size();

            for (size_t j = 0; j < size; j++) (j < size/2) ? cOne+=(number[j]-'0') : cTwo+=(number[j]-'0');
            
            if(cOne==cTwo) answ++;
        }
            return answ;
    }
};

int main()
{
    


    return 0;
}