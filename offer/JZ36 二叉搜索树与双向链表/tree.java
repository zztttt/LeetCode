/**
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    private TreeNode head = new TreeNode(0);
    private TreeNode tail = head;
    private void pre(TreeNode root){
        if(root != null){
            pre(root.left);
            TreeNode prev = tail;
            tail.right = new TreeNode(root.val);
            tail = tail.right;
            tail.left = prev;
            pre(root.right);
        }
    }
    public TreeNode Convert(TreeNode root) {
        if(root == null)
            return null;
        pre(root);
        head = head.right;
        head.left = null;
        return head;
    }
}