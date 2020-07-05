public class list {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(), p = dummy;
        int carry = 0;
        while(l1!= null && l2 != null){
            int cur = l1.val + l2.val + carry;
            carry = cur / 10;
            cur = cur % 10;
            p.next = new ListNode(cur);
            p = p.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        ListNode rest = null;
        if(l1 != null){
            rest = l1;
        }
        if(l2 != null){
            rest = l2;
        }
        while(rest != null){
            int cur = carry + rest.val;
            carry = cur / 10;
            cur = cur % 10;
            p.next = new ListNode(cur);
            p = p.next;
            rest = rest.next;
        }
        if(carry != 0){
            p.next = new ListNode(carry);
        }
        return dummy.next;
    }
    public static void main(String[] args) throws Exception{
        System.out.println(111);
    }
}