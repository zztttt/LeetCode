/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    private Map<Node, Node> mapping = new HashMap<>();
    public Node copyRandomList(Node head) {
        if(head == null)
            return null;
        if(mapping.containsKey(head)){
            return mapping.get(head);
        }else{
            int val = head.val;
            Node cur = new Node(val);
            mapping.put(head, cur);
            cur.next = copyRandomList(head.next);
            cur.random = copyRandomList(head.random);
            return cur;
        }
        
    }
}