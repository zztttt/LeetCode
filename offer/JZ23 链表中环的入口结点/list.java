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

    public ListNode EntryNodeOfLoop(ListNode head) {
        ListNode fast = head, slow = head;
        Boolean hasCycle = false;
        while(fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
            if(fast == null && slow != null)
                return null;
            if(fast.equals(slow)){
                hasCycle = true;
                break;
            }
        }
        if(!hasCycle)
            return null;
        fast = head;
        //System.out.println(fast.val + "," + slow.val);
        while(fast != null){
            if(fast.equals(slow)){
                return fast;
            }
            fast = fast.next;
            slow = slow.next;
        }
        return null;
    }
}