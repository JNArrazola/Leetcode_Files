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
    string reverseWords(string s) {
        vector<string> words;
        string word = "";

        for (size_t i = 0; i < s.size(); i++){
            if(s[i]!=' ') {
                word+=s[i];
            } else if((s[i]==' '&&!word.empty())||i==s.size()){
                words.push_back(word);
                word = "";
            }
        }
        for(const string &s : words)
            cout << s << endl;
        return "";
    }
};

int main()
{
    Solution s;

    s.reverseWords("the sky is blue");
    return 0;
}