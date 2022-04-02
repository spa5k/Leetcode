class Solution:
    def validPalindrome(self, s: str) -> bool:
        if s == s[::-1]:
            return True

        l, r = 0, len(s) - 1
        while l <= r:
            if s[l] != s[r]:
                temp2 = s[:r] + s[r + 1 :]
                temp = s[:l] + s[l + 1 :]

                return temp == temp[::-1] or temp2 == temp2[::-1]

            l += 1
            r -= 1
        return False