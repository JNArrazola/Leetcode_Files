#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;


        while (i < s.size())
        {
            if(s[j]==' '){
                for (size_t k = i; k <= j/2; k++)
                    swap(s[k], s[j-k-1]);
                i++;
                j = i;
            } else {
                j++;
            }
        }
        return s;
    }
};

int main()
{
    


    return 0;
}