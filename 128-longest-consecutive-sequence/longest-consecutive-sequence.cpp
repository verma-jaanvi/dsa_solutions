class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;

        set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(int num : st){
            if(st.find(num-1) == st.end()){
                int cnt = 1;
                while(st.find(num++) != st.end()){
                    cnt++;
                }
                ans= max(ans, cnt);
            }
        }
        return ans -1 ;
    }
};