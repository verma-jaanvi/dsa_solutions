class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        queue<int> q;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int zero = q.front();
            q.pop();
            for(int j = 0; j<nums.size(); j++){
                if(zero < j && nums[j] != 0){
                    nums[zero] = nums[j];
                    nums[j] = 0;
                    zero = j;
                }
            }
        }
    }
};