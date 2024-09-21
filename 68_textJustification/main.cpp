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



class Solution {
private:
    bool canWord(vector<string> &s, int &width, int &index, vector<string>& words, int &maxWidth){
        if(width + s.size() + words[index].size() > maxWidth)
            return false;
        
        return true;
    }

    string generateSpace(int length){
        string str = "";
        for (size_t i = 0; i < length; i++)
            str+=" ";
        return str;
    }

    string leftJustify(vector<string> &temp, int &maxWidth){
        string left = "";

        for (size_t i = 0; i < temp.size(); i++)
        {
            left+=temp[i];
            if(i != temp.size() - 1)
                left+=" ";
        }
        
        for (size_t i = left.size(); i < maxWidth; i++)
            left+=" ";
        
        return left;
    }

    string justify(vector<string> &temp, int &maxWidth, int &sz, bool isLast){
        if(isLast)
            return leftJustify(temp, maxWidth);
        
        
        
        if(temp.size() == 1){
            for (size_t i = 0; i < maxWidth - sz; i++)
                temp[0]+=" ";
            
            return temp[0];
        }

        string justifiedString = "";
        

        int spaces = (maxWidth-sz)/(temp.size() - 1);
        int carry = (maxWidth-sz)%(temp.size() - 1);


        for (size_t i = 0; i < temp.size(); i++)
        {
            justifiedString+=temp[i];

            if(i == temp.size() - 1)   
                continue;

            string space;
            if(carry){
                space = generateSpace(spaces + 1);
                carry--;
            } else 
                space = generateSpace(spaces);
            justifiedString+=space;
        }

        return justifiedString;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int currIndex = 0;
        vector<string> answ;
        
        while (currIndex < words.size())
        {
            vector<string> temp;
            int sz = 0;
            
            while (currIndex < words.size() && canWord(temp, sz, currIndex, words, maxWidth))
            {
                temp.push_back(words[currIndex]);
                sz+=words[currIndex].size();
                currIndex++;
            }

            answ.push_back(justify(temp, maxWidth, sz, (currIndex == words.size() ? true : false)));
        }
        
        return answ;
    }
};


int main()
{

    return 0;
}