#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int answ = 0;

        while (n>0){}
        {
            int games = n/2;
            answ+=games;
            n-=games;
        }
        

        return answ;
    }
};

int main()
{
    Solution s;

    s.numberOfMatches(7);

    return 0;
}