class Solution:
    def longestSubsequence(self, nums):
        x = 0
        for v in nums:
            x ^= v
        if x != 0:
            return len(nums)
        for v in nums:
            if v != 0:
                return len(nums) - 1
        return 0