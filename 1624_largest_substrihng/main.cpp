#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> map; 
        int answ = -1;

        for (int i = 0; i < s.size(); i++)
            if(map.find(s[i])==map.end())
                map[s[i]] = i;
            else 
                answ = max(answ, i - map[s[i]] - 1);

        return answ;
    }
};

int main()
{
    


    return 0;
}