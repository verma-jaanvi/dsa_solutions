class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        pref = {}
        pref[0] = 1
        sum = 0
        for i in nums:
            sum += i
            if (sum-k) in pref:
                ans += pref[sum - k]
            pref[sum] = pref.get(sum, 0) + 1
        return ans