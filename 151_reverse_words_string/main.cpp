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
#include <set>
#include <math.h>
#include <iomanip>
#include <bitset>
using namespace std;

#define PI (3.141592);
#define e (2.7182);

typedef long long ll;
typedef long l;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

template <typename R>
using st = stack<R>;

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
public:
    string reverseWords(string s) {
        string answ = "";
        vector<string> words;

        string localStr = "";
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]!=' '){
                localStr+=s[i];
            } else if(localStr.size()!=0){
                words.push_back(localStr);
                localStr = "";
            }
        }
        if(localStr!="") words.push_back(localStr);

        for (int i = words.size() - 1; i >= 0; i--){
            for (int j = 0; j < words[i].size(); j++)
                answ+=words[i][j];
            if(i!=0) answ+=" ";
        }
        return answ;
    }
};

int main()
{

    return 0;
}