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
    string firstPalindrome(vector<string>& words) {
        for (size_t i = 0; i < words.size(); i++)
        {
            bool flag = 1;
            for (size_t j = 0; j < words[i].size()/2; j++)
                if(words[i][j]!=words[i][words[i].size() - j - 1]) {
                    flag = 0;
                    break;
                }
                if(flag) return words[i];
        }
        return "";
    }
};

int main()
{

    return 0;
}