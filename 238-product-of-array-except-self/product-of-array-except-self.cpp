class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int pro = 1;
        for(int i : nums){
            ans.push_back(pro);
            pro *= i;
        }
        pro = 1;
        for(int i = nums.size()-1; i>=0; --i){
            ans[i] *= pro;
            pro *= nums[i];
        }
        return ans;
    }
};