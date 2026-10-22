class Solution {
public:
    bool fn(int l, int r, vector<int> &nums, int &t){
        if(nums[l] % 2 != 0)    return false;
        for(int i = l; i< r; ++i){
            if(nums[i]> t || nums[i+1] > t || nums[i] % 2 == nums[i+1] % 2)    return false;
        }
        if(nums[r] > t) return false;
        return true;
    }

    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 0;
        int ans = 0;
        for(int r = 0; r<n; ++r){
            if(fn(l, r, nums, threshold)){
                ans = max(ans, r-l+1);
            }else{
                while(l<=r && !fn(l, r, nums, threshold)){
                    l++;
                }
            }
        }
        return ans;
    }
};