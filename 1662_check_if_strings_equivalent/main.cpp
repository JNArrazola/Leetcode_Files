#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string wordOne = "";
        string wordTwo = "";

        for(const string& w: word1)
            wordOne+=w;
        
        for(const string& w: word2)
            wordTwo+=w;
        
        return wordOne == wordTwo;
    }
};

int main()
{
    Solution s;

    vector<string> a = {"ab", "c"};
    vector<string> b = {"a", "bc"};

    cout << s.arrayStringsAreEqual(a,b) << endl;

    return 0;
}