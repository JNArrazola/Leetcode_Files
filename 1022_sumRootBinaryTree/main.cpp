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
    int convertToDecimal(string number){
        if(number.size() == 0)
            return 0;
        
        int answ = 0;

        for (int i = 0; i < number.size(); i++)
            if(number[i] == '1')
                answ += pow(2, number.length() - i - 1);
        
        return (int)answ;
    }
    
    void dfs(int &answ, TreeNode *node, string str){
        if(!node)
            return;
        
        str+=to_string(node->val);
        
        if(!node->left&&!node->right){
            answ+=convertToDecimal(str);
            return;
        }

        dfs(answ, node->left, str);
        dfs(answ, node->right, str);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root)
            return 0;
        
        int answ = 0;
        dfs(answ, root, "");
        return answ;
    }
};

int main()
{
    Solution s;

    s.sumRootToLeaf(nullptr);
    return 0;
}