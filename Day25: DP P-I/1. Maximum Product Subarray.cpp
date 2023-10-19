int maximumProduct(vector<int> &arr, int n)
{
    int ans=INT_MIN;
    int pre = 1, suff = 1;

    for(int i=0; i<n; i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;

        pre = pre * arr[i];
        suff = suff * arr[n-i-1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}


// METHOD 2 - variation of Kadane's algo

int maximumProduct(vector<int> &arr, int n)
{
    int ans=INT_MIN;
    for(int i=0; i<n; i++){
        ans=max(ans, arr[i]);
    }
    int curmx=1, curmn=1;
    for(auto i : arr){
        if(i<0){
            int temp= curmx;
            curmx=max(curmn*i, i);
            curmn=min(temp*i, i);
        }
        else{
            curmn=min(curmn*i, i);
            curmx=max(curmx*i, i);
        }
        ans=max(ans, curmx);
    }
    return ans;
}
