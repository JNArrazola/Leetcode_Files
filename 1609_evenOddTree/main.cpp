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
    void queueNodes(TreeNode *&nodeOne, TreeNode *&nodeTwo, queue<TreeNode*> &bfs){
        if(nodeOne)
            bfs.push(nodeOne);
        if(nodeTwo)
            bfs.push(nodeTwo);
    }
    
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        int depth = 0;
        bool isEven = 1;

        while (!bfs.empty())
        {
            int n = bfs.size();
            int toCompare = INT32_MIN;
            
            for (size_t i = 0; i < n; i++)
            {
                TreeNode *node = bfs.front();

                cout << node->val << "|" << toCompare << endl;
                if(toCompare != INT32_MIN)
                    if(node->val <= toCompare)
                        return false;
            
                if(isEven)
                    queueNodes(node->right, node->left, bfs);
                else 
                    queueNodes(node->left, node->right, bfs);

                toCompare = node->val;
                bfs.pop();
            }
            isEven = (isEven) ? 0 : 1;
        }
        return true;
    }
};

int main()
{

    return 0;
}