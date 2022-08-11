# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        def dfs(root, current_sum):
            if not root:
                return 0
            current_sum = current_sum*10 + root.val
            if not root.left and not root.right:
                return current_sum
            else:
                return dfs(root.left, current_sum) + dfs(root.right, current_sum)
        return dfs(root, 0)