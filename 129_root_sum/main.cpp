#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution
{
private:
    void calculateAnswer(TreeNode *node, int actualNumber, int &answ){
        if(!node) return;
        actualNumber = actualNumber*10 + node->val;
        if(!node->left&&!node->right){
            answ+=actualNumber;
            return;
        }
        
        calculateAnswer(node->left, actualNumber, answ);
        calculateAnswer(node->right, actualNumber, answ);
    }
public:
    int sumNumbers(TreeNode *root)
    {
        int answ = 0;
        calculateAnswer(root, 0, answ);
        return answ;
    }
};

int main()
{
    Solution s;
    TreeNode *root;
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    s.sumNumbers(root);
    return 0;
}