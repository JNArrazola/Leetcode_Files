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
private:
    int binarySearch(int lowerBound, int upperBound, vector<int> nums, int num){
        while (lowerBound <= upperBound)
        {
            int middle = lowerBound + (upperBound - lowerBound)/2;

            if(nums[middle] == num){
                return middle;
            } else if(nums[middle] < num){
                return binarySearch(middle + 1, upperBound, nums, num);
            } else {
                return binarySearch(lowerBound, middle - 1, nums, num);
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size()-1, nums, target);
    }
};

int main()
{

    return 0;
}