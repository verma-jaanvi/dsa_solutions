class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // if(n==1)    return 0;
        // if(n==2)    return nums[0] > nums[1] ? 0 : 1;
        int low = 0, high = n-1;
        while(low< high){
            int mid = low +(high - low)/2;
            // if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            //     return mid;
            // }
            if(nums[mid] < nums[mid +1 ]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};