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
    int maxArea(vector<int>& height) {
        int ptrOne = 0, ptrTwo = height.size() - 1, answ = INT32_MIN;
        
        while (ptrOne <= ptrTwo)
        {
            if(height[ptrOne] < height[ptrTwo]){
                answ = max((ptrTwo-ptrOne)*height[ptrOne], answ);
                ptrOne++;
            } else {
                answ = max((ptrTwo-ptrOne)*height[ptrTwo], answ);
                ptrTwo--;
            }
        }
        
        return answ;
    }
};

int main()
{

    return 0;
}