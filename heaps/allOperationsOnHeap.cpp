#include <bits/stdc++.h>

using namespace std;

class heap{
    public:
        void swap(int &a, int &b){
            int temp = a;
            a=b;
            b=temp;
        }

        int arr[100];
        int size;
        heap(){
            arr[0] = -1;
            size=0;
        }
        
        void insert(int val){
            size=size+1;
            int index=size;
            //step1 -- insert new node at end
            arr[index] = val;       
            //step2 -- take that node toits correct position
            while(index>1){
                int parent = index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else{
                    return;
                } 
            }
        }
        
        void deleteroot(){
            if(size==0){
                cout<<"Nothing to delete";
                return;
            }
            //step1 -- swap root node with last node in array
            swap(arr[1], arr[size]);   
            //step2 -- remove last node from array(here we reduces arraysize)
            size--;     
            //step3 -- propogate root to its correct position in the heap
            int i=1;
            while(i<size){
                int leftchild = 2*i;
                int rightchild = 2*i+1;
                if(leftchild<size && arr[i]<arr[leftchild]){
                    swap(arr[i], arr[leftchild]);
                    i=leftchild;
                }
                else if(rightchild<size && arr[i]<arr[rightchild]){
                    swap(arr[i], arr[rightchild]);
                    i=rightchild;
                }
                else{
                    return;
                }
            }
        }
        
        void printheap(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    
    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n){
    int size = n;
    while(size>1){
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
    //INSERT AND DELETEROOT ON HEAP
    cout<<"INSERT AND DELETEROOT ON HEAP"<<endl;
    heap h;
    h.insert(60);
    h.insert(50);
    h.insert(50);
    h.insert(40);
    h.insert(55);
    h.insert(30);
    h.insert(20);
    h.insert(70);
    h.printheap();
    h.deleteroot();
    h.printheap();
    cout<<"***********************"<<endl;
    //HEAPIFY ALGORITHM
    cout<<"HEAPIFY ALGORITHM"<<endl;
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
    cout<<"***********************"<<endl;
    //HEAPSORT FUNCTION
    cout<<"HEAPSORT FUNCTION"<<endl;
    n = 5;
    int arr[n+1] = {-1, 70,60,55,45,50};
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr, n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
    return 0;
}
