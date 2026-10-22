class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // window size? - y-x <= x;
        int l = 0, r = 0;
        int ans = 0;
        while(r < n){
            while(nums[r]- nums[l] > nums[l]){
                l++;
                // r = l;
                // continue;
            }
            for(int i = l; i<=r; ++i){
                ans = max(ans, (nums[r] ^ nums[i]));

            }
            r++;
        }
        return ans;
    }
};