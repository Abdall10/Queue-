#include <iostream>
using namespace std;
// circular queue

#define SIZE 5

int queue[SIZE];

int front = -1;
int rear = -1;

bool isEmpty(); // function to check if the queue is empty
bool isFull(); // function to check if the queue is full

void enqueue(int data); // function to add data to the queue
void dequeue();         // function to remove data from the queue
int peek();             // function to return the front element of the queue
void display();


int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display(); // 10 20 30 40 50 

    enqueue(60);

    dequeue();
    display(); // 20 30 40 50

    enqueue(60);
    display(); // 20 30 40 50 60

    cout<<"peek is: "<<peek()<<endl;


    return 0;
}

bool isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }else{
        return false;
    }
}

bool isFull(){
    if(front == 0 && rear == SIZE -1 ){
        return true;
    }else if(rear == front -1){
        return true;
    }else{
        return false;
    }
}

void enqueue(int data){
    if(isFull()){
      cout<<"Queue is full"<<endl;
    }else{
        if(isEmpty()){
            front = rear = 0;
            queue[rear] = data; // insert data at rear
        }else if(rear == SIZE -1){
             rear = 0;
             queue[rear] = data; // insert data at rear
        }else{
            queue[++rear] = data; // insert data at rear
        }
    }
}

void dequeue(){
    if(isEmpty()){
          cout<<"Queue is empty"<<endl;
    }else{
        if(front == rear){
            front = rear = -1;
        }else if(front == SIZE - 1){
            front = 0;
        }else{
            front++;
        }
    }
}

int peek(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return -1;
    }else{
        return queue[front];
    }
}

void display(){
    if(isEmpty()){
       cout<<"Queue is empty"<<endl;
    }else{
        if(front <= rear){
          for(int i = front; i <= rear; i++){
                cout<< queue[i]<<" \t";
          }
          cout<<endl;
        }else{ // when front > rear
          for(int i = front; i < SIZE; i++){
                cout<< queue[i]<<" \t";
          }
          for(int i = 0; i <= rear; i++){
            cout<< queue[i]<<" \t";
          }
            cout<<endl;
        }
    }
}