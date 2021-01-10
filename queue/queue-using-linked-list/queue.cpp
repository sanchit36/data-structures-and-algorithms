#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

class Queue {
  Node* front, *rear;
  public:
  Queue(){ front=rear=NULL;}
  void enqueue(int x);
  int dequeue();
  int isEmpty();
  void display();
};


void Queue::enqueue(int x){
  Node *t = new Node;
  if(t==NULL){
    cout << "Heap Overflow\n";
    return;
  }
  t->data = x;
  t->next = NULL;
  if(front == NULL){front = rear = t;}
  else{ 
    rear->next = t;
    rear = t;
  }
  cout<<x<<" has been inserted successfully.\n";
}

int Queue::dequeue(){
  int x = -1;
  Node *t=NULL;
  if(front == NULL){
    cout << "Queue is Empty\n";
    return x;
  }
  x = front->data;
  t = front;
  if(front == rear){front = rear = NULL;}
  else{
    front = front->next;
  }
  delete t;
  cout<<x<<" is the dequeued item.\n";
  return x;
}

int Queue::isEmpty(){
  return (front == NULL)? 1 : 0;
}

void Queue::display(){
  Node* t = front;
  while(t){
    cout << t->data << " ";
    t = t->next;
  }
  cout << "\n";
}

int main(){
  Queue q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.display();
  q.dequeue();
  q.dequeue();
  q.display();
  q.dequeue();
  q.dequeue();
  q.display();

  return 0;
}