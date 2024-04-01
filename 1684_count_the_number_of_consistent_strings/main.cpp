#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        int counter = 0;

        for (size_t i = 0; i < allowed.size(); i++)
            st.insert(allowed[i]);

        for (size_t i = 0; i < words.size(); i++)
        {
            bool flag = 1;
            for (size_t j = 0; j < words[i].size(); j++)
            {
                if(st.find(words[i][j])==st.end()){
                    flag = 0;
                    break;
                }
            }
            if(flag) counter++;
        }
        return counter;
    }
};

int main()
{
    


    return 0;
}