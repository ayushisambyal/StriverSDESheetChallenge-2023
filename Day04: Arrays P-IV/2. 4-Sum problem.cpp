#include <bits/stdc++.h>

string fourSum(vector<int> nums, int target, int n) {
    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        if( i>0 && nums[i] == nums[i-1]) continue;
        // skipping duplicates
        
        for(int j=i+1; j<n; j++){
            if(j != i+1 && nums[j] == nums[j-1]) continue;
            int k=j+1, l=n-1;
            while(k<l){
                long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                if(sum == target){
                    return "Yes";
                    k++; l--;
                    
                    while(k<l && nums[k] == nums[k-1]) k++;
                    while(k<l && nums[l] == nums[l+1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }
    return "No";
}
