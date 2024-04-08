#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        int contador = 0;
        while (true)
        {
            if(s[contador]!=t[contador]) {
                return (s.size()>t.size()) ? s[contador] : t[contador];
            }
            contador++;
        }
    }
};

int main()
{
    Solution s;

    cout << s.findTheDifference("abcde","abcd") << endl;


    return 0;
}