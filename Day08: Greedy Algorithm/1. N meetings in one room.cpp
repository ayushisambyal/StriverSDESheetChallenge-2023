#include <bits/stdc++.h> 

// create a structure for storing meeting 
struct meet{
    int start;
    int end;
    int pos;
};

// comparator to sort as per the end time
bool comparator(struct meet m1, struct meet m2){
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    // when end time is equal - then check for position/ idx
    else if(m1.pos < m2.pos) return true;
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n= start.size();
    // create a struct meet
    struct meet meet[n];
    // insert the data in meet
    for(int i=0; i<n; i++){
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i+1;
    }
    // sort as per end time
    sort(meet, meet+n, comparator);

    // ds for storing meeting.pos 
    vector<int> pos;
    int limit = meet[0].end;
    pos.push_back(meet[0].pos);
    
    for(int i=1; i<n; i++){
        if(meet[i].start > limit){
            limit = meet[i].end;
            pos.push_back(meet[i].pos);
        }
    }
    return pos;
}
