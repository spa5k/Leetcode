class Solution:
    def isPalindrome(self, s: str) -> bool:
        left = 0
        right = len(s) - 1

        while left < right:

            left_letter = s[left].lower()
            right_letter = s[right].lower()

            if left_letter == " " or not s[left].isalnum():
                left += 1
                continue
            elif right_letter == " " or not s[right].isalnum():
                right -= 1
                continue

            if left_letter == right_letter:
                left += 1
                right -= 1
                continue
            else:
                return False
        return True