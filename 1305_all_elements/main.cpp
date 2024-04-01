#include <iostream>
#include <vector>
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
    void transverseTree(TreeNode *node, vector<int> &answ){
        if(!node) return;
        answ.push_back(node->val);
        transverseTree(node->left, answ);
        transverseTree(node->right, answ);
    }
    
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> answ;
        transverseTree(root1, answ);
        transverseTree(root2, answ);
        sort(answ.begin(),answ.end());
        return answ;
    }
};

int main()
{
    


    return 0;
}