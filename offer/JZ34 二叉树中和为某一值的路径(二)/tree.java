import java.util.ArrayList;
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
    private void dfs(TreeNode root,int target, ArrayList<ArrayList<Integer>> ret, ArrayList<Integer> path){
        if(root  == null)
            return;
        if(root.left == null && root.right == null && root.val == target){
            ArrayList<Integer> data = new ArrayList<>(path);
            data.add(root.val);
            ret.add(new ArrayList<>(data));
            return;
        }
        path.add(root.val);
        dfs(root.left, target - root.val, ret, path);
        dfs(root.right, target - root.val, ret, path);
        path.remove(path.size() - 1);
    }
    
    public ArrayList<ArrayList<Integer>> FindPath(TreeNode root,int target) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();
        ArrayList<Integer> path = new ArrayList<>();
        dfs(root, target, ret, path);
        return ret;
    }
}