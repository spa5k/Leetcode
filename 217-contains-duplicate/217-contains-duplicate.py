class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        num_set=set(nums)
        if len(nums)==len(num_set):
            return False
        else:
            return True