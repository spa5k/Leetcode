# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True

        def symmtery(right, left):
            if right is None and left is None:
                return True
            if left is None or right is None:
                return False
            if left.val != right.val:
                return False
            out = symmtery(left.left, right.right)
            inside = symmtery(left.right, right.left)
            return out and inside

        return symmtery(root.right, root.left)