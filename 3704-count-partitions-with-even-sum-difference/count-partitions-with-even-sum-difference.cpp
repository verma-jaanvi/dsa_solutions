class Solution {
public:

    int countPartitions(vector<int>& nums) {
        int sum  = 0, n = nums.size();
        for(int i: nums)    sum += i;
        if(sum&1)   return 0;
        return n-1;
    }
};