import java.util.*;

/*
 * public class TreeNode {
 *   int val = 0;
 *   TreeNode left = null;
 *   TreeNode right = null;
 * }
 */

public class Solution {
    public boolean dfs(TreeNode root, int sum){
        if(root == null)
            return false;
        if(root.left == null && root.right == null && root.val == sum)
            return true;
        return dfs(root.left, sum - root.val) || dfs(root.right, sum - root.val);
    }
    public boolean hasPathSum (TreeNode root, int sum) {
       return dfs(root, sum);
    }
}