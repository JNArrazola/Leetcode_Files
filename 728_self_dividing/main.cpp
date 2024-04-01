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
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> answ;
        
        for (size_t i = left; i <= right; i++)
        {
            int flag = 1;
            string num = to_string(i);
            for (size_t j = 0; j < num.size(); j++)
            {
                if(num[j]=='0'||((i)%(num[j]-'0'))){
                    flag = 0;
                    break;
                } 
            }
            if(flag) answ.push_back(i);
        }
        return answ;
    }
};

int main()
{

    return 0;
}