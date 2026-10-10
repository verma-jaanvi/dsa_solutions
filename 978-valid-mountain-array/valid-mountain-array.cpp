class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3)   return false;
        int idx = 0;
        while(idx < n-1 && arr[idx] < arr[idx+1]){
            idx++;
        }

        if(idx == 0 || idx == n-1)  return false;

        while(idx < n-1 && arr[idx] > arr[idx + 1]){
            idx++;
        }

        return idx == n-1;
    }
};