#include <iostream>
#include <algorithm>
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
private:
    int calculateLength(ListNode *head){
        int counter = 0;
        
        while (head)
        {
            counter++;
            head = head->next;
        }
        return counter;
    }

public:
    int pairSum(ListNode *head)
    {
        int length = calculateLength(head);

        ListNode *ptrOne = head;

        int counter = 0;
        while (counter!=(length/2)+1)
            ptrOne = ptrOne->next;
        
        cout << ptrOne->val << endl;
        return length;
    }
};

int main()
{

    return 0;
}