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
    void DFS(TreeNode* root, long long targetSum, vector<long> sums, int &ctr){
        if(!root) return;

        for(long & i : sums){
            i+=root->val;
            if(i==targetSum) ctr++;
        }
        sums.push_back(root->val);
        if(root->val==targetSum) ctr++;

        DFS(root->left, targetSum, sums, ctr);
        DFS(root->right, targetSum, sums, ctr);
        sums.pop_back();
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int ctr = 0;

        vector<long> sums;
        sums.push_back(root->val);
        if(sums[0]==targetSum) ctr++;
        DFS(root->left, targetSum, sums, ctr);
        DFS(root->right, targetSum, sums, ctr);

        return ctr;
    }
};

int main()
{

    return 0;
}