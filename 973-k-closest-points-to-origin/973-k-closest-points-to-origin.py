class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        # min heap of size k
        minHeap = []

        for x, y in points:
            distance = (x**2) + (y**2)
            minHeap.append([distance, x, y])

        heapq.heapify(minHeap)

        res = []

        while k > 0:
            dist, x, y = heapq.heappop(minHeap)
            res.append([x, y])
            k -= 1
        return res