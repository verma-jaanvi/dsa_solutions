class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1)  return nums[0] + k;
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i : nums){
            heap.push(i);
        } 

        while(k > 0){
            int a = heap.top();
            heap.pop();
            // int b = heap.top();
            heap.push(a  + 1);
            k--;
        }

        long long pro = 1;
        long long mod = 1e9 + 7;
        while(!heap.empty()){
            pro = (pro * heap.top()) % mod;
            heap.pop();
        }

        return pro;
    }
};