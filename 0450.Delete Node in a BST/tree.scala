/**
 * Definition for a binary tree node.
 * class TreeNode(_value: Int = 0, _left: TreeNode = null, _right: TreeNode = null) {
 *   var value: Int = _value
 *   var left: TreeNode = _left
 *   var right: TreeNode = _right
 * }
 */
object Solution {
    def deleteNode(root: TreeNode, key: Int): TreeNode = {
        if(root == null)
            return null;
        if(key < root.value){
            root.left = deleteNode(root.left, key);
        }else if(key > root.value){
            root.right = deleteNode(root.right, key)
        }else{
            if(root.left == null)
                return root.right;
            if(root.right == null)
                return root.left;
            var minNode: TreeNode = findMin(root.right, key);
            root.value = minNode.value;
            root.right = deleteNode(root.right, root.value);
        }
        return root;
    }
    
    def findMin(root: TreeNode, key: Int): TreeNode = {
        var node = root;
        while(node.left != null){
            node = node.left;
        }
        return node;
    }
}