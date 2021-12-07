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
    public Boolean isMatching(TreeNode root, TreeNode node){
        if(node == null)
            return true;
        if(root == null || root.val != node.val)
            return false;
        return isMatching(root.left, node.left) && isMatching(root.right, node.right);
    }
    public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        if(root1 == null ||root2 == null)
            return false;
        if(isMatching(root1, root2))
            return true;
        else
            return HasSubtree(root1.left, root2) || HasSubtree(root1.right, root2);
    }
}