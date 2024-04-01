#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int answ = 0, counter = 0;;

        for(const int &i : gain){
            counter+=i;
            answ = max(answ, counter);
        }
        return answ;
    }
};

int main()
{
    


    return 0;
}