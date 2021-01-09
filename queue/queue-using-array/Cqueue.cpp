#include <iostream>
using namespace std;

class Cqueue {
  private:
  int size;
  int f;
  int r;
  int* arr;

  public:
  Cqueue(int s){
    size = s;
    f = r = -1;
    arr = new int [size];
  }

  int isEmpty(){
    return (f == -1 && r == -1)? 1 : 0;
  }

  int isFull(){
    return ((r + 1) % size == f)? 1 : 0;
  }

  void enquque(int x){
    if(isFull()){
      cout << "Queue is Full\n";
      return;
    }
    if(f == -1 && r == -1){
      f = 0;
      r = 0; 
    }else{
      r = (r+1) % size;
    }
    arr[r] = x;
  }

  int dequeue(){
    int temp = -1;
    if(isEmpty()){
      cout << "Queue is Empty\n";
    }
    else{
      temp = arr[f];
      if(f % size == r){
        r = -1; f = -1;
      }
      else{
        f = (f+1) % size;
      }
    }
    return temp;
  }

  void display(){
    if(isEmpty()) return;
    int i;
    for(i=f; i!=r; i=(i+1)%size){
      cout << arr[i] << " ";
    }
    cout << arr[i] << "\n";
  }
};

int main() {
  Cqueue q (5);

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
  q.enquque(101);
  q.display();
  q.dequeue();
  q.dequeue();
  q.display();
  q.dequeue();
  q.dequeue();
  q.display();
  q.enquque(1);
  q.display();
  return 0;
}