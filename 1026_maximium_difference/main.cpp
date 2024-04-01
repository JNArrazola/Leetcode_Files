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
    void searchAnswer(TreeNode *&node, int localMax, int localMin,int &answ){
        if(!node){
            answ = max(answ, localMax - localMin);
            return;
        }

        localMax = max(localMax, node->val);
        localMin = min(localMin, node->val);
        
        searchAnswer(node->left, localMax, localMin, answ);
        searchAnswer(node->right, localMax, localMin, answ);
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        int answ = 0;
        searchAnswer(root, INT32_MIN, INT32_MAX, answ);
        return answ;
    }
};

int main()
{
    
    return 0;
}