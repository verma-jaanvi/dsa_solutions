class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MIN;
        for(int i =0; i<n-2; ++i){
            // for(int j = i+1; j<n-1; ++j){
            //     for(int k=j+1; k<n; ++k){
            //         ans = max(ans, nums[i] * nums[j] * nums[k]);
            //     }
            // }
            if(i >0 && nums[i] == nums[i-1])    continue;
            int j = i+1, k = n-1;
            while(j<k){
                int pro = nums[i] * nums[j] * nums[k];
                if(pro > ans){
                    ans = pro;
                    // while(j<k && nums[j] == nums[j+1])  j++;
                    // while(j<k && nums[k] == nums[k-1])  k--;
                    // k--;
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
};