/*
public class TreeLinkNode {
    int val;
    TreeLinkNode left = null;
    TreeLinkNode right = null;
    TreeLinkNode next = null;

    TreeLinkNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {
    public TreeLinkNode GetNext(TreeLinkNode root) {
        if(root == null)
            return null;
        if(root.right != null){
            root = root.right;
            while(root.left != null){
                root = root.left;
            }
            return root;
        }
        while(root.next !=  null){
            TreeLinkNode parent = root.next;
            if(parent.left == root){
                return parent;
            }
            root = root.next;
        }
        return null;
    }
}