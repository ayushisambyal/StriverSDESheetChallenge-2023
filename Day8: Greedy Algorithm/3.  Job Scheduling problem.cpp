#include <bits/stdc++.h>

bool comparator(vector<int> a, vector<int> b){
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs){
    // finding max of the deadlines
    int n = jobs.size(), maxi=0;
    for(int i=0; i<n; i++){
        maxi = max(maxi, jobs[i][0]);
    }
    // vector for slots 
    vector<bool> slots(maxi, false);
    sort(jobs.begin(), jobs.end(), comparator);
    int prof = 0;
    
    // prof = summation of profit made
    for(int i=0; i<n; i++){
        int dl = jobs[i][0]-1; // deadline day
    
        while(dl >= 0){
        // iterating from deadline max to decreasing
            
            if(slots[dl]== false){ // if slot empty

                slots[dl] = true; // marking true
                prof += jobs[i][1]; // adding profit
                break; // breaking for next ith job
            }
            dl--;
        }
    }
    return prof;
}
