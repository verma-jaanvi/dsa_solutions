class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1)  return 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = k-1;
        int ans = INT_MAX;
        while(r<n){
            ans = min(ans, nums[r] - nums[l]);
            r++;
            l++;
        }
        return ans;
    }
};