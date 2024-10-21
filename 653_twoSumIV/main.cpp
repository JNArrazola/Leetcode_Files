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
    bool dfs(TreeNode *nd, const int &k, unordered_set<int> &st){
        if(!nd)
            return false;

        if(st.find(k - nd->val) != st.end())
            return true;
        
        st.insert(nd->val);

        return dfs(nd->left, k, st) || dfs(nd->right, k, st);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;

        return dfs(root, k, st);
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}