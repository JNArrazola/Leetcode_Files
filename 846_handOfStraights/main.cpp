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
    int binarySearch(vector<int> &numbers, int number, int lowerBound, int upperBound){
        if(lowerBound<=upperBound){
            int middle = lowerBound + (upperBound - lowerBound)/2;
            
            if(numbers[middle]==number)
                return middle;
            else if(numbers[middle] > number)
                return binarySearch(numbers, number, lowerBound, middle - 1);
            else  
                return binarySearch(numbers, number, middle + 1, upperBound);
        }

        return -1;
    }    
    
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize)
            return false;

        sort(hand.begin(), hand.end());

        while (hand.size())
        {
            int number = *hand.begin();

            for (size_t i = 1; i < groupSize; i++)
            {
                int search = binarySearch(hand, number + i, 0, hand.size() - 1);
                if(search==-1)
                    return false;
                else 
                    hand.erase(hand.begin() + search);
            }
            hand.erase(hand.begin());
        }

        return true;
    }
};

int main()
{

    return 0;
}