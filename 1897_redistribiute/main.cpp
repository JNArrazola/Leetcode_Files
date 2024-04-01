#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> letters;

        for (size_t i = 0; i < words.size(); i++)
            for (size_t j = 0; j < words[i].size(); j++)
                letters[words[i][j]]++;
        
        for(auto i = letters.begin(); i!=letters.end(); i++)
            if((*i).second%(words.size())) return false;
        return true;
    }
};

int main()
{
    


    return 0;
}