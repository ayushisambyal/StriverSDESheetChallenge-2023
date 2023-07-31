#include<bits/stdc++.h>

class Kthlargest {
public:

    int k;
    std::priority_queue<int, vector<int>, greater<int>> minHeap;

    Kthlargest(int k, vector<int> &arr) {
        this->k = k;
        for (int num : arr) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int num) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};



