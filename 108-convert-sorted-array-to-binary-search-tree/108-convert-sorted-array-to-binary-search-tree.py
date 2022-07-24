# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        if not nums:
            return None
        mid = len(nums)//2
        root = TreeNode(nums[mid])
        left_side = nums[:mid]
        right_side = nums[mid+1:]
        root.left = self.sortedArrayToBST(left_side)
        root.right = self.sortedArrayToBST(right_side)

        return root