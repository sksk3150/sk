#include <iostream>
using namespace std;
#define MAX 10

class DEqueue {
public:
    int deque[MAX];
    int front = -1;
    int rear = -1;

    bool isFull() {
        return (front == 0 && rear == MAX - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    void insertFront(int element) {
        if (isFull()) {
            cout << "\nOVERFLOW! Cannot Insert." << endl;
        } else if (isEmpty()) {
            front = 0;
            rear = 0;
            deque[front] = element;
            cout << "\nElement " << element << " inserted at the front." << endl;
        } else if (front == 0) {
            front = MAX - 1;
            deque[front] = element;
            cout << "\nElement " << element << " inserted at the front." << endl;
        } else {
            front--;
            deque[front] = element;
            cout << "\nElement " << element << " inserted at the front." << endl;
        }
    }

    void insertRear(int element) {
        if (isFull()) {
            cout << "\nOVERFLOW! Cannot Insert." << endl;
        } else if (isEmpty()) {
            front = 0;
            rear = 0;
            deque[rear] = element;
            cout << "\nElement " << element << " inserted at the rear." << endl;
        } else if (rear == MAX - 1) {
            rear = 0;
            deque[rear] = element;
            cout << "\nElement " << element << " inserted at the rear." << endl;
        } else {
            rear++;
            deque[rear] = element;
            cout << "\nElement " << element << " inserted at the rear." << endl;
        }
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "\nERROR! Queue is Empty." << endl;
        } else {
            cout << "\nElement: " << deque[front] << " has been removed from the Queue" << endl;
            if (front == rear) {
                front = -1;
                rear = -1;
            } else if (front == MAX - 1) {
                front = 0;
            } else {
                front++;
            }
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "\nERROR! Queue is Empty." << endl;
        } else {
            cout << "\nElement: " << deque[rear] << " has been removed from the Queue" << endl;
            if (front == rear) {
                front = -1;
                rear = -1;
            } else if (rear == 0) {
                rear = MAX - 1;
            } else {
                rear--;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "\nQueue is Empty." << endl;
            return;
        }

        cout << "\nDisplaying Queue Contents:" << endl;

        if (front > rear) {
            for (int i = front; i < MAX; i++) {
                cout << deque[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << deque[i] << " ";
            }
        } else {
            for (int i = front; i <= rear; i++) {
                cout << deque[i] << " ";
            }
        }
        cout << endl;
    }
};

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
                cout << "\nTerminating Program..." << endl;
                return 0;

            default:
                cout << "\nINVALID CHOICE!" << endl;
        }
    }
}
