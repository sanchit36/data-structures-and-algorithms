#include <iostream>
using namespace std;

class Queue{
  int size;
  int f;
  int r;
  int* arr;

  public:
  Queue(int s){
    size = s;
    f = r = -1;
    arr = new int [size];
  }

  int isFull(){
    return (r == size - 1)? 1 : 0;
  }

  int isEmpty(){
    return (f == r)? 1 : 0;
  }

  void enquque(int x){
    if(isFull()){
      cout << "Queue is Full\n";
    }
    else{
      r++;
      arr[r] = x;
    }
  }

  int dequeue(){
    int temp = -1;
    if(isEmpty()){
      cout << "Queue is Empty";
    } 
    else{
      f++;
      temp = arr[f];
    }
    return temp;
  }

  void display(){
    for(int i = f+1; i <= r; i++){
      cout << arr[i] << " ";
    }
    cout << "\n";
  }

};

int main(){
  Queue q (5);
  
  q.enquque(10);
  q.enquque(20);
  q.enquque(30);
  q.enquque(40);
  q.enquque(50);
  q.enquque(60);
  q.display();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.display();
  q.dequeue();
  q.dequeue();
  q.dequeue();
  q.display();
  return 0;
}