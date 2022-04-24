class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        heaper = []

        for i in nums:
            heapq.heappush(heaper, (-i))

        num1 = -heapq.heappop(heaper)
        num2 = -heapq.heappop(heaper)

        return (num1 - 1) * (num2 - 1)