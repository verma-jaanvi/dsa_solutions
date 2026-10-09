class Solution {
public:
    void fn(int n, vector<int>& arr) {
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) arr.push_back(i);
        }
    }

    bool canRotate(vector<int>& arr, int l, int k) {
        int breaks = 0;

        for (int idx = l; idx < l + k - 1; ++idx) {
            if (arr[idx] > arr[idx + 1]) breaks++;
        }

        if (arr[l + k - 1] > arr[l]) breaks++;

        return breaks <= 1;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> divisors;
        fn(n, divisors);

        int ans = 0;

        for (int k : divisors) {
            bool valid = true;
            int prevMax = INT_MIN;

            for (int l = 0; l < n; l += k) {
                if (!canRotate(nums, l, k)) {
                    valid = false;
                    break;
                }

                int mn = *min_element(nums.begin() + l,
                                      nums.begin() + l + k);
                int mx = *max_element(nums.begin() + l,
                                      nums.begin() + l + k);

                if (prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};