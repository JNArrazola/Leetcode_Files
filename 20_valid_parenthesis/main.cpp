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

int main()
{
    vector<vector<int>> mt(5, vector<int>(5));
    pair<int, int> one;
    int n = mt.size();
    for (size_t i = 0; i < n; i++)
    {
        vector<int> input;
        for (size_t j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            if(num==1) one = {i, j};
            input.push_back(num);
        }
        mt.push_back(input);
    }
    
    int x = one.first, y = one.second;

    int answ = abs( n - 1 - x) + abs(n - 1 -y);
    cout << answ << endl;
    return 0;
}