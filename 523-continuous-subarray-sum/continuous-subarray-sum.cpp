class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        int sum = 0;

        for(int i=0; i<n; ++i){
            sum += nums[i];
            if(mpp.count(sum%k)){
                int l = mpp[sum%k];
                if(i - l >= 2)  return true;
            }else{
                mpp[sum%k] = i;
            }
        }
        return false;
    }
};