#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int answ = 0;
        
        for (size_t i = 0; i < colors.size() - 1; i++)
        {
            int minimium = INT32_MAX;
            if(colors[i]==colors[i+1]){
                char top = colors[i];
                while (colors[i]==top)
                {
                    minimium = min(neededTime[i], minimium);
                    i++;
                }
                answ+=minimium;
            }
        }
        return answ;
    }
};

int main()
{
    


    return 0;
}