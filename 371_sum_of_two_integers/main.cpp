#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

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
    int getSum(int a, int b) {
        if(a==0) return b;
        if(b==0) return a;    

        int signA = (a > 0) ? 1 : -1;
        int signB = (b > 0) ? 1 : -1;

        double absa = abs(a);
        double absb = abs(b);

        double result;

        if(signA == signB){
            result = signA * log(exp(absa)*exp(absb));
        } else {
            if(signA > signB){
                result = signA * log(exp(absa)/exp(absb));
            } else {
                result = signB * log(exp(absb)/exp(absa));
            }
        }
        return (int)round(result);
    }
};

int main()
{

    return 0;
}