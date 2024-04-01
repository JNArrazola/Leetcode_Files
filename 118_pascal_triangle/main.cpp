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
    vector<vector<int>> generate(int numRows) {
        if(numRows==1) return {{1}};
        if(numRows==2) return {{1},{1,1}};
        vector<vector<int>> answ = {{1},{1,1}};

        for (size_t i = 3; i <= numRows; i++)
        {
            vector<int> line(i - 1, 1);

            for (size_t j = 1; j < line.size()-1; j++)
                line[j] = answ[i-1][j-1] + answ[i-1][j];

            answ.push_back(line);
        }
        
        return answ;
    }
};

int main()
{

    return 0;
}