/**
*    public class ListNode {
*        int val;
*        ListNode next = null;
*
*        ListNode(int val) {
*            this.val = val;
*        }
*    }
*
*/
import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode head) {
        ListNode dummy = new ListNode(-1);
        while(head != null){
            ListNode old = dummy.next, p = head;
            head = head.next;
            
            dummy.next = p;
            p.next = old;
            
        }
        ArrayList<Integer> ret = new ArrayList<>();
        dummy = dummy.next;
        while(dummy != null){
            ret.add(dummy.val);
            dummy = dummy.next;
        }
        return ret;
    }
}