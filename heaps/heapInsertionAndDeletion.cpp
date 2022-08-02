#include <bits/stdc++.h>

using namespace std;

//IMPLEMENTATION OF MAX HEAP

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


int main()
{
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
    
    return 0;
}
