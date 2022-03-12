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
    public Node copyRandomList(Node head) {
        if(head == null)
            return null;
        Map<Node, Node> mapping = new HashMap<>();
        // store old - new mapping
        Node p = head;
        while(p != null){
            Node cur = new Node(p.val);
            mapping.put(p, cur);
            p = p.next;
        }
        
        p = head;
        while(p != null){
            mapping.get(p).next = mapping.get(p.next);
            mapping.get(p).random = mapping.get(p.random);
            p = p.next;
        }
        
        return mapping.get(head);
    }
}