int search(int* arr, int n, int key) {
    int l = 0, h = n-1;
    
    while(l <= h){
        int m = (l + h) >> 1;
        if(arr[m] == key) return m;

        // if left is sorted
        if(arr[l] <= arr[m]){
            if(key >= arr[l] && key <= arr[m]){
                h = m-1;
            }
            else l = m+1;
        }
        // if left is not sorted
        else{
            if(key >= arr[m] && key <= arr[h]){
                l = m+1;
            }
            else h = m-1;
        }
    }
    return -1;
}
