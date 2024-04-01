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
    bool validation(unordered_map<int, int> &nums){
        int counterOdd = 0;

        for(auto i : nums){
            if(i.second%2) counterOdd++;
            if(counterOdd == 2) return 0;
        }

        return true;
    }

    void dfs(TreeNode *node, int &answ, unordered_map<int, int> ocurrences){
        if(!node) return;
        
        ocurrences[node->val]++;
        if(!node->left&&!node->right){
            if(validation(ocurrences)) answ++;
            return;
        }
        dfs(node->left, answ, ocurrences);
        dfs(node->right, answ, ocurrences);
    }   
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int answ = 0;
        dfs(root, answ, {});
        return answ;
    }
};

int main()
{

    return 0;
}