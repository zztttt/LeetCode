/*
 public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {
    public ListNode deleteDuplication(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy, cur = head;
        while(cur != null){
            if(cur.next != null && cur.val == cur.next.val){
                // delete
                int val = cur.val;
                while(cur != null){
                    if(cur.val != val)
                        break;
                    cur = cur.next;
                }
                prev.next = cur;
//                 prev = cur;
//                 cur = prev.next;
            }else{
                prev = cur;
                cur = cur.next;
            }
        }
        return dummy.next;
    }
}