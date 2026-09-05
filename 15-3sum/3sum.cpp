typedef vector<vector<int>> vvi;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vvi ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-2; ++i){
            if(i>0 && nums[i] == nums[i-1])   continue;
            int tar = - nums[i];
            int j = i+1, k = nums.size() - 1;
            while(j < k){
                int sum = nums[j] + nums[k];
                if(sum == tar){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j<k && nums[j+1] == nums[j])    j++;
                    while(k>j && nums[k-1] == nums[k])    k--;
                    j++; k--;
                }
                else if(sum < tar)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};