class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1, en = 0;
        int n = piles.size();
        for(int i : piles){
            en = max(en, i);
        }
        int ans = 0;
        while(st <= en){
            int mid = st + (en - st)/2;
            int cnt = 0;
            for(int i : piles){
                cnt += ceil((double)i/mid);
                if(cnt > h)    break;
            }
            if(cnt <= h){
                ans = mid;
                en = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return ans;
    }
};