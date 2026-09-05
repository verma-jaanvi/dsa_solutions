class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        mpp = {}
        for i in nums:
            mpp[i] = mpp.get(i, 0) + 1
        ans = []
        for k in mpp:
            if mpp[k] > 1:
                ans.append(k)
        return ans