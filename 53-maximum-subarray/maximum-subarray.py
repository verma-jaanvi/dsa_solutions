class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum = -1e9
        curr = 0
        for i in nums:
            curr += i
            sum = max(sum, curr)
            if curr < 0:
                curr = 0
        return sum