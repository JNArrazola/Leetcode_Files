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
#include <set>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("03")
#pragma GCC target ("avx")

#define PI (3.141592);

typedef long long ll;
typedef long l;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

template <typename R>
using st = stack<R>;

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
    bool dfs(TreeNode *node, TreeNode *subRoot, bool searchingSubTree){
        if(!node||!subRoot){
            if(!searchingSubTree)
                return false;

            return !node&&!subRoot;
        }

        if(searchingSubTree)
            if(node->val != subRoot->val)
                return false;

        if(node->val == subRoot->val)
            if(dfs(node->left, subRoot->left, true) && dfs(node->right, subRoot->right, true))
                return true;
            else 
                if(searchingSubTree)
                    return false;
        
        return dfs(node->left, subRoot, false) || dfs(node->right, subRoot, false);
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot, false);
    }
};

int main()
{

    return 0;
}