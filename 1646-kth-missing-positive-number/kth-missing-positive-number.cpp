class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int prev = 1;
        vector<int> vec(n, 0);
        for(int i= 0; i < n; ++i){
            vec[i] = arr[i] - (i + 1);
        }

        int low = 0, high = n -1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(vec[mid] < k){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        if (ans == -1) {
            return k;
        }

        // int res = arr[ans];

        return arr[ans] + (k - vec[ans]);
    }
};