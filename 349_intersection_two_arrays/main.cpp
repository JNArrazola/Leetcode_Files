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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        unordered_set<int> answ;

        if(nums1.size()>nums2.size()){
            for(const short &i : nums1)
                st.insert(i);
            for(const short &i : nums2)
                if(st.find(i)!=st.end())
                    answ.insert(i);
        } else {
            for(const short &i : nums2)
                st.insert(i);
            for(const short &i : nums1)
                if(st.find(i)!=st.end())
                    answ.insert(i);
        }

        vector<int> answer;

        for(const short &i : answ)
            answer.push_back(i);
        return answer;
    }
};

int main()
{

    return 0;
}