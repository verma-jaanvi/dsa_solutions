class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)  return false;

        map<int,  int> mpp;
        for(int i : hand){
            mpp[i]++;
        }

        for(auto& [val, freq] : mpp){
            if(freq > 0){
                int cnt = freq;
                for(int i = 0; i< groupSize; ++i){
                    if(mpp[val + i] < cnt){
                        return false;
                    }
                    mpp[val + i] -= cnt;
                }
            }
        }
        return true;
    }
};