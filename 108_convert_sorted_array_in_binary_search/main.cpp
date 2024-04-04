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
    void insertNode(TreeNode *&node, int &num){
        if(!node){
            node = new TreeNode(num);
            return;
        }

        if(node->val < num){
            
        }

    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = nullptr;


    }
};

int main()
{
    


    return 0;
}