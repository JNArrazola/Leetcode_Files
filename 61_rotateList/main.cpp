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
    int calculateLength(ListNode *head){
        int ctr = 0;

        while (head){
            ctr++;
            head = head->next;
        }
        return ctr;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return nullptr;
        if(!k)
            return head;

        int l = calculateLength(head);
        
        if(l == 1)
            return head;

        int numberOfRotations = k%l;

        if(!numberOfRotations)
            return head;

        ListNode *prev = nullptr, *actual = head;
        for (size_t i = 0; i < l - numberOfRotations; i++)
        {
            prev = actual;
            actual = actual->next;
        }

        ListNode *definitiveHead = actual;

        while (actual->next)
            actual = actual->next;
        
        actual->next = head;

        prev->next = nullptr;
        return definitiveHead;
    }
};

int main()
{

    return 0;
}