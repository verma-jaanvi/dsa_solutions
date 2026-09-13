class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0, odd = 0, ans = 0;
        for(int r = 0; r<nums.size(); ++r){
            if(nums[r]&1){
                odd++;
                // even = 0;
            }
            while(odd > k){
                if(nums[l]&1)   odd--;
                l++;
            }
            if(odd == k){
                int even = 0;
                int temp = l;
                while(temp <= r && !(nums[temp]&1)){
                    even++; temp++;
                }
                temp = r+1;
                
                ans += even + 1;
            }
            
        }
        return ans;
    }
};