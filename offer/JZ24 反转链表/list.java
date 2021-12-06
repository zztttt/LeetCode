/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode ReverseList(ListNode head) {
         ListNode dummy = new ListNode(-1);
        while(head != null){
            ListNode old = dummy.next, p = head;
            head = head.next;
            dummy.next = p;
            p.next = old;
        }
        return dummy.next;
    }
}