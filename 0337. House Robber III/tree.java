/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static class RobInfo{
        public int curMax;
        public int notRobMax;
        public RobInfo(int _curMax, int _notRobMax){
            this.curMax = _curMax;
            this.notRobMax = _notRobMax;
        }
    }
    private RobInfo robNode(TreeNode root){
        if(root == null){
            return new RobInfo(0, 0);
        }
        RobInfo left = robNode(root.left);
        RobInfo right = robNode(root.right);
        int robMax = root.val + left.notRobMax + right.notRobMax;
        int notRobMax = left.curMax + right.curMax;
        int curMax = Math.max(robMax, notRobMax);
        return new RobInfo(curMax, notRobMax);
    }
    public int rob(TreeNode root) {
        RobInfo robInfo = robNode(root);
        return Math.max(robInfo.curMax, robInfo.notRobMax);
    }
}