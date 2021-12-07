using System;
using System.Collections.Generic;

/*
public class TreeNode
{
	public int val;
	public TreeNode left;
	public TreeNode right;

	public TreeNode (int x)
	{
		val = x;
	}
}
*/

class Solution {
    public void reverse(TreeNode root){
        if(root == null)
            return;
        TreeNode left = root.left;
        root.left = root.right;
        root.right = left;
        reverse(root.left);
        reverse(root.right);
    }
    public TreeNode Mirror (TreeNode root) {
        reverse(root);
        return root;
    }
}