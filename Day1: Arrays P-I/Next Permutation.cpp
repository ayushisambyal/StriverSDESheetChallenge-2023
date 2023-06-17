#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &a, int n)
{
    int ind = -1;

    // finding the break point 
    for(int i=n-2; i>=0; i--){
        if(a[i] < a[i+1]){
            ind = i;
            break;
        }
    }

    // base case - if it's the last permutation, just reverse to get the 1st one
    if(ind == -1){
        reverse(a.begin(), a.end());
        return a;
    }

    // swapping with the slightly higher no.
    for(int i=n-1; i>=ind; i--){
        if(a[i] > a[ind]){
            swap(a[i], a[ind]);
            break;
        }
    }

    // reversing the rest of the element on the LHS of break pt. to sort them
    reverse(a.begin()+ind+1, a.end());
    return a;
}
