class Solution {
public:
    void mergeSort(int &ans, int l, int r, vector<int> &nums){
        if(l >=r)   return;
        
        int mid = l +(r-l)/2;
        mergeSort(ans, l, mid, nums);
        mergeSort(ans, mid+1, r, nums);
        merge(ans, l, mid, r, nums);

    }

    void merge(int &ans, int l, int mid, int r, vector<int> &nums){
        int j = mid+1;
        for(int i = l ; i<=mid; ++i){
            while(j <= r && nums[i] > 2LL * nums[j]) j++;
            ans += j - (mid+1);
        }
        int i = l;
        j = mid +1;
        vector<int> arr;
        while(i<=mid && j <= r){
            if(nums[i] < nums[j]){
                arr.push_back(nums[i++]);
            }else{
                arr.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            arr.push_back(nums[i++]);
        }
        while(j<=r){
            arr.push_back(nums[j++]);
        }
        for(i = l; i<=r; ++i){
            nums[i] = arr[i-l];
        }
    }

    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergeSort(ans, 0, nums.size()-1, nums);
        return ans;
    }
};