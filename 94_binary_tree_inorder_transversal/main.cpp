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
    void search(TreeNode *node, vector<int> &answ){
        if(!node) return;

        if(!node->left&&!node->right){
            answ.push_back(node->val);
            return;
        }

        if(node->left) search(node->left, answ);
        answ.push_back(node->val);
        if(node->right) search(node->right, answ);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answ;
        search(root, answ);
        return answ;
    }
};

int main()
{
    


    return 0;
}