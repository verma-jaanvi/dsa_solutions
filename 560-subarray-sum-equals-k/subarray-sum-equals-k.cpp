class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> mpp;
        int cnt = 0;
        mpp[0] = 1;
        long long sum = 0;
        for (int i : nums) {
            sum += i;
            auto it = mpp.find( sum - k);
            if (it != mpp.end()) {
                cnt += it->second;
            }
            mpp[sum]++;
        }
        return cnt;
    }
};