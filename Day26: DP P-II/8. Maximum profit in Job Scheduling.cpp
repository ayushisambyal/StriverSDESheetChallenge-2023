#include <bits/stdc++.h>
using namespace std;

vector<int> jobScheduling(vector<vector<int>>& jobs) {
    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    });

    vector<bool> slot(n, false);
    vector<int> result(2, 0); 

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i][1]) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[0]++;
                result[1] += jobs[i][2];
                break;
            }
        }
    }

    return result;
}
