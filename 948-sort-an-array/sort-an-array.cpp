class Solution {
public:
    int piv(vector<int>& arr, int low, int high) {
        int p = low + rand() % (high - low + 1);
        swap(arr[low], arr[p]);

        int el = arr[low];
        int i = low, j = high;
        while (i < j) {
            while (arr[i] <= el && i <= high - 1) {
                i++;
            }
            while (arr[j] > el && j >= low + 1) {
                j--;
            }
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        return j;
    }

    void quicksort(vector<int>& arr, int low, int high) {
        if (low >= high)
            return;

        int pos = piv(arr, low, high);
        quicksort(arr, low, pos - 1);
        quicksort(arr, pos + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};