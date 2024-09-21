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

        while (head)
        {
            head = head->next;
            ctr++;
        }
        return ctr;
    }

    void generateList(vector<ListNode*> &answ, ListNode *&head, int &sizeOfParts, int &excess){
        int ctr = 0;

        while (head)
        {
            ListNode *prev = nullptr, *start = nullptr;

            start = head;

            for (size_t i = 0; i < sizeOfParts; i++)
            {
                prev = head;
                head = head->next;
            }   
            
            if(excess){
                prev = head;
                head = head->next;
                --excess;
            }

            prev->next = nullptr;
            answ[ctr++] = start;
        }
    }       

public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> answ(k, nullptr);
        
        if(!head || !k)
            return answ;
        
        int length  = calculateLength(head), sizeOfParts = length/k, excess = length%k;
        generateList(answ, head, sizeOfParts, excess);
        return answ;
    }   
};

int main()
{

    return 0;
}