class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX, maxi = INT_MIN, currmin = 0, currmax = 0, totalsum = 0;
        for(int i : nums){
            currmax = max(currmax+i, i);
            currmin = min(currmin+i, i);
            totalsum += i;
            maxi = max(maxi, currmax);
            mini = min(mini, currmin);
        }
        if(maxi < 0)    return maxi;
        return max(maxi, totalsum - mini);

    }
};