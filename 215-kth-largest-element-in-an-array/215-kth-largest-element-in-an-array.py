class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        maxHeap = []

        for i in nums:
            if len(maxHeap) == k:
                heapq.heappushpop(maxHeap, i)
            else:
                heapq.heappush(maxHeap, i)
        # print(maxHeap)
        while k < 1:
            heapq.heappop(maxHeap)
        return maxHeap[0]