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
    bool checkRecord(string s) {
        int ctr = 0;
        
        for (size_t i = 0; i < s.size(); i++)
        {
            if(i>2&&s[i]=='L'&&s[i-1]=='L'&&s[i-2]=='L') return false;
            if(s[i]=='A') ctr++;
            if(ctr>=3) return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}