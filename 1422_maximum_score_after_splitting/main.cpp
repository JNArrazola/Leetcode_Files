#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int pivot = 1, answ = 0;

        while (pivot!=s.size()-1)
        {
            int counter = 0;
            for (size_t i = 0; i < s.size(); i++)
            {
                if(i<pivot&&s[i]=='0')
                    counter++;
                else if(i>=pivot&&s[i]=='1')
                    counter++;
            }
            answ = max(answ, counter);
            pivot++;
        }
        
        return answ;
    }
};

int main()
{
    Solution s;

    cout << s.maxScore("1111") << endl;


    return 0;
}