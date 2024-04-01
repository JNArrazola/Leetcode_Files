#include <iostream>
#include <vector>
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
    void buscar(TreeNode *node, vector<int> &leafs){
        if(!node) return;
        
        if(!node->left&&!node->right){
            leafs.push_back(node->val);
            return;
        }
        buscar(node->left, leafs);
        buscar(node->right, leafs);
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafsOne; 
        vector<int> leafsTwo; 

        buscar(root1, leafsOne);
        buscar(root2, leafsTwo);

        if(leafsOne.size()!=leafsTwo.size()) return 0;

        for (size_t i = 0; i < leafsOne.size(); i++)
            if(leafsOne[i]!=leafsTwo[i]) return 0;
        return 1;
    }
};

int main()
{
    


    return 0;
}