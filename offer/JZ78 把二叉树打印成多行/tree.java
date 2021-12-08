import java.util.ArrayList;
import java.util.concurrent.LinkedBlockingQueue;


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
    ArrayList<ArrayList<Integer> > Print(TreeNode root) {
        if(root == null)
            return new ArrayList<>();
        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();
        LinkedBlockingQueue<TreeNode> queue = new LinkedBlockingQueue<>();
        queue.add(root);

        while(!queue.isEmpty()){
            ArrayList<TreeNode> curLevel = new ArrayList<>();
            ArrayList<Integer> curLevelVal = new ArrayList<>();
            while(!queue.isEmpty()){
                TreeNode cur = queue.poll();
                curLevelVal.add(cur.val);
                if(cur.left != null){
                    curLevel.add(cur.left);
                }
                if(cur.right != null){
                    curLevel.add(cur.right);
                }
            }
            ret.add(curLevelVal);
            for(TreeNode t: curLevel){
                queue.add(t);
            }
        }
        return ret;
    }
    
}