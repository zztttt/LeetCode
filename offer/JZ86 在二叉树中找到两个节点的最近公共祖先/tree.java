import java.util.*;

/*
 * public class TreeNode {
 *   int val = 0;
 *   TreeNode left = null;
 *   TreeNode right = null;
 * }
 */

public class Solution {
    private TreeNode find(TreeNode root, int a, int b){
        if(root == null)
            return null;
        if(root.val == a || root.val == b)
            return root;
        TreeNode left = find(root.left, a, b);
        TreeNode right = find(root.right, a, b);
        if(left == null)
            return right;
        if(right == null)
            return left;
        return root;
    }
    public int lowestCommonAncestor (TreeNode root, int a, int b) {
        return find(root, a, b).val;
    }
}