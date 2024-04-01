#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



class Solution {
private:
    string searchKey(size_t lowerBound, size_t upperBound, vector<vector<string>> &keys, string &key){
        if(!keys.size()) return "?";
        if (lowerBound <= upperBound) {
            size_t middle = lowerBound + (upperBound - lowerBound) / 2;

            if (keys[middle][0] == key) {
                return keys[middle][1];
            } else if (keys[middle][0] > key) {
                return searchKey(lowerBound, middle - 1, keys, key);
            } else {
                return searchKey(middle + 1, upperBound, keys, key);
            }
        }
        return "?";
    }

public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string answ = "";
        sort(knowledge.begin(), knowledge.end());
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                string key;
                i++;
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                answ += searchKey(0, knowledge.size() - 1, knowledge, key);
            } else {
                answ += s[i];
            }
        }
        return answ;
    }
};


int main()
{
    


    return 0;
}