class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, l = 0, ans = 0;
        for(int r = 0; r< nums.size(); ++r){
            sum += nums[r];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }

            if(sum == goal){
                int zero = 0;
                int temp = l;
                while(temp <= r && nums[temp] == 0){
                    zero++;
                    temp++;
                }
                ans += (goal == 0) ? zero : zero + 1;
            }

        }
        return ans;
    }
};