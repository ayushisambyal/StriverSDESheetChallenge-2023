// Once Row Optimization
#include<bits/stdc++.h>
int maxProfit(vector<int> &val, vector<int> &wt, int n, int maxwt)
{  
    vector<int> prev(maxwt+1,0);
    for(int w = wt[0]; w<=maxwt; w++) prev[w] = val[0];

    for(int i=1; i<n; i++){
        for(int w=maxwt; w>=0; w--){
            int notTake = 0 + prev[w];
			int take = INT_MIN;
            if(wt[i] <= w){
                take = val[i] + prev[w-wt[i]];
            }
            prev[w] = max(take, notTake);
		}
    }
    return prev[maxwt];
}

// Two Row Optimized
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{    
    vector<int> prev(w+1,0), cur(w+1,0);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            int take=0;
            if(weights[i-1] <= j){
                take= prev[j-weights[i-1]] + values[i-1];
            }
            int notTake= prev[j];
            cur[j]=max(take, notTake);
        }
        prev=cur;
    }
    return prev[w];
}
