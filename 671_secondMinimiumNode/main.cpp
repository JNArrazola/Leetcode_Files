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

class LowestValues{
    public:
        int lowest;
        int sLowest;
        LowestValues(){
            lowest = INT32_MAX;
            sLowest = INT32_MAX;
        };
};

class Solution {
private:
    void dfs(TreeNode* node, LowestValues* &lw){
        if(!node)
            return;
        
        if(lw->lowest > node->val){
            if(lw->lowest == INT32_MAX)
                lw->lowest = node->val;
            else {
                lw->sLowest = lw->lowest;
                lw->lowest = node->val;
            }
        }

        dfs(node->left, lw);
        dfs(node->right, lw);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        
        LowestValues* lw = new LowestValues();
        
        dfs(root, lw);

        return ((lw->lowest == lw->sLowest) ? -1 : lw->sLowest);
    }
};

int main()
{

    return 0;
}