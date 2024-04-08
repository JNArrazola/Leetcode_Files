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
    int countSeniors(vector<string>& details) {
        int answ = 0;
        for (size_t i = 0; i < details.size(); i++)
            if(((details[i][11]-'0')*10 + (details[i][12]-'0'))>60) answ++;
        
        return answ;
    }
};

int main()
{

    return 0;
}