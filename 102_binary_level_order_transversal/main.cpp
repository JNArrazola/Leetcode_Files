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
    void searchAnswer(TreeNode *node, vector<vector<int>> &answ, int depth){
        if(!node) return;

        if(answ.size() -1 < depth + 1) answ.push_back({node->val});
        else answ[depth].push_back(node->val);

        depth++;
        searchAnswer(node->left, answ, depth);
        searchAnswer(node->right, answ, depth);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answ;

        searchAnswer(root, answ, 0);
        return answ;
    }
};

int main()
{
    


    return 0;
}