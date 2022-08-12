# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def countNodes(self, root: Optional[TreeNode]) -> int:
        def get_tree_height(node):
            if not node:
                # base case
                return 0

            else:
                # general case
                return 1 + get_tree_height(node.left)

        def counting(node):
            h = get_tree_height(node)
            if h == 0:
                return 0
            if (h-1) == get_tree_height(node.right):
                return 2**(h-1) + counting(node.right)
            else:
                return 2**(h-2) + counting(node.left)
        return counting(root)