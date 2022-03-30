class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n, m = len(s1), len(s2)

        if n > m:
            return False

        target_hash = sum(hash(char) for char in s1)
        cur_hash = sum(hash(char) for char in s2[:n])

        if cur_hash == target_hash:
            return True

        # sliding window
        for right in range(n, m):

            # remove the pass char and add the new char
            left = right - n
            cur_hash += hash(s2[right]) - hash(s2[left])

            if cur_hash == target_hash:
                return True

        return False