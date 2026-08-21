class Solution {
public:
    int brokenCalc(int startValue, int target) {
        //think the opposite; target -> startValue;
        // till target > startValue divide by 1;
        // then add 1 till it goes to startValue;
        int ans = 0;

        while(target > startValue){
            target = target&1 ? target+1 : target/2;
            ans++;
        }
        if(target < startValue){
            ans += startValue - target;
        }
        return ans;
    }
};