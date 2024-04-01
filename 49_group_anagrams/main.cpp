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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> answ;
        int ct = 0;
        
        for(const string &s : strs){
            string copy_s = s;
            sort(copy_s.begin(),copy_s.end());
    
            if(mp.find(copy_s)==mp.end()){
                mp[copy_s] = ct++;
                answ.push_back({s});
            } else {
                answ[mp[copy_s]].push_back(s);
            }
        }
        return answ;
    }
};

int main()
{

    return 0;
}