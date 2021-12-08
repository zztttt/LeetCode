/*
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
    boolean isMatching(TreeNode a, TreeNode b){
        if(a == null && b == null)
            return true;
        if(a == null && b != null)
            return false;
        if(a != null && b == null)
            return false;
        if(a.val != b.val)
            return false;
        return isMatching(a.left, b.right) && isMatching(a.right, b.left);
    }
    boolean isSymmetrical(TreeNode root) {
        if(root == null)
            return true;
        return isMatching(root.left, root.right);
    }
}