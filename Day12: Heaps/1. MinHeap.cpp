#include <bits/stdc++.h> 
using namespace std;

void heapify(vector<int>& heap, int n, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(heap[idx], heap[smallest]);
        heapify(heap, n, smallest);
    }
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> result;

    vector<int> heap;
    for (int i = 0; i < n; i++) {
        int type = q[i][0];
        if (type == 0) {
            int x = q[i][1];
            heap.push_back(x);
            int idx = heap.size() - 1;
            while (idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
                swap(heap[idx], heap[(idx - 1) / 2]);
                idx = (idx - 1) / 2;
            }
        } 
        else if (type == 1) {
            if (!heap.empty()) {
                result.push_back(heap[0]);
                swap(heap[0], heap[heap.size() - 1]);
                heap.pop_back();
                heapify(heap, heap.size(), 0);
            }
        }
    }

    return result;
}
