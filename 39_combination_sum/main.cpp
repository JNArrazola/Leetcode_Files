#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void aux(vector<int> &candidates, vector<int> possibleCase, vector<vector<int>> &answ, int residuo, int start){
        if(!residuo) {
            answ.push_back(possibleCase);
            return;
        }
        
        for (size_t i = start; i < candidates.size(); i++) {
            if(candidates[i]<=residuo){
                possibleCase.push_back(candidates[i]);
                aux(candidates, possibleCase, answ, residuo - candidates[i], i);
                possibleCase.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answ;
        vector<int> possibleCase;
        aux(candidates, possibleCase, answ, target, 0);
        return answ;
    }
};


int main()
{
    


    return 0;
}