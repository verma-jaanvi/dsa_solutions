class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        long long l = w[0], r = 0;
        for(int i : w){
            l = max(l, (long long)i);
            r += i;
        }
        int ans = 0;
        while(l <= r){
            long long mid = l + (r - l)/2;
            int cnt = 1, val = 0;
            for(int i= 0; i<w.size(); ++i){
                if(val + w[i] <= mid) {
                    val += w[i];
                }else{
                    cnt++;
                    val = w[i];
                }
            }
            if(cnt <= days){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};