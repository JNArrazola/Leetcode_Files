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
    void search(TreeNode *node, int &answ){
        if(!node) return;

        if(!node->val%2){
            if(node->left&&node->left->left) answ+=node->left->left->val;
            if(node->left&&node->left->right) answ+=node->left->right->val;
            if(node->right&&node->right->left) answ+=node->right->left->val;
            if(node->right&&node->right->right) answ+=node->right->right->val;
        }
        search(node->left, answ);
        search(node->right, answ);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        int answ = 0;
        search(root, answ);
        return answ;
    }
};

int main()
{
    


    return 0;
}