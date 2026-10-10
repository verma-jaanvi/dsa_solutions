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

        int pro = 1;
        while(!heap.empty()){
            if((long long)heap.top() * pro > 1e9 + 7)  
                pro = (1LL * pro * heap.top()) % 1000000007;
            else
                pro *= heap.top();
            heap.pop();
        }

        return pro;
    }
};