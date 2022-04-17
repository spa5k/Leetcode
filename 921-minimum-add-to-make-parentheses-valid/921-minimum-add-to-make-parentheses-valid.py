class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        balance = 0
        right_pending = 0
        for i in s:
            if i == "(":
                balance += 1
                right_pending += 1

            if i == ")" and right_pending > 0:
                balance -= 1
                right_pending -= 1
            elif i == ")":
                balance += 1

        return balance