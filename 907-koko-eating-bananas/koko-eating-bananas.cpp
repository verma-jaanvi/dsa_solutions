class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = piles[0];
        for(int i : piles){
            r = max(r, i);
        }
        int ans = 0;
        while( l  <= r){
            int mid = l + (r-l)/2;
            int cnt = 0;
            for(int i : piles){
                cnt += ceil((double)i/mid);

                if(cnt > h) break;
            }

            if(cnt <= h){
                ans = mid;
                r = mid -1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};