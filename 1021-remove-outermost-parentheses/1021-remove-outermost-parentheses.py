class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        open_count = 0
        res = []

        for i in s:
            if i == ")":
                open_count -= 1
            if open_count > 0:
                res.append(i)
            if i == "(":
                open_count += 1
        return "".join(res)