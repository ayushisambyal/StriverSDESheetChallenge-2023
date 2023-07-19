#include<bits/stdc++.h>
using namespace std;

// Partition function for QuickSelect
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// QuickSelect algorithm to find the Kth largest element
int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivotIndex = partition(arr, left, right);

    if (pivotIndex == k) {
        return arr[pivotIndex];
    } else if (pivotIndex > k) {
        return quickSelect(arr, left, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, right, k);
    }
}

vector<int> kthSmallLarge(vector<int>& arr, int n, int k) {
    vector<int> res;

    if (k > n) {
        return res;
    }

    int kthSmallest = quickSelect(arr, 0, n - 1, k - 1);
    int kthLargest = quickSelect(arr, 0, n - 1, n - k);

    res.push_back(kthSmallest);
    res.push_back(kthLargest);

    return res;
}
