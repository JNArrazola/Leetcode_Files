#include <iostream>
#include <string>
#include <math.h>
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
    int getDecimalValue(ListNode* head) {
        string number = "";
        int answ = 0;

        while (head)
        {
            number+=to_string(head->val);
            head = head->next;
        }
        
        for (size_t i = 0; i < number.size(); i++)
            if(number[i]!='0')
                answ+= pow(2, number.size()-i - 1);
        
        return answ;
    }
};

int main()
{
    Solution s;
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    s.getDecimalValue(head);

    return 0;
}