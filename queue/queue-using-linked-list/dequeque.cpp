#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node* prev;
};

class Dequeue{
  public:
  Node* front, * rear;
  Dequeue(){ front = rear = NULL;}

  void push_back(int x);
  void push_front(int x);
  int pop_back();
  int pop_front();
  void display();
};

void Dequeue::push_back(int x){
  Node* t = new Node;
  if(t==NULL){
    cout << "Heap is Full";
    return;
  }
  t->data = x;
  t->next = NULL;
  t->prev = NULL;
  if(front == NULL){front = rear = t;}
  else{
  rear->next = t;
  t->prev = rear;
  rear = t;
  }
  cout<<x<<" has been inserted successfully.\n";
}

void Dequeue::push_front(int x){
  Node* t = new Node;
  if(t==NULL){
    cout << "Heap is Full";
    return;
  }
  t->data = x;
  t->next = NULL;
  t->prev = NULL;
  if(front == NULL){front=rear=t;}
  else{
    t->next = front;
    front->prev = t;
    front = t;
  }
  cout<<x<<" has been inserted successfully.\n";
}

int Dequeue::pop_front(){
  int x = -1;
  Node* p = NULL;

  if(front==NULL){
    cout << "Queue is Empty.\n";
  }
  else{
    x = front->data;
    p = front;
    front = front->next;
    delete p;
    cout<<x<<" is the dequeued item.\n";
  }
  return x;
}

int Dequeue::pop_back(){
  int x=-1;
  Node* p = NULL;

  if(front==NULL){
    cout << "Queue is Empty.\n";
  }
  else{
    x = rear->data;
    p = rear;
    if(front->next == NULL){rear = NULL; front=NULL;}
    else{
      rear = rear->prev;
      rear->next = NULL;
    }
    delete p;
    cout<<x<<" is the dequeued item.\n";
  }
  return x;
}

void Dequeue::display(){
  Node* t = front;
  while(t){
    cout << t->data << " ";
    t = t->next;
  }
  cout << "\n";
}

int main(){
  Dequeue q;
  q.push_back(10);
  q.push_back(20);
  q.display();
  q.push_front(30);
  q.push_front(50);
  q.push_back(60);
  q.display();
  q.pop_front();
  q.pop_front();
  q.pop_back();
  q.pop_back();
  q.pop_back();
  q.display();
  return 0;
}