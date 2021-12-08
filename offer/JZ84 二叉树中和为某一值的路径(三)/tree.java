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
    private int count = 0;
    private void dfs(TreeNode root,int target){
        if(root == null)
            return;
        target = target - root.val;
        if(target == 0)
            count++;
        dfs(root.left, target);
        dfs(root.right, target);
    }
    public int FindPath (TreeNode root, int target) {
        if(root == null)
            return count;
        dfs(root, target);
        FindPath(root.left, target);
        FindPath(root.right, target);
        return count;
    }
}