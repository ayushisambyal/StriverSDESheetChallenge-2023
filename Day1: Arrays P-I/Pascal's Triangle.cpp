#include <bits/stdc++.h>

vector<long long int> genRow(int row){
  
  long long ans = 1;
  vector<long long int> ansRow;
  ansRow.push_back(ans);

  for(int i=2; i<=row; i++){  
    ans = ans*(row-i+1); 
    ans = ans/ (i-1);
    ansRow.push_back(ans);
  }
  return ansRow;
}

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;
  for(int i=1; i<=n; i++){
    // vector<int> temp = genRow(i);
    // no need to use a temp cz it's a arraylist 
    ans.push_back(genRow(i));
  }
  return ans;
}
