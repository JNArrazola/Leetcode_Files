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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    private:
        bool dfs(ListNode *head, TreeNode *node){
            if(!head)
                return true;
            if(!node)
                return false;

            if(head->val == node->val)
                if(dfs(head->next, node->left) || dfs(head->next, node->right))
                    return true;
            return false;
        }
    
        bool goThrough(ListNode *head, TreeNode *node){
            if(!node)
                return false;

            if(dfs(head, node))
                return true;
            
            return goThrough(head, node->left) || goThrough(head, node->right);
        }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return goThrough(head, root);
    }
};

int main()
{

    return 0;
}