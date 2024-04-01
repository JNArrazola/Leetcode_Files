#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <array>
using namespace std;

#define PI (3.141592);
#define e (2.7182);

typedef long long ll;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

static vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();

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
    void search(TreeNode *node, int level, vector<int> &answ){
        if(!node) return;
        if(answ.size()>level){
            answ[level] = max(answ[level], node->val);
        } else {
            answ.push_back(node->val);
        }
        level++;
        search(node->left, level, answ);
        search(node->right, level, answ);
    }
    
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> answ = {};
        search(root, 0, answ);
        return answ;
    }
};

int main()
{

    return 0;
}