class Solution {
public:
    long long countCommas(long long n) {
        long long cnt = 0;
        long long st = 1000;
        long long cm = 1;

        while(st <= n){
            long long en = min(n, st * 1000 -1);
            cnt += (en - st + 1) * cm;

            st *= 1000;
            cm++;
        }

        return cnt;
    }
};