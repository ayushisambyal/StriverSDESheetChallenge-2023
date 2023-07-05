// GIVING ERROR !
// int isInt(double num){
//   if(num == int(num)) 
//     return int(num);
//   else 
//     return -1;
// }

// int NthRoot(int n, int m) {
//   double low = 1.0, high = double(m);
//   double mid = 0.0, eps = 1e-9;

//   while((high-low) > 1e-6){
//     mid = (low+high) / 2.0;
//     if(pow(mid, n) > m) low = mid;
//     else high = mid;
//   }
//   return isInt(mid);
// }

int NthRoot(int n, int m) {
  for(int i=0; pow(i,n) <= m; i++){
    if(pow(i,n) == m) return i;
  }
  return -1;
}
