# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        q = collections.deque()
        q.append(root)
        ans = []
        while q:
            temp = q.popleft()
            if temp.left:
                ans += self.postorderTraversal(temp.left)
            if temp.right:
                ans += self.postorderTraversal(temp.right)
            ans.append(temp.val)
        return ans