#include<bits/stdc++.h>
using namespace std;

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void stlSort(vector<int>& nums){
    sort(nums.begin(), nums.end());
}

void selectionSort(vector<int>& nums){
    int n = nums.size();
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(nums[j]<nums[minIndex]){
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
}

void bubbleSort(vector<int>& nums){
    int n = nums.size();
    for(int i=1;i<n;i++){
        for(int j=0; j<n-i; j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

void optiBubbleSort(vector<int>& nums){
    int n = nums.size();
    for(int i=1;i<n;i++){
        bool flag = false;
        for(int j=0; j<n-i; j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j], nums[j+1]);
                flag = true;
            }
        }
        if(flag == false){
            break;
        }
    }
}

void insertionSort(vector<int>& nums){
    int n = nums.size();
    for(int i=1;i<n;i++){
        int temp = nums[i];
        int j = i-1;
        while(j>=0){
            if(nums[j]>temp){
                nums[j+1] = nums[j];    //shift current element to next index
            }
            else{
                break;
            }
            j--;
        }
        nums[j+1] = temp;
    }
}

void merge(vector<int>& nums, int l, int r){
    int mid = l + (r-l)/2;
    //length of left subarray == mid-l+1
    //length of right subarray == r-mid
    int leftsize = mid-l+1;
    int rightsize = r-mid;

    //create two subarrays for left and right
    vector<int> left(leftsize);
    vector<int> right(rightsize);
    // int *left = new int[leftsize];
    // int *right = new int[rightsize];

    //copy values to left and right subarrays
    for(int i=0;i<leftsize;i++){
        left[i] = nums[l+i];
    }
    for(int i=0;i<rightsize;i++){
        right[i] = nums[mid+1+i];
    }

    //merge both sorted arrays
    int index1 = 0; //left array index
    int index2 = 0; //right array index
    int k = l;      //main array index
    while(index1<leftsize && index2<rightsize){     //put values in main
        if(left[index1] <= right[index2]){
            nums[k] = left[index1];
            k++;
            index1++;
        }
        else{
            nums[k] = right[index2];
            k++;
            index2++;
        }
    }
    //now any of left or right may contain some values
    //hence to remove them, do the following
    while(index1<leftsize){
        nums[k] = left[index1];
        k++;
        index1++;
    }
    while(index2<rightsize){
        nums[k] = right[index2];
        k++;
        index2++;
    }

    //clear the temporary vectors since of no use
    left.clear();
    right.clear();
}
void mergeSort(vector<int>& nums, int l, int r){
    //base case
    if(l>=r){
        return;
    }
    int mid = l + (r-l)/2;

    //left part sort
    mergeSort(nums, l, mid);
    //right part sort
    mergeSort(nums, mid+1, r);
    //merge both parts
    merge(nums, l, r);
}

int partition(vector<int>& nums, int l, int r){
    //choosing 1st element as pivot
    int pivot = nums[l];

    //getting count of elements smaller than pivot element
    int count=0;
    for(int i=l+1; i<=r; i++){
        if(nums[i]<=pivot){
            count++;
        }
    }

    //correct index of the pivot to which it belongs
    int pivotIndex = l+count;
    swap(nums[pivotIndex], nums[l]);

    //applying swap condition on left and right subarray
    int i = l;
    int j = r;
    while(i<pivotIndex && j>pivotIndex){
        while(nums[i]<=pivot){
            i++;
        }
        while(nums[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void quickSort(vector<int> &nums, int l, int r){
    if(l>=r){
        return;
    }

    //get pivot element
    int p = partition(nums, l, r);

    //apply quicksort on left and right subarray
    quickSort(nums, l, p-1);
    quickSort(nums, p+1, r);
}

vector<int> sortArray(vector<int>& nums) {
    stlSort(nums);      //c++ stl sort
    // selectionSort(nums);        //selection sort
    // bubbleSort(nums);       //bubble sort
    // optiBubbleSort(nums);       //optimized bubble sort
    // insertionSort(nums);        //insertion sort
    // mergeSort(nums, 0, nums.size()-1);     //merge sort
    // quickSort(nums, 0, nums.size()-1);     //quick sort

    return nums;
}

int main(){
  vector<int> arr {5,4,3,2,4,5,6,5,4,3,2,1};
  vector<int> ans = sortArray(arr);
  for(auto x : ans){
    cout<<x<<" ";
}
