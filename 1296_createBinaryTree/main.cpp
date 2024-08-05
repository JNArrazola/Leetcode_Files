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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> hm;
        vector<int>

        for(vector<int> &v : descriptions){
            if(hm.find(v[0]) == hm.end()){
                TreeNode *node = new TreeNode();
                if(v[2])
                    node->left = new TreeNode(v[1]);
                else 
                    node->right = new TreeNode(v[1]);
                hm[node->val] = node;
            } else { 
                if(v[2]){
                    hm[v[0]]->left = new TreeNode(v[1]);
                }
                else {
                    hm[v[0]]->right = new TreeNode(v[1]);
                }

            } 
        }

    }
};

int main()
{

    return 0;
}