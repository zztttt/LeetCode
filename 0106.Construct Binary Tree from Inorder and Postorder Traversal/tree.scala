/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */
object Solution {
    def buildTree(inorder: Array[Int], postorder: Array[Int]): TreeNode = {
        build(inorder, postorder, 0, inorder.length - 1, 0, postorder.length - 1);
    }
    def build(inorder: Array[Int], postorder: Array[Int], ilow: Int, ihigh: Int, plow: Int, phigh: Int): TreeNode = {
        var ret: TreeNode = null;
        if(ilow == ihigh || plow == phigh)
            ret = new TreeNode(inorder(ilow));
        else if(ilow < ihigh && plow < phigh){
            val rootVal = postorder(phigh);
            ret = new TreeNode(rootVal);
            val pos = findPos(inorder, ilow, ihigh, rootVal);
            ret.left = build(inorder, postorder, ilow, pos - 1, plow, plow + (pos - ilow) - 1);
            ret.right = build(inorder, postorder, pos + 1, ihigh, plow + (pos - ilow), phigh - 1);
        }
        return ret;
    }
    def findPos(v: Array[Int], low: Int, high: Int, target: Int): Int = {
        var i = 0;
        for(i <- low to high){
            if(v(i) == target)
                return i;
        }
        return -1;
    }
}