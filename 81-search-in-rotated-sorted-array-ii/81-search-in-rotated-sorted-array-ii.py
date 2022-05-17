class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        l, r = 0, len(nums)-1

        while l <= r:
            m = (l+r)//2

            if nums[m] == target:
                return True

            while l < m and nums[l] == nums[m]:
                l += 1

            # if the first part is ordered.
            if nums[l] <= nums[m]:
                # target is in first half.
                if nums[l] <= target < nums[m]:
                    r = m-1
                else:
                    l = m+1
            else:
                # target is in second half.
                if nums[m] < target <= nums[r]:
                    l = m+1
                else:
                    r = m-1
        return False