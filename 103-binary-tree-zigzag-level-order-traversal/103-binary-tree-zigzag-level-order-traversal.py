# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return root
        q = collections.deque()
        q.append(root)
        res = []
        l_to_r = False
        while q:
            qlen = len(q)
            level = []
            for i in range(qlen):
                current = q.popleft()
                level.append(current.val)
                if current.left:
                    q.append(current.left)
                if current.right:
                    q.append(current.right)
            if l_to_r:
                # reverse the level before appending
                res.append(level[::-1])
            else:
                res.append(level)
            l_to_r = not l_to_r
        return res