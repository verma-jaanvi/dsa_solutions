class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<long long, int> mpp;
        mpp[0] = 1;
        long long sum = 0;
        int cnt =0;
        for(int i : nums){
            sum += i;
            int rem = (sum % k +k)%k;
            if(mpp.count(rem)){
                cnt += mpp[rem];
            }
            mpp[rem]++;
        }
        return cnt;
    }
};