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
#include <deque>
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};

        queue<TreeNode*> bfs;
        vector<vector<int>> answ;
        bool LtoR = true;
        bfs.push(root);

        while (!bfs.empty())
        {
            vector<int> temp;
            int n = bfs.size();

            for (size_t i = 0; i < n; i++)
            {
                TreeNode *node = bfs.front();
                bfs.pop();
                temp.push_back(node->val);

                if(node->left) bfs.push(node->left);
                if(node->right) bfs.push(node->right);
            }
            
            if(!LtoR)
                reverse(temp.begin(), temp.end());

            answ.push_back(temp);

            LtoR = !LtoR;
        }
        
        return answ;
    }
};

int main()
{

    return 0;
}