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

class Solution {
private:
    void searchAnswer(TreeNode *node, vector<vector<int>> &answ, int depth){
        if(!node) return;

        if(answ.size() <= depth) answ.push_back({node->val});
        else answ[depth].push_back(node->val);

        depth++;
        searchAnswer(node->left, answ, depth);
        searchAnswer(node->right, answ, depth);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> answ(0);
        searchAnswer(root, answ, 0);

        for (size_t i = 0; i < answ.size()/2; i++)
            swap(answ[i], answ[answ.size()-i-1]);
        
        return answ;
    }
};

int main()
{

    return 0;
}