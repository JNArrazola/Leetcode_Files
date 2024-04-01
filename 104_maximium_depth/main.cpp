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
    void calculateDepth(TreeNode *&node ,int &answ, int depth){
        if(!node){
            answ = max(answ, depth);
            return;
        }

        calculateDepth(node->left, answ, depth+1);
        calculateDepth(node->right, answ, depth+1);
    }
public:
    int maxDepth(TreeNode *root)
    {
        int answ = INT32_MIN;
        calculateDepth(root, answ, 0);
        return answ;
    }
};

int main()
{

    return 0;
}