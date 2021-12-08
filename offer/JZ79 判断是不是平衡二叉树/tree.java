public class Solution {
    static class Info{
        public int level;
        public Info(int a){
            this.level = a;
        }
    }
    public boolean status = true;
    Info dfs(TreeNode root){
        if(root == null)
            return new Info(0);
        Info left = dfs(root.left);
        Info right = dfs(root.right);
        if(Math.abs(left.level - right.level) > 1){
            status = false;
        }
        return new Info(Math.max(left.level, right.level) + 1);
    }
    public boolean IsBalanced_Solution(TreeNode root) {
        if(root == null)
            return true;
        dfs(root);
        return status;
    }
}