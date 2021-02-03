#include<iostream>
using namespace std;

void swap(int *x, int*y){
  int temp=*x;
  *x=*y;
  *y=temp;
}

void selectionSort(int arr[], int n){
  int i,j,k;
  for(i=0;i<n;i++){
    k = i;
    for(j=k=i;j<n;j++){
      if(arr[j] < arr[k]) 
        k = j;
    }
    swap(&arr[i],&arr[k]);
  }
}


int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  selectionSort(arr,n);

  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }
}