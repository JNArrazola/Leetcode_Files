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
    void search(TreeNode *node, string actualString, vector<string> &answ){
        if(!node) return;
        

        
        if(actualString.empty()){
            actualString+=to_string(node->val);
        } else {
            actualString+=("->"+to_string(node->val));
        }

        if(!node->left&&!node->right){
            answ.push_back(actualString);
            return;
        }
        search(node->left, actualString, answ);
        search(node->right, actualString, answ);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answ;

        search(root, "", answ);
        return answ;
    }
};

int main()
{
    


    return 0;
}