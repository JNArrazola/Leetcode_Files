#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode;

        dummy->next = head;
        ListNode *cur = dummy;

        while (cur->next!=nullptr)
        {
            if(cur->next->val==val){
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        
        return dummy->next; 
    }
};

int main()
{
    Solution solucion;
    ListNode *node = new ListNode(7);
    node->next = new ListNode(7);
    node->next->next = new ListNode(2);
    node->next->next->next = new ListNode(7);

    solucion.removeElements(node, 7);
    return 0;
}