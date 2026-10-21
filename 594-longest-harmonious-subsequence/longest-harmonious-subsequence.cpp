class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = 1, mini = 0;
        int ans = 0;
        int n = nums.size();
        while(maxi < n){
            int diff = nums[maxi] - nums[mini];
            if(diff == 1)   ans = max(ans, maxi - mini + 1);
            if(diff <= 1)   maxi++;
            else    mini++;

        }
        return ans;
    }
};