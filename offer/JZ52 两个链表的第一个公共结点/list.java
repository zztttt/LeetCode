/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindFirstCommonNode(ListNode l1, ListNode l2) {
        ListNode head1 = l1, head2 = l2;
        Integer len1 = 0, len2 = 0;
        while(l1 != null){
            len1++;
            l1 = l1.next;
        }
        while(l2 != null){
            len2++;
            l2 = l2.next;
        }
        l1 = head1; l2 = head2;
        if(len1 > len2){
            int gap = len1 - len2;
            while(gap > 0){
                l1 = l1.next;
                gap--;
            }
        }else{
            int gap = len2 - len1;
            while(gap > 0){
                l2 = l2.next;
                gap--;
            }
        }
        while(l1 != null && l2 != null){
            if(l1.equals(l2))
                return l1;
            l1 = l1.next;
            l2 = l2.next;
        }
        return null;
    }
}