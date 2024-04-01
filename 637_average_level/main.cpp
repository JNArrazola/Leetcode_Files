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

struct summatory{
    int counter;
    double sum;
};

class Solution {
private:
    void search(TreeNode*node, vector<summatory> &v, int level){
        if(!node) return;
        if(v.size()<=level){
            summatory n;
            n.sum = node->val;
            n.counter = 1;
        } else {
            v[level].sum += node->val;
            v[level].counter++;
        }
        level++;
        search(node->left, v, level);
        search(node->right, v, level);
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<summatory> v;

        search(root, v, 0);
        if(v.empty()) return {0};

        vector<double> answ;

        for (size_t i = 0; i < v.size(); i++)
            answ.push_back(v[i].sum/v[i].counter);
        return answ;
    }
};

int main()
{

    return 0;
}