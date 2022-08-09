"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return root
        q = collections.deque()
        q.append(root)

        while q:
            for i in range(1, len(q)):
                q[i-1].next = q[i]
            q[-1].next = None
            new_level = collections.deque()
            for node in q:
                if node.left:
                    new_level.append(node.left)
                if node.right:
                    new_level.append(node.right)
            q = new_level
        return root