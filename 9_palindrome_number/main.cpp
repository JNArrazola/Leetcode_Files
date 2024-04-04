#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        

        int invertedNumber = 0, number = x;
        while (x!=0)
        {
            invertedNumber = invertedNumber*10+x%10;
            x/=10;
        }

        return invertedNumber == number;
    }
};

int main()
{
    Solution s;

    cout << s.isPalindrome(121) << endl;


    return 0;
}