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
#include <bits/stdc++.h>

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
    string makeGood(string s) {
        bool changed = false;;

        while (1)
        {
            bool change = false;
            for (size_t i = 0; i < s.length()-1; i++)
            {
                if(i>s.length()) break;
                if((islower(s[i])&&isupper(s[i+1])&&toupper(s[i])==s[i+1])
                ||islower(s[i+1])&&isupper(s[i])&&toupper(s[i+1])==s[i]){
                    s.erase(i,2);
                    i+=2;
                    change = true;
                }
            }
            if(!change)
                break;
        }
        return s;
    }
};

int main()
{
    Solution s;

    cout << s.makeGood("abBAcC") << endl;
    cout << "" << endl;
    return 0;
}