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
private:
    unordered_map<int, int> dp;
    int mx = INT32_MIN;

    int solve(TreeNode *node){
        if(!node)
            return 0;

        if(dp.find(node->val)!=dp.end())
            return dp[node->val];

        
        int left = max(node->val + solve(node->left), solve(node->left));
        int rigth = max(node->val + solve(node->right), solve(node->right));

        return dp[node->val] = max(mx, left + rigth);
    }

    
public:
    int maxPathSum(TreeNode* root) {
        return solve(root);
    }
};

int main()
{

    return 0;
}