class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // queue<int> q;
        int zero = -1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                // q.push(i);
                zero = i;
                break;
            }
        }
        if(zero == -1)  return;
        int r = zero +1;
        while(r<nums.size()){
            if(nums[r] != 0){
                swap(nums[r], nums[zero]);
                zero++;
            }
            r++;
        }
    }
};