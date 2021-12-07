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
    private ArrayList<Integer> preOrder = new ArrayList<>();
    private void preOrderTraverse(TreeNode root){
        if(root == null)
            return;
        preOrderTraverse(root.left);
        preOrder.add(root.val);
        preOrderTraverse(root.right);
    }
    public int KthNode (TreeNode root, int k) {
        preOrderTraverse(root);
        if(preOrder.size() < k || k <= 0)
            return -1;
        return preOrder.get(k - 1);
    }
}