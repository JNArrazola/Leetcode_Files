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
    string frequencySort(string s) {
        unordered_map<char, int> val;
        string answ = "";

        for (size_t i = 0; i < s.size(); i++)
            val[s[i]]++;
        
        for(const auto &c : val){
            for (size_t i = 0; i < c.second; i++)
                answ+=c.first;
        }

        return answ;
    }
};

int main()
{

    return 0;
}