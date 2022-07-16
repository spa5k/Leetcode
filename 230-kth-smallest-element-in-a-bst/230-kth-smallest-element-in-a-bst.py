# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        collection = []

        def extract(node):
            if not node:
                return

            extract(node.left)
            collection.append(node.val)
            extract(node.right)

        extract(root)
        return collection[k-1]