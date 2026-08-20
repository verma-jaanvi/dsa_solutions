class Solution {
public:
    int jump(vector<int>& nums) {
        int n= nums.size();
        if(n == 1)  return 0;
        int ans = 0, farthest = 0, currend = 0;;
        for(int i =0; i<n -1 ; ++i){
            farthest = max(farthest , i + nums[i]);
            if(i == currend){
                ans++;
                currend = farthest;
            }
            
        }
        return ans;
    }
};