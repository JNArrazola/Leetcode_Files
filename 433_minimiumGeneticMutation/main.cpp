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
    void makeRegister(queue<pair<string, short>> &q, unordered_set<string> &viz, string testString, unordered_set<string> &bank, int ctr){
        if(viz.find(testString) == viz.end()&&bank.find(testString) != bank.end()){
            q.push({testString, ++ctr});
            viz.insert(testString);
        }
    }
    
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene)
            return 0;
        
        unordered_set<string> bank_set = {bank.begin(), bank.end()};
        unordered_set<string> viz;
        queue<pair<string, short>> bfs;

        bfs.push({startGene, 0});
        viz.insert(bfs.front().first);

        while (!bfs.empty())
        {
            pair<string, short> p = bfs.front();
            string actualString = p.first;
            bfs.pop();

            if(actualString == endGene){
                viz.clear();
                bank_set.clear();
                return p.second;
            }

            for (size_t i = 0; i < startGene.size(); i++)
            {
                char aux = actualString[i];

                actualString[i] = 'A';
                makeRegister(bfs, viz, actualString, bank_set, p.second);
                actualString[i] = aux;

                actualString[i] = 'C';
                makeRegister(bfs, viz, actualString, bank_set, p.second);
                actualString[i] = aux;

                actualString[i] = 'G';
                makeRegister(bfs, viz, actualString, bank_set, p.second);
                actualString[i] = aux;

                actualString[i] = 'T';
                makeRegister(bfs, viz, actualString, bank_set, p.second);
                actualString[i] = aux;
            }   
        }
        return -1;
    }
};

int main()
{

    return 0;
}