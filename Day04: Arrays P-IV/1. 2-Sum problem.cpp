#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   
   int n = arr.size();
   int left = 0, right = n-1;
   vector<vector<int>> ans;
   sort(arr.begin(), arr.end());

   while (left < right) {
      
      int sum = arr[left] + arr[right];
      if (sum == s) {
      
         int currLeft = left;
         int currRight = right;
         
         // Find all possible pairs with the same sum
         while (left < right && arr[left] == arr[currLeft]) {
            while (left < right && arr[right] == arr[currRight]) {
              ans.push_back({arr[left], arr[right]});
              right--;
            }
            left++;
            right = currRight;
         }
      }
      else if (sum < s) left++;
      else right--;
   }
   return ans;
}
