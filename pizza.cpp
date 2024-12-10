#include <iostream>
using namespace std;

class PizzaParlour {
public:
    const int m = 50;
    int array[50];
    int front = -1;
    int rear = -1;

    bool isFull() {
        return ((front == 0 && rear == m - 1) || (rear == (front - 1) % m));
    }


    bool isEmpty() {
        return (front == -1);
    }

    void placeOrder(int x) {
        if (isFull()) {
            cout << "Sorry, cafe is full. Please wait!" << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % m;
        }

        array[rear] = x;
        cout << "Order " << x << " placed!" << endl;
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "\nNo orders to serve!" << endl;
            return;
        }

        cout << "Order " << array[front] << " served!" << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % m;
        }
    }

    void display() {
        cout << "Current orders: ";

        if (isEmpty()) {
            cout << "-" << endl;
            return;
        }

        int i = front;
        while (i != rear) {
            cout << array[i] << " ";
            i = (i + 1) % m;
        }
        cout << array[rear] << endl;
    }
};

int main() {
    PizzaParlour p;
    int ch, n;
    char ao;

    do {
        cout << "\n----Dashboard----\n";
        cout << "1. Place order\n";
        cout << "2. Serve order\n";
        cout << "3. Display orders\n";
        cout << "4. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                do {
                    cout << "\nEnter the pizza ID: ";
                    cin >> n;
                    p.placeOrder(n);
                    cout << "\nDo you want to place another order (y/n): ";
                    cin >> ao;
                } while (ao == 'y' || ao == 'Y');
                break;
            case 2:
                p.serveOrder();
                break;
            case 3:
                p.display();
                break;
            case 4:
                cout << "Thank you. Do visit again!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }

        if (ch == 1 || ch == 2 || ch == 3) {
            char M;
            cout << "\nDo you want to return to the dashboard (y/n): ";
            cin >> M;
            if (M == 'n' || M == 'N') {
                cout << "Thank you. Do visit again!" << endl;
                break;
            }
        }
    } while (ch != 4);

    return 0;
}
