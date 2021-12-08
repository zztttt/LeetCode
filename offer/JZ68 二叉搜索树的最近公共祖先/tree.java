import java.util.*;

/*
 * public class TreeNode {
 *   int val = 0;
 *   TreeNode left = null;
 *   TreeNode right = null;
 *   public TreeNode(int val) {
 *     this.val = val;
 *   }
 * }
 */

public class Solution {
    private TreeNode find(TreeNode root, int a, int b){
        if(root == null)
            return null;
        if(a <= root.val && root.val <= b)
            return root;
        if(a < root.val && b < root.val)
            return find(root.left, a, b);
        return find(root.right, a, b);
    }
    public int lowestCommonAncestor (TreeNode root, int a, int b) {
        if(a > b){
            int tmp = a;
            a = b;
            b = tmp;
        }
        return find(root, a, b).val;
    }
}