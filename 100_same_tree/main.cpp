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
    void search(TreeNode *p, TreeNode *q, int &answ){
        if(!p&&!q) return;
        
        if(!p&&q||p&&!q){
            answ = 0;
            return;
        }

        if(p->val!=q->val){
            answ = 0;
            return;
        }

        search(p->left, q->left, answ);
        search(p->right, q->right, answ);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int flag = 1;

        search(p, q, flag);
        return flag;
    }
};

int main()
{
    


    return 0;
}