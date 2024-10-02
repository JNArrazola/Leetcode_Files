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
#include <deque>
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

class CustomStack {
private:
    int k;  
    vector<int> st;

public:
    CustomStack(int maxSize) {
        this->k = maxSize;
    }
    
    void push(int x) {
        if(k > st.size())
            st.push_back(x);
    }
    
    int pop() {
        if(st.empty())
            return -1;
        int num = st[st.size() - 1];
        st.pop_back();
        return num;
    }
    
    void increment(int obj, int val) {
        for (size_t i = 0; i < obj && i < st.size(); i++)
            st[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main()
{

    return 0;
}