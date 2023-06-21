#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  int n = arr.size();
  map<int, int> mp;
  int sum = 0;
  int maxlen = 0;

  for(int i=0; i<n; i++){
    sum += arr[i];
    if(sum == 0){
      maxlen = max(maxlen, i+1);
    }
    else if(mp.find(sum) != mp.end()){
      maxlen = max(maxlen, i-mp[sum]);
    }
    else mp[sum] = i;
  }
  return maxlen;
}
