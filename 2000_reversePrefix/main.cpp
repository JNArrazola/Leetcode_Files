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

#pragma GCC optimize("03")
#pragma GCC target ("avx")

#define PI (3.141592);

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
    string reverse(string &w, short &index){
        for (size_t i = 0; i <= index/2; i++)
            swap(w[i], w[index - i]);
        return w;
    }
    
public:
    string reversePrefix(string word, char ch) {
        for (short i = 0; i < word.size(); i++)
            if(word[i]==ch) 
                return reverse(word, i);
        return word;
    }
};

int main()
{

    return 0;
}