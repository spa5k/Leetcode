class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        result = []
        for val in nums1:
            res, pos = self.search(val, nums2)
            if res == True:
                del nums2[pos]
                result.append(val)
        return result

    def search(self, val, a):
        a.sort()
        l = 0
        h = len(a)-1
        while l <= h:
            mid = (l + h) // 2
            if a[mid] == val:
                return True, mid
            elif a[mid] < val:
                l = mid + 1
            else:
                h = mid - 1
        return False, -1