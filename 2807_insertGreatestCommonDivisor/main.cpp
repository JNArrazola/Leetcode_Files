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

class Solution {
private:
    int euclideanAlgorithm(int a, int b){
        if(a < b) swap(a, b);

        while (b)
        {
            int t = b;
            b = a%b;
            a = t;
        }
        
        return a;
    }
    
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *ptr = head;

        while (ptr&&ptr->next)
        {
            int gdc = euclideanAlgorithm(ptr->val, ptr->next->val);

            ListNode *n = new ListNode(gdc);
            ListNode *t = ptr->next;

            ptr->next = n;
            n->next = t;    
            ptr = ptr->next->next;
        }
        return head;
    }
};

int main()
{
    Solution s;
    ListNode * a = s.insertGreatestCommonDivisors(nullptr);
    return 0;
}