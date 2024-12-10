#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// DEqueue class using a doubly linked list
class DEqueue {
private:
    Node* front;
    Node* rear;

public:
    DEqueue() : front(nullptr), rear(nullptr) {}

    // Check if the DEqueue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Insert an element at the front
    void insertFront(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << "Element " << element << " inserted at the front." << endl;
    }

    // Insert an element at the rear
    void insertRear(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Element " << element << " inserted at the rear." << endl;
    }

    // Delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "ERROR! Queue is Empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Element: " << temp->data << " has been removed from the Queue." << endl;
        if (front == rear) { // Single element in the queue
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }
        delete temp;
    }

    // Delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "ERROR! Queue is Empty." << endl;
            return;
        }
        Node* temp = rear;
        cout << "Element: " << temp->data << " has been removed from the Queue." << endl;
        if (front == rear) { // Single element in the queue
            front = rear = nullptr;
        } else {
            rear = rear->prev;
            rear->next = nullptr;
        }
        delete temp;
    }

    // Display all elements in the DEqueue
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return;
        }
        cout << "Displaying Queue Contents:" << endl;
        Node* current = front;
        while (current!=nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Main function to test the DEqueue class
int main() {
    DEqueue dq;
    int choice, element;

    while (true) {
        cout << "\n---------- MENU ----------" << endl;
        cout << "1. Insert at the Front" << endl;
        cout << "2. Insert at the Rear" << endl;
        cout << "3. Delete at the Front" << endl;
        cout << "4. Delete at the Rear" << endl;
        cout << "5. Display Queue Contents" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert at the front: ";
                cin >> element;
                dq.insertFront(element);
                break;

            case 2:
                cout << "Enter the element to insert at the rear: ";
                cin >> element;
                dq.insertRear(element);
                break;

            case 3:
                dq.deleteFront();
                break;

            case 4:
                dq.deleteRear();
                break;

            case 5:
                dq.display();
                break;

            case 6:
                cout << "Terminating Program..." << endl;
                return 0;

            default:
                cout << "INVALID CHOICE!" << endl;
        }
    }
}
