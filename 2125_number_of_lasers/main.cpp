#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int answ = 0;

        int counter = 0, prev = 0;
        for (int i = 0; i < bank.size(); i++){
            for (int j = 0; j < bank[i].size(); j++)
                if(bank[i][j]=='1') counter++;
            
            if(prev) answ+=(prev*counter);

            if(counter!=0){
                prev = counter;
                counter = 0;
            }
        }
        

        return answ;
    }
};

unsigned short main()
{
    


    return 0;
}