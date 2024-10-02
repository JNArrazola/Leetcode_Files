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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 
class Solution {
private:
    ListNode *head;
    
    ListNode* swapp(ListNode *&nd){
        if(!nd->next || !nd->next->next)
            return nd;

        ListNode *prev = nd, *curr = nd->next, *nxt = nd->next->next;

        curr->next = prev;

        if(prev == head)
            head = curr;

        prev->next = swapp(nxt);
        return head;
    }

public:
    ListNode* swapPairs(ListNode* head) {
        this->head = head;
        if(!head || !head->next)
            return head;

        return swapp(head);
    }
};
 */

class Solution {
private:
    ListNode *head;
    
    ListNode* swapp(ListNode *nd){
        if(!nd || !nd->next)
            return nd;

        ListNode *prev = nd, *curr = nd->next, *nxt = nd->next->next;

        nxt = nd->next->next;
        curr->next = prev;

        nd = curr;

        prev->next = swapp(nxt);
        return curr;
    }

public:
    ListNode* swapPairs(ListNode* head) {
        this->head = head;
        if(!head || !head->next)
            return head;

        return swapp(head);
    }
};

int main()
{

    return 0;
}