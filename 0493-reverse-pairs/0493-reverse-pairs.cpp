class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; 
        int left = low;      
        int right = mid + 1;   

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int countInversion(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        int count = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > (long long)2 * arr[right]) {
                right++;
            }
            count += (right - (mid + 1));
        }
        return count;
    }

    int mergeSort(vector<int>& arr, int left, int right) {
        int inversion = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            inversion += mergeSort(arr, left, mid);
            inversion += mergeSort(arr, mid + 1, right);
            inversion += countInversion(arr, left, mid, right);
            merge(arr, left, mid, right);
        }
        return inversion;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};