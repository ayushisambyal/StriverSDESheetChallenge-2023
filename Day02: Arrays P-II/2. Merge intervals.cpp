#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++){
        // creating a new interval
        if(ans.empty() || intervals[i][0] > ans.back()[1])
            ans.push_back(intervals[i]);
        else
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
    }
    return ans;
}
