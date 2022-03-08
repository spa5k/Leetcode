class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        res = 0
        cur = 0
        for n in s:
            if n != ' ':
                cur += 1
                res = cur
            else:
                cur = 0
        return res