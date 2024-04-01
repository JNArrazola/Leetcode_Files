#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> map;
        vector<vector<int>> answ = {{}, {}};

        for (size_t i = 0; i < matches.size(); i++)
        {
            if(map.find(matches[i][0])==map.end()) map.insert({matches[i][0], 0});
            map[matches[i][1]]++;
        }
        
        for(const auto &i : map){
            if(!(i.second)) answ[0].push_back(i.first);
            else if(i.second==1) answ[1].push_back(i.first);
        }
        sort(answ[0].begin(), answ[0].end());
        sort(answ[1].begin(), answ[1].end());
        return answ;
    }
};

int main()
{
    


    return 0;
}