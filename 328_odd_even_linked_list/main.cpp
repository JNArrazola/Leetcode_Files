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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *current = head, *temp = nullptr, *nextNode = nullptr;

        while (current->next&&current->next->next->next)
        {
            temp = current->next;
            nextNode = current->next->next;
            current->next = current->next->next;
            current->next->next = temp;
            current->next->next->next = nextNode;
            current = current->next->next;
        }
        
        return head;
    }
};

int main()
{
    


    return 0;
}