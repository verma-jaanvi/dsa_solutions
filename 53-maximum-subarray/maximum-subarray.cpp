class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = -1e9, curr = 0;
        for(int i : nums){
            curr += i;
            sum = max(sum, curr);
            if(curr < 0)    curr = 0;
        }
        return sum;
    }
};