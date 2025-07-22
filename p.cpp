#include <iostream>
#include <vector>
using namespace std;

// Step 1: Get Pivot
int getPivot(vector<int>& arr, int n) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e) {
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

// Step 2: Binary Search with Start and End Range
int binarysearch(vector<int>& nums, int start, int end, int target) {
    int mid = start + (end - start) / 2;

    while (start <= end) {
        if (nums[mid] == target) {
            return mid;
        } else if (target > nums[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

// Step 3: Final Search Function
int search(vector<int>& arr, int n, int k) {
    int pivot = getPivot(arr, n);  // ? add semicolon

    if (k >= arr[pivot] && k <= arr[n - 1]) {
        return binarysearch(arr, pivot, n - 1, k);
    } else {
        return binarysearch(arr, 0, pivot - 1, k);
    }
}
