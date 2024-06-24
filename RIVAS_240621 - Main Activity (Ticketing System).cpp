#include <iostream>

using namespace std;


struct Node {
    string studentName;
    Node* next;
};


class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    
    void enqueue(string studentName) {
        Node* newNode = new Node();
        newNode->studentName = studentName;
        newNode->next = nullptr;

        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    
    void dequeue() {
        if (front == nullptr) {
            cout<<"No students waiting for consultation."<<endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

 
    bool isEmpty() {
        return front == nullptr;
    }

   
    void peek() {
        if (front == nullptr) {
            cout<<"No students waiting for consultation."<<endl;
            return;
        }

        cout<<"Student being consulted: "<<front->studentName<<endl;
    }

   
    void display() {
        Node* temp = front;
        while (temp!= nullptr) {
            cout<<temp->studentName<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    Queue consultationQueue;
    
   consultationQueue.enqueue("Arnold Alisangco");
    consultationQueue.enqueue("James Berganio");
    consultationQueue.enqueue("Dave Rivas");
    consultationQueue.enqueue("Ryan Sorera");
    consultationQueue.enqueue("JM Tiongco");

    cout<<"Remaining students in line for consultation:";
    consultationQueue.display();


    while (!consultationQueue.isEmpty()) {
        consultationQueue.peek();
        consultationQueue.dequeue();
        cout<<"Students waiting for consultation: ";
        consultationQueue.display();
    }

    return 0;
}