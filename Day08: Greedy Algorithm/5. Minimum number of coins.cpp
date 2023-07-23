#include <bits/stdc++.h> 

int findMinimumCoins(int amnt) 
{
    int d[] = {1,2,5,10,20,50,100,500,1000};
    int n = 9, cnt = 0;

    for(int i=n-1; i>=0; i--){
        while (amnt >= d[i]){
            amnt -= d[i];
            cnt++;
        }
    }
    return cnt;
}
