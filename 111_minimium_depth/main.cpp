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
    void searchMinimiumDepth(TreeNode *node, int localDepth, int &answ){
        if(!node) return;
        localDepth++;

        if(localDepth>answ) return;
        if(!node->left&&!node->right){
            answ = min(answ, localDepth);
        }

        searchMinimiumDepth(node->left, localDepth, answ);
        searchMinimiumDepth(node->right, localDepth, answ);
    }

public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        int answ = INT32_MAX;
        searchMinimiumDepth(root, 0, answ);
        return answ;
    }
};

int main()
{
    


    return 0;
}