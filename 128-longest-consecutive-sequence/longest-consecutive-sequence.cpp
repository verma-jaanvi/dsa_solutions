class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> vec(nums.begin(), nums.end());
        int ans = 0;
        for(int i : vec){
            if(vec.find(i-1) == vec.end()){
                int curr = 1, val = i;
                while(vec.find(val+1) != vec.end()){
                    curr++;
                    val += 1;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};