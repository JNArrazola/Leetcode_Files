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
    bool checkValidString(string s) {
        stack<char> st;
        int counter = 0;

        for (size_t i = 0; i < s.size(); i++)
        {
            if(s[i]=='(') s.push_back(s[i]); else 
            if(!s.empty()&&s[i]==')') s.pop_back(); else
            if(s[i]=='*') counter++;
        }
        
        return st.size() <= counter;
    }
};

int main()
{

    return 0;
}