class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        //dynamic window
        int l = 0;
        int ans = INT_MAX;
        for(int l = 0; l<n; ++l){
            for(int r = l; r<n; ++r){
                int orval = 0;
                for(int i = l; i<=r; ++i){
                    orval |= nums[i];
                }
                if(orval >= k){
                    ans = min(ans, r-l+1);
                    
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};