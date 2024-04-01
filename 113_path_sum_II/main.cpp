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
    void searchTracks(TreeNode *node, int localSum, int &targetSum, vector<vector<int>> &answ, vector<int> nums){
        if(!node) return;

        localSum+=node->val;
        nums.push_back(node->val);

        if(!node->left&&!node->right){
            if(localSum == targetSum){
                answ.push_back(nums);
                return;
            }
        }

        searchTracks(node->left, localSum, targetSum, answ, nums);
        searchTracks(node->right, localSum, targetSum, answ, nums);
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answ;
        vector<int> nums;
        searchTracks(root, 0, targetSum, answ, nums);
        return answ;
    }
};

int main()
{
    


    return 0;
}