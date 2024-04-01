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
    void search(TreeNode *&node, int &answ, int isLeft){
        if(!node) return;
        
        if(!node->left&&!node->right&&isLeft){
            answ+=node->val;
            return;
        } else if(!node->left&&!node->right&&!isLeft){
            return;
        }

        search(node->left, answ, 1);
        search(node->right, answ, 0);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int answ = 0;
        search(root, answ, 0);
    }
};

int main()
{
    


    return 0;
}