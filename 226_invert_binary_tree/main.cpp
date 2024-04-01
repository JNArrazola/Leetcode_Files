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
    void invert(TreeNode *node){
        if(!node) return;
        swap(node->left, node->right);

        invert(node->left);
        invert(node->right);
    }
    
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};

int main()
{
    


    return 0;
}