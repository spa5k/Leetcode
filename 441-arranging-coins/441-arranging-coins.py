class Solution:
    def arrangeCoins(self, n: int) -> int:
        l, r = 0, n
        while l <= r:
            mid = (l+r)//2
            current = mid*(mid+1)//2
            if current == n:
                return mid
            elif current <= n:
                l = mid+1
            else:
                r = mid-1
        return r