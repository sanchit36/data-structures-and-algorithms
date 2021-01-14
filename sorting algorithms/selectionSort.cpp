#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
  int min_idx;
  for(int i=0;i<n;i++){
    min_idx = i;
    for(int j=i+1;j<n;j++){
      if(arr[j] < arr[min_idx]) 
        min_idx = j;
    }
    int temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
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