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

void imprimirLista(ListNode *head)
{
    ListNode *ptr = head;

    while (ptr)
    {
        cout << ptr->val << endl;
        ptr = ptr->next;
    }
}

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1)
        {
            return l2;
        }
        else if (!l2)
        {
            return l1;
        }
        else if (!l1 && !l2)
        {
            return {};
        }

        ListNode *newList = new ListNode;
        ListNode *current = newList;

        int carry = 0;
        int suma;

        while (l1 && l2)
        {
            suma = 0;

            suma = l1->val + l2->val + carry;

            carry = suma / 10;

            current->next = new ListNode(suma % 10);

            l1 = l1->next;
            l2 = l2->next;
            current = current->next;
        }

        if (!l1)
        {
            while (l2)
            {
                suma = 0;

                suma = l2->val + carry;

                carry = suma / 10;

                current->next = new ListNode(suma % 10);

                l2 = l2->next;
            }
        }
        else if (!l2)
        {
            while (l1)
            {
                suma = 0;

                suma = l1->val + carry;

                carry = suma / 10;

                current->next = new ListNode(suma % 10);

                l1 = l1->next;
            }
        }

        return newList->next;
    }
};

int main()
{
    Solution solucion;
    int x = 9 + 9;

    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    solucion.addTwoNumbers(l1, l2);

    /* cout << x / 10 << endl; // carry
    cout << x % 10 << endl; // suma */

    return 0;
}
