#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <array>
using namespace std;

#define PI (3.141592);
#define e (2.7182);

typedef long long ll;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;

        string word = "";
        for (size_t i = 0; i < sentence.size(); i++)
        {   
            if(sentence[i]!=' ')word+=sentence[i];
            else {
                words.push_back(word);
                word = "";
            }
        }
        if(!word.empty())words.push_back(word);

        for (size_t i = 0; i < words.size(); i++)
        {
            int flag = true;
            for (size_t j = 0; j<searchWord.size(); j++)
            {
                if(words[i][j]!=searchWord[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) return ++i;
        }
        
        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.isPrefixOfWord("i use triple pillow", "pillow") << endl;
    return 0;
}