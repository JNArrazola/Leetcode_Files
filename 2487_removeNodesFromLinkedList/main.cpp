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
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head->next)
            return head;
        
        ListNode *prev = nullptr, *ptr = head;

        while (ptr&&ptr->next)
        {
            if(ptr->val < ptr->next->val){
                if(ptr == head){
                    ListNode *temp = head;
                    head = head->next;
                    delete temp;
                    ptr = head;
                } else {
                    ListNode *temp = ptr;
                    prev->next = ptr->next;
                    ptr = ptr->next;
                    delete temp;
                }
            } else {
                prev = ptr;
                ptr = ptr->next;
            }
        }
        
        return head;
    }
};

int main()
{

    return 0;
}