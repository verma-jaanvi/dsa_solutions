class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int cnt = 0;
        for(int i: nums){
            if(!mpp.empty()){
                if(mpp.find(k+i) != mpp.end()){
                    cnt += mpp[k+i];
                }
                if(mpp.find(i-k) != mpp.end()){
                    cnt += mpp[i-k];
                }
            }
            mpp[i]++;
        }
        return cnt;
    }
};