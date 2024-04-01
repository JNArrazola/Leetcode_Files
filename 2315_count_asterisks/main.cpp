#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int flag = 0, answ = 0;
        

        for (size_t i = 0; i < s.size(); i++)
        {
            if(s[i]=='|'&&!flag) flag = 1;
            else if(s[i]=='|'&&flag) flag = 0;
            
            if(!flag&&s[i]=='*') answ++;
        }
        
        return answ;
    }
};

int main()
{
    


    return 0;
}