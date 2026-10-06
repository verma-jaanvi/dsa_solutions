class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> vec(n, 0);

        for (int i = 0; i < n; ++i) {
            vec[i] = arr[i] - (i + 1);
        }
        
        int low = 0, high = n - 1;
        int ans = n; 
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vec[mid] >= k) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;
            }
        }

        if (ans == 0) {
            return k;
        }

        if (ans == n) {
            return arr.back() + (k - vec[n - 1]);
        }
        return arr[ans - 1] + (k - vec[ans - 1]);
    }
};