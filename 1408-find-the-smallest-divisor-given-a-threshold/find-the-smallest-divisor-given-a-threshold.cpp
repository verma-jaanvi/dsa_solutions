class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long high = 0;
        for(int i : nums){
            high += i;
        }
        long long low = 1;
        int ans =0;
        while(low <= high){
            long long mid = low + (high - low)/2;
            int sum = 0;
            for(int i : nums){
                sum += ceil((double)i/mid);
                if(sum > threshold){
                    break;
                }
            }
            if(sum <= threshold){
                ans = mid;
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }
};