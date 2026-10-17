class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; ++i){
            int sum = 0;
            for(int j = i; j<n; ++j){
                sum += nums[j];
                if(find(nums.begin() + i, nums.begin() + j + 1, sum) != nums.begin() + j + 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};