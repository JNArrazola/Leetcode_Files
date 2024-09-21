#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    string reverse(string s){
        for (size_t i = 0; i < s.size()/2; i++)
            swap(s[i], s[s.size() - 1 - i]);
        return s;
    }  
public:
    string reverseWords(string s) {
        int ptrOne = 0, ptrTwo = 0;
        string answ = "";

        for (size_t i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ' || i == s.size() - 1){
                if(i == s.size() - 1)
                    ptrTwo++;
                
                answ+=reverse(s.substr(ptrOne, ptrTwo - ptrOne));

                if(i != s.size() - 1)
                    answ+=" ";

                ptrOne = i + 1;
                ptrTwo = i + 1;
            } else 
                ptrTwo++;
        }
    
        return answ;
    }
};

int main()
{
    


    return 0;
}