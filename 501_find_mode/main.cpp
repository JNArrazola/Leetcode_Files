#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void searchSolution(TreeNode *node, unordered_map<int, int> &counter){
        if(!node) return;
        counter[node->val]++;
        searchSolution(node->left, counter);
        searchSolution(node->right, counter);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> answ;
        unordered_map<int, int> counter;
        searchSolution(root, counter);

        int mayor = INT32_MIN;
        for(auto c : counter)
            if(c.second > mayor) mayor = c.second;

        for(auto c : counter) if(c.second==mayor) answ.push_back(c.first); 

        return answ;
    }
};

int main()
{
    


    return 0;
}