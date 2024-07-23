#include <bits/stdc++.h>
using namespace std;

void pattern9(int n){
  for(int i=0;i<n;i++){
    for(int j=n-1;j>i;j--){
      cout<<" ";
    }
    cout<<"*";
    for(int j=0;j<i;j++){
      cout<<"**";
    }
    cout<<endl;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        cout<<" ";
    }
    cout<<"*";
    for(int j=n-1;j>i;j--){
        cout<<"**";
    }
    cout<<endl;
  }
}

void pattern10(int n){
  for(int i=0;i<2*n;i++){
    if(i<n){
      for(int j=0;j<=i;j++){
        cout<<"*";
      }
    }else{
      for(int j=i+1;j<2*n;j++){
        cout<<"*";
      }
    }
    
    cout<<endl;
  }
}

void pattern11(int n){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      cout << !((i+j)%2);
    }
    cout<<endl;
  }
}

void pattern18(int n){
  for(int i=0;i<n;i++){
    for(char j=('A'+n-1)-i;j<=('A'+n-1);j++){
      cout<<j;
    }
    cout<<endl;
  }
}

int main() {
  // Patterns
  // https://takeuforward.org/strivers-a2z-dsa-course/must-do-pattern-problems-before-starting-dsa/

  int n = 5;
  
  pattern9(n);
  cout<<endl;
  pattern10(n);
  cout<<endl;
  pattern11(n);
  cout<<endl;
  pattern18(n);
  
  return 0;
}
