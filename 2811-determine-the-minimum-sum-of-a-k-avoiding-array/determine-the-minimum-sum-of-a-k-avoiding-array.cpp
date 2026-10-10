class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> arr;
        int sum = 0;
        int val = 1, idx = 0;
        while(idx < n){
            if(find(arr.begin(), arr.end(), k - val) == arr.end()){
                arr.push_back(val);
                sum+=val;
                
                idx++;
            }
            val++;
        }
        return sum;
    }
};