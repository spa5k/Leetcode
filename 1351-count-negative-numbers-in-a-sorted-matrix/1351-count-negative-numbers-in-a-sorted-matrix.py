class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0

        for row in grid:
            data = self.findFirstNegativeIndex(row)
            count += data
        return count

    def findFirstNegativeIndex(self, row: List[int]):
        l = 0
        r = len(row)-1
        res=0
        found_negative = False
        while l <= r:
            middle = (l+r)//2

            if row[middle] < 0:
                res += r-middle+1
                r = middle-1
                found_negative = True
            else:
                l = middle+1
        return res