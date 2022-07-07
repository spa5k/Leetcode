# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not subRoot:
            return True
        if not root:
            return False

        if self.isSameTree(root, subRoot):
            return True
        right = self.isSubtree(root.left, subRoot)
        if right:
            return True
        left = self.isSubtree(root.right, subRoot)
        if left:
            return True
        return False

    def isSameTree(self, s, t):
        if not s and not t:
            return True
        if s and t and s.val == t.val:
            right = self.isSameTree(s.left, t.left
                                    )
            left = self.isSameTree(s.right, t.right)
            return right and left
        return False