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
using hm = unordered_map<J, A>;z

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0, d = 0, l = 0, r = 0;

        for(const char & c : moves){
            switch (c)
            {
            case 'U':
                u++;
                break;
            case 'D':
                d++;
                break;
            case 'L':
                l++;
                break;
            case 'R':
                r++;
                break;
            default:
                break;
            }
        }

        return u == d && l == r;
    }
};

int main()
{

    return 0;
}