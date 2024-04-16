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
    vector<string> removeAnagrams(vector<string>& words) {
        
        for (short i = words.size() - 1; i >= 1; i--)
        {
            string wordOne = words[i], wordTwo = words[i-1];
            sort(wordOne.begin(), wordOne.end());
            sort(wordTwo.begin(), wordTwo.end());

            if(wordOne==wordTwo)
                words.erase(words.begin() + i);
        }
        return words;
    }
};

int main()
{

    return 0;
}