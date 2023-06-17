#include <bits/stdc++.h> 

void sort012(int *a, int n)
{
   int low=0, mid=0, high=n-1;

   // while unsorted
   while (mid <= high){
      
      if(a[mid] == 0){
         swap(a[low], a[mid]);
         low++;mid++;
      }
      else if(a[mid] == 1){
         mid++;
      }
      else{
         swap(a[mid], a[high]);
         high--;
      }
   }
}
