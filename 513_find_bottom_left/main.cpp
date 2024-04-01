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
    void search(TreeNode *node, int isLeft, pair<int, int> &answ, int localDepth){
        if(!node) return;

        if(!node->left&&!node->right&&localDepth > answ.second&&isLeft){
            answ = {node->val, localDepth};
        }

        search(node->left, 1, answ, localDepth++);
        search(node->right, 0, answ, localDepth++);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> answ;
        search(root, 0, answ, 0);
        return answ.first;
    }
};

int main()
{
    


    return 0;
}