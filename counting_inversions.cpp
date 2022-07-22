//https://www.geeksforgeeks.org/counting-inversions/

class Solution{
    long long int merge(long long arr[],long long int l,long long int r,long long int mid){
        long long int i = l;  //left subarray pointer
        long long int j = mid;    //right subarray pointer
        long long int k = l;   //original subarray pointer
        
        long long int invCount = 0;
        
        while((i<mid) && (j<r)){
            if(arr[i] <= arr[j]){
                arr[k] = arr[i];
                k++;i++;
            }
            else{
                arr[k] = arr[j];
                k++;j++;
                
                //in this condition an element is put at correct position, so count it also
                invCount = invCount + mid-i;
            }
        }
        while(i<mid){
            arr[k++] = arr[i++];
        }
        while(j<r){
            arr[k++] = arr[j++];
        }
        return invCount;
    }
    long long int mergeSort(long long arr[],long long int l,long long int r){
        long long int mid;
        long long int invCount=0;
        if(r>l){
            mid = l + (r-l)/2;
            invCount += mergeSort(arr, l, mid-1);
            invCount += mergeSort(arr, mid, r);
            
            invCount += merge(arr, l, r, mid);
        }
        return invCount;
    }
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr, 0, N-1);
    }
