#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newListHead = nullptr;
        ListNode *ptrNewList = newListHead;

        int sum = 0, carry = 0;
        while (l1&&l2)
        {
            sum = l1->val + l2->val + carry;
            carry = 0;
            
            if(sum>=10){
                carry = sum / 10;
                sum%=10;
            }

            if(!ptrNewList){
                ptrNewList = new ListNode(sum);
            } else {
                ptrNewList->next = new ListNode(sum);
                ptrNewList = ptrNewList->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return newListHead;
    }
};

int main()
{
    


    return 0;
}