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
    void search(TreeNode *&nodo,int &sum, int &low, int &high){
        if(!nodo) return;

        if(nodo->val>=low&&nodo->val<=high) sum+=nodo->val;
        search(nodo->left, sum, low, high);
        search(nodo->right, sum, low, high);
    }
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum = 0;
        search(root, sum, low, high);
        return sum;
    }
};

int main()
{

    return 0;
}