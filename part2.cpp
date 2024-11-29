#include <iostream>
using namespace std;
// SIMPLE QUEUE
#define SIZE 5
int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value);
void dequeue();
int peek();
void display();



int main() {
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);

    display(); // 5 10 15 20
    dequeue();

    display(); // 10 15 20

    cout<< "peek = " << peek() << endl;


    return 0;
}

// function to add an element
void enqueue(int value){
   if(rear != SIZE-1){   // if queue is no't full
      if( front == -1 && rear == -1){  // if queue is empty
        front++;    
        queue[++rear] = value;
      }else{
        queue[++rear] = value;
      }
   }else{
    cout<<"Queue is full"<<endl;
   }
}

// function to remove an element
void dequeue(){
    if( front != -1 && rear != -1 && front <= rear){  
        front++;
    }else{
        cout<<"Queue is empty"<<endl;
    }
}

int peek(){
    if( front != -1 && rear != -1 && front <= rear){  
        return queue[front]; 
    }else{
        cout<<"Queue is empty"<<endl;
        return -1;
    }
}

void display(){
    if(front != -1 && rear != -1 && front <= rear){
        for( int i = front; i <= rear; i++){        
             cout<<queue[i]<<"\t";
        }
        cout<<endl;
    }else{
        cout<<"Queue is empty."<<endl;
    }
}



//335094