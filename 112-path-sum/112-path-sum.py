# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False

        def check_sum(node, current_sum):
            if not node:
                return
            current = node.val+current_sum
            if not node.left and not node.right:
                # its a leaf node
                if current == targetSum:
                    return True
            else:
                if node.left:
                    left = check_sum(node.left, current)
                    if left:
                        return True
                if node.right:
                    right = check_sum(node.right, current)
                    if right:
                        return True
        res = check_sum(root, 0)
        if res:
            return True
        return False