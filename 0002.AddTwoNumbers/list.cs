/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1), p = dummy;
        int carry = 0;
        while(l1 != null && l2 != null){
            int cur = l1.val + l2.val + carry;
            carry = cur / 10;
            cur = cur % 10;
            ListNode tmp = new ListNode(cur);
            p.next = tmp;
            p = p.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        ListNode rest = null;
        if(l1 != null)
            rest = l1;
        if(l2 != null)
            rest = l2;
        while(rest != null){
            int cur = rest.val + carry;
            carry = cur / 10;
            cur = cur % 10;
            ListNode tmp = new ListNode(cur);
            p.next = tmp;
            p = p.next;
            rest = rest.next;
        }
        if(carry != 0){
            p.next = new ListNode(carry);
        }
        
        return dummy.next;
    }
}