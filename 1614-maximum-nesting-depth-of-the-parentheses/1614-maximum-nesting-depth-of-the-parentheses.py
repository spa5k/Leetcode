class Solution:
    def maxDepth(self, s: str) -> int:
        l_count = 0
        max_depth = 0

        for i in s:
            if i == "(":
                l_count += 1
            elif i == ")":
                l_count -= 1

            max_depth = max(l_count, max_depth)
        return max_depth