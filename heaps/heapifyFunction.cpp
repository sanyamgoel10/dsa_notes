#include <bits/stdc++.h>

using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    
    if(left<n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int main()
{
    int n = 5;
    int inparr[6] = {-1, 54, 53, 55, 52, 50};       //because we consider 1st array element as null
          
    for(int i=1;i<=n;i++){
        cout<<inparr[i]<<" ";
    }
    cout<<endl;
    
    for(int i=n/2; i>0; i--){
        heapify(inparr, n, i);
    }
    
    for(int i=1;i<=n;i++){
        cout<<inparr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
