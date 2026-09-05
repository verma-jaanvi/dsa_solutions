class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        ans = []
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:  continue
            j = i+1
            k = len(nums) -1
            tar = -nums[i]
            while j < k:
                sum = nums[j] + nums[k]
                if sum == tar:
                    ans.append([nums[i], nums[j], nums[k]])
                    while j < k and nums[j+1] == nums[j]:
                        j +=1
                    while j < k and nums[k-1] == nums[k]:
                        k -= 1
                    j +=1
                    k -=1
                elif sum < tar:
                    j +=1
                else:
                    k -= 1
            
        return ans
