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
private:
    string generateString(char a, int length){
        string word = "";
        
        for (size_t i = 0; i < length; i++)
            word+=a;
        
        return word;
    }
public:
    string customSortString(string order, string s) {
        string answ = "";
        unordered_map<char, int> hm;

        for(const char & c : s)
            hm[c]++;

        for(const char & c : order){
            if(hm[c]!=0){
                answ+=generateString(c, hm[c]);
                hm[c] = 0;
            }
        }

        for(const char & c : s){
            if(hm[c]!=0){
                answ+=generateString(c, hm[c]);
                hm[c] = 0;
            }
        }

        return answ;
    }
};

int main()
{

    return 0;
}