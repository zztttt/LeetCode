# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        cur = [root]
        next = []
        data = []
        ret = []
        
        while len(cur) > 0:
            for node in cur:
                data.append(node.val)
                if node.left is not None:
                    next.append(node.left)
                if node.right is not None:
                    next.append(node.right)
            ret.append(data.copy())
            cur = next
            next = []
            data.clear()
        return ret
            
            