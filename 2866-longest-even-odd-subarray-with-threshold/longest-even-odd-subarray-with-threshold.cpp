class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 0;
        int ans = 0;
        int r = 0;
        while(r<n){
            if(nums[r] > threshold || nums[l]%2 != 0){
                r++;
                l = r;
                continue;
            }
            if(r > l && nums[r] %2 == nums[r-1]%2){
                l = r;
                continue;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};