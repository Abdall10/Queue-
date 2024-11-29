#include <iostream>
using namespace std;
// QUEUE Linked List


struct Node {
    int data;
    Node* next;
};

Node* front, *rear = NULL;

void enqueue(int value);
void dequeue();
int peek();
void display();


int main (){
   // Replace {10, 20, 30, 40, 50} with {60, 70, 80, 90, 100} to test the code
   enqueue(10);
   enqueue(20);
   enqueue(30);
   enqueue(40);
   enqueue(50);  
   display();  // 10 	20 	30 	40 	50 
   dequeue();
   display();  // 20 	30 	40 	50
   cout << "peek = " << peek() << endl; // peek is 20
   dequeue();
   dequeue();
   dequeue();
   dequeue();
   dequeue();
   display(); // Queue is empty
   enqueue(60);
   enqueue(70);
   enqueue(80);  
   enqueue(90);
   enqueue(100);
   display(); // 60 	70 	80 	90 	100 
   cout << "peek = " << peek() << endl; // peek = 60
    return 0;
}

void enqueue(int value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (front == NULL){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear= newNode; 
    }
}

void dequeue(){
    if (rear == NULL){
        cout << "Queue is empty" << endl;
    }else if(front == rear){
        Node* ptr= front; // pointer to the first element in queue
        front = rear = NULL;
        delete(ptr);
    }else {  // If there is more than one element in the queue
        Node* ptr= front; 
        front = front->next; // move the front pointer to the next element
        delete(ptr);
    }
}

int peek(){
    if (rear == NULL){
    cout << "Queue is empty" << endl;
    return -1;
    }else{
        return front->data;
    }
}

void display(){
  if(front == NULL){
    cout << "Queue is empty" << endl;
  }else{
    Node* current = front;
    while (current != NULL) {
        cout << current->data << " \t";
        current = current->next;
    }
    cout<<endl;
  }
}



/*

QUEUE: 5 10 15 
                 FRONT                                    REAR                  
     _____      ____________        ____________       ____________
    | NULL|    | Data| NEXT |      | DATA| NEXT |     | Data| Next |
    |     |    | 5   |      |  ->  | 10  |      | ->  | 15  | NULL |
    |_____|    |_____|______|      |_____|______|     |_____|______|
                    
                  current              current            current


 if front == rear then queue is empty
*/             