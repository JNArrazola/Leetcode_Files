#include <iostream>
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
    void searchTarget(TreeNode *node, int actualSum, int &targetSum, int &boolean){
        if(!node||boolean) return;

        actualSum+=node->val;
        if(!node->left&&!node->right){
            if(actualSum==targetSum) boolean = 1;
            return;
        }
        searchTarget(node->left, actualSum, targetSum, boolean);
        searchTarget(node->right, actualSum, targetSum, boolean);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int answ = 0;
        searchTarget(root, 0, targetSum, answ);
        return answ;
    }
};

int main()
{
    


    return 0;
}