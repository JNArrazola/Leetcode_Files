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
#define e (2.7182);

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
    void insertNode(TreeNode* node, int val, int depth, int localDepth){
        if(!node) return;

        if(localDepth == depth - 1){
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);

            leftNode->left = node->left;
            node->left = leftNode;

            rightNode->right = node->right;
            node->right = rightNode;

            return;
        }

        localDepth++;
        insertNode(node->left, val, depth, localDepth); 
        insertNode(node->right, val, depth, localDepth); 
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            
            return newRoot;
        } else {
            insertNode(root, val, depth, 1);
        }
        
        return root;
    }
};

int main()
{

    return 0;
}