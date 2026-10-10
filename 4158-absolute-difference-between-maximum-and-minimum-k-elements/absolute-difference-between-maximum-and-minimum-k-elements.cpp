class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int smsum = 0, larsum = 0;

        int n = nums.size();
        for(int i = 0; i<k; ++i){
            smsum += nums[i];
            larsum += nums[n-i-1];
        }
        
        return abs(larsum - smsum);
    }
};