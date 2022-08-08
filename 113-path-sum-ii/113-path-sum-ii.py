# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        answer = []

        def dfs(node, current_path, target):
            if not node:
                return

            target = target-node.val
            if (not node.left) and not node.right and target == 0:
                # this is a suitable leaf node.
                current_path.append(node.val)
                answer.append(current_path)
                return
            # if not leaf node and not result
            dfs(node.left, current_path+[node.val], target)
            dfs(node.right, current_path+[node.val], target)
            return
        dfs(root, [], targetSum)
        return answer