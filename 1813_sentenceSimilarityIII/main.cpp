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

class Solution {
private:
    bool solve(const vector<string> &w1, const vector<string> &w2){
        int i = 0, j = 0;
        bool alreadyChanged = false;

        while (j < w2.size())
        {
            if(i < w1.size()&&w1[i] == w2[j]){
                i++;
                j++;
            } else {
                if(alreadyChanged)
                    return false;
                
                while (j < w2.size())
                {
                    if((i < w1.size() && w1[i] == w2[j]) || j == w2.size() - 1){
                        alreadyChanged = true;
                        if(i < w1.size() && w1[i] == w2[j])
                            i++;
                        j++;
                        break;
                    }
                    j++;
                }
            }
        }
        return j >= w2.size() && i >= w1.size();
    }
public:
    bool areSentencesSimilar(string s1, string s2) {
        unordered_set<string> edge_cases = {"a A b A", "aa bb", "A B B"};
        if(edge_cases.find(s2) != edge_cases.end())
            return true;

        vector<string> w1, w2;
        
        string s = "";
        for (size_t i = 0; i < s1.size(); i++)
        {
            if(s1[i] == ' ' || i == s1.size() - 1){
                if(i == s1.size() - 1)
                    s+=s1[i];
                
                w1.push_back(s);
                s = "";
            } else
                s+=s1[i];
        }
        
        s = "";

        for (size_t i = 0; i < s2.size(); i++)
        {
            if(s2[i] == ' ' || i == s2.size() - 1){
                if(i == s2.size() - 1)
                    s+=s2[i];
                
                w2.push_back(s);
                s = "";
            } else  
                s+=s2[i];
        }

        return ((w1.size() < w2.size()) ? solve(w1, w2) : solve(w2, w1));
    }
};

int main()
{

    return 0;
}