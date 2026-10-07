class Solution {
public:
    void fn(int &cnt, vector<int> &nums, long long &mid){
        long long sum = 0;
        for(int i : nums){
            if(sum + i <= mid){
                sum += i;
            }else{
                cnt++;
                sum = i;
            }
        }
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = nums[0], high = 0;
        for(int i : nums){
            low = max(low, 1LL * i);
            high += i;
        }
        int ans = 0, sum = high;
        while(low <= high){
            long long mid = low + (high - low)/2;
            int cnt = 1;
            fn(cnt, nums, mid);
            if(cnt <= k){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }
};