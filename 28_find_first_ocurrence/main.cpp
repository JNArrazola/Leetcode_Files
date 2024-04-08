#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = needle.size();
        
        
        while (j < haystack.size()){
            string substring = haystack.substr(i,j);
            cout << substring << endl;
            if(substring == needle){
                return i;
            } 
            ++i;
            ++j;
        } 
        
        return -1;
    }
};

int main()
{
    Solution solution;
    int i = solution.strStr("cbbd", "bb");
    std::cout << i << endl; 
    return 0;
}
