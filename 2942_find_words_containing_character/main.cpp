#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> answ;
        
        for (size_t i = 0; i < words.size(); i++)
        {
            for (size_t j = 0; j < words[i].size(); j++)
            {
                if(words[i][j]==x){
                    answ.push_back(i);
                    break;
                }
            }
        }
        return answ;
    }
};

int main()
{
    Solution s;
    vector<string> p = {"leet","code"};

    s.findWordsContaining(p, 'e');
    return 0;
}