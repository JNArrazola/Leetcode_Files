public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode doubleIt(ListNode head) {
        ListNode before = null;

        ListNode temp = head;
        while (temp != null) {
            ListNode next = temp.next;
            temp.next = before;
            before = temp;
            temp = next;
        }
        head = before;
        temp = head;

        int carry = 0;
        while (temp.next != null) {
            int value = temp.val*2 + carry;
            


            temp.val = temp.val%10;
            temp = temp.next;
        }

        while (carry > 9) {
            temp.next = new ListNode(carry);
            carry = ((temp.val > 9) ? temp.val/10 : 0);
        }

        return temp;
    }
};
