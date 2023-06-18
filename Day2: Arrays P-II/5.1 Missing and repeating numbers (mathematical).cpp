#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &a, int n)
{
	// find val1 = s - sn = x-y
	// find val2 = s2 - s2n = x2 - y2
	
	long long sn = (n * (n+1)) /2;
	long long s2n = (n * (n+1) * (2*n+1)) /6;
	long long int s=0, s2 = 0;

	for(int i=0; i<n; i++){
		s += a[i];
		s2 += (long long)a[i] * (long long)a[i];
	}
	
	long long val1 = s - sn; 
	long long val2 = s2 - s2n;
	// finding val3 = x+y
	long long val3 = val2 / val1;
	
	long long x = (val1 + val3) /2;
	long long y = x - val1;

	return 	{(int)y, (int)x};
}
