#include<iostream>
using namespace std;

void swap(int *x, int*y){
  int temp=*x;
  *x=*y;
  *y=temp;
}

void bubbleSort(int arr[], int n)
{
  int i,j,swapped = 0;
  for(i=0;i<n;i++)
  {
    swapped = 0;
    for(j=0; j<n-i-1; j++)
    {
      if(arr[j]>arr[j+1])
      {
        swap(&arr[j],&arr[j+1]);
        swapped = 1;
      }
    }
    if(swapped == 0)
        break;
  }
}


int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }

  bubbleSort(arr,n);

  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }
}

