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
using namespace std;

#define PI (3.141592);
#define e (2.7182);

typedef long long ll;

template <typename T>
using vt = vector<T>;

template <typename J, typename A>
using hm = unordered_map<J, A>;

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
    void search(TreeNode *ptrOne, TreeNode *ptrTwo, bool &answ){
        if(answ) return;
        if((!ptrOne&&ptrTwo)||(ptrOne&&!ptrTwo)){
            answ = false;
            return;
        } else if(!ptrOne&&!ptrTwo){
            return;
        }

        search(ptrOne->left, ptrTwo->right, answ);
        search(ptrOne->right, ptrTwo->left, answ);
    }

public:
    bool isSymmetric(TreeNode* root) {
        bool answ = true;
        TreeNode *ptrOne = root, *ptrTwo = root;
        search(ptrOne, ptrTwo, answ);
        return answ;
    }
};

int main()
{

    return 0;
}