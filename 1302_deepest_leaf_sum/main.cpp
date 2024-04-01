#include <iostream>
#include <algorithm>
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
    void findMaxDepth(TreeNode *node, int localDepth, int &maxDepth){
        if(!node) return;
        if(!node->left&&!node->right){
            maxDepth = max(maxDepth, localDepth);
            return;
        }
        localDepth++;
        findMaxDepth(node->left, localDepth, maxDepth);
        findMaxDepth(node->right, localDepth, maxDepth);
    }
    
    void sumMaxDepth(TreeNode *node, int &answ, int localDepth, int maxDepth){
        if(!node) return;
        
        if((localDepth==maxDepth)&&!(node->left)&&!(node->right)){
            cout << node->val << endl;
            answ+=node->val;
            return;
        }

        localDepth++;
        sumMaxDepth(node->left, answ, localDepth, maxDepth);
        sumMaxDepth(node->right, answ, localDepth, maxDepth);
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth = 0, answ = 0;
        findMaxDepth(root, 0, maxDepth);
        sumMaxDepth(root, answ, 0, maxDepth);
        return answ;
    }
};

int main()
{
    


    return 0;
}