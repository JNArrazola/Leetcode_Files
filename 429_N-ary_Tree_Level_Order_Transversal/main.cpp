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


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        
        vector<vector<int>> answ;
        queue<Node*> bfs;

        bfs.push(root);
        while (!bfs.empty())
        {
            int n = bfs.size();
            vector<int> level = {};

            for (size_t i = 0; i < n; i++)
            {
                Node* node = bfs.front();
                level.push_back(node->val);
                bfs.pop();

                vector<Node*> children = node->children;
                for (size_t i = 0; i < children.size(); i++)
                    bfs.push(children[i]);
            }
            answ.push_back(level);
        }
        
        return answ;
    }
};

int main()
{

    return 0;
}