class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        ranks = []

        for i, val in enumerate(score):
            heapq.heappush(ranks, (-val, i))
        print(ranks)
        res = [0] * len(score)
        r = 1
        rank = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        while len(ranks) != 0:
            _, i = heapq.heappop(ranks)
            if r <= 3:
                res[i] = rank[r - 1]
            else:
                res[i] = str(r)
            r += 1
        return res