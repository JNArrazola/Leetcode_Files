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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *prev = nullptr, *nxt = nullptr;
        vector<int> answ;

        while (head)
        {
            nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        
        int mx = INT32_MIN;
        while (prev)
        {
            if(prev->val > mx){
                mx = max(mx, prev->val);
                answ.push_back(0);
            } else
                answ.push_back(mx);
            prev = prev->next;
        }
        
        reverse(answ.begin(), answ.end());
        return answ;
    }
};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    return 0;
}