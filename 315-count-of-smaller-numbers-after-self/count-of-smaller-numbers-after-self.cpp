class Solution {
public:
    void merge(vector<pair<int, int>> &arr, int left, int mid, int right, vector<int> &counts){
        int i = left, j = mid + 1;
        int rightcount = 0;

        vector<pair<int, int>> temp;
        while(i <= mid && j <= right){
            if(arr[j].first < arr[i].first){
                temp.push_back(arr[j]);
                rightcount++;
                j++;
            }else{
                counts[arr[i].second] += rightcount;
                temp.push_back(arr[i]);
                i++;
            }
        }
        while (i <= mid) {
            counts[arr[i].second] += rightcount;
            temp.push_back(arr[i]);
            i++;
        }
        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }
        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }

    void mergeSort(vector<pair<int, int>> &arr, int left, int right, vector<int> &counts ){
        if(left >= right)   return;

        int mid = left + (right - left)/2;
        mergeSort(arr, left, mid, counts);
        mergeSort(arr, mid+1, right, counts);
        merge(arr, left, mid, right, counts);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<pair<int, int>> arr(n);

        for(int i = 0; i<n; ++i){
            arr[i] = {nums[i] , i};
        }

        mergeSort(arr, 0, n-1, counts);
        return counts;
    }
};