#include <iostream>
#include <string>

using namespace std;
// queue Linked List implementation { int && String}
struct Node {
    int data;
    string name;
    Node* next;
};

Node* front, *rear = NULL;

void enqueue(int value, string name);
void dequeue();
int peek();
void display();

int main() {
    cout<<"The old data \n";
    enqueue(1, "Adam");
    enqueue(2, "Alice");
    enqueue(3, "Bob");
    enqueue(4, "David");
    enqueue(5, "Eve");
    display();
    cout << "peek is ID: " << peek() << endl;
    dequeue(); // Remove the first element
    cout<<"Remove the first item and display the new data: "<<endl;
    enqueue(6, "Frank");
    display();
    cout << "peek is ID: " << peek() << endl;

    return 0;
}

void enqueue(int value, string name) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->name = name;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (rear == NULL) {
        cout << "Queue is empty" << endl;
    } else if (front == rear) {
        Node* ptr = front;
        front = rear = NULL;
        delete ptr;
    } else {
        Node* ptr = front;
        front = front->next;
        delete ptr;
    }
}

int peek() {
    if (rear == NULL) {
        cout << "Queue is empty" << endl;
        return -1;
    } else {
        return front->data;
    }
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty" << endl;
    } else {
        Node* current = front;
        while (current != NULL) {
            cout << current->data << "- " << current->name << endl;
            current = current->next;
        }
    }
}