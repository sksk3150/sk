#include <iostream>
#include <string>
using namespace std;
#define SIZE 10

struct Job {
    int id;
    string name;
};

class JobQueue {
public:
    Job jobArray[SIZE];
    int front = -1;
    int rear = -1;

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    void addJob(int id, string name) {
        if (isFull()) {
            cout << "Queue is OVERFLOW" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        jobArray[rear].id = id;
        jobArray[rear].name = name;
        cout << "Job added: ID=" << id << ", Name=" << name << endl;
    }

    void deleteJob() {
        if (isEmpty()) {
            cout << "Queue is UNDERFLOW" << endl;
            return;
        }
        cout << "Job deleted: ID=" << jobArray[front].id << ", Name=" << jobArray[front].name << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty, nothing to display" << endl;
            return;
        }
        cout << "Jobs in the queue: ";
        for (int i = front; i <= rear; i++) {
            cout << "[" << jobArray[i].id << ": " << jobArray[i].name << "] ";
        }
        cout << endl;
    }
};

int main() {
    JobQueue jobQueue;
    int menuOption = 1; // Control flag for menu
    int jobId;
    string jobName;

    while (menuOption) {
        cout << "\nMenu:\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Job ID: ";
                cin >> jobId;
                cout << "Enter Job Name: ";
                cin.ignore(); // To handle newline character after integer input
                getline(cin, jobName);
                jobQueue.addJob(jobId, jobName);
                break;
            case 2:
                jobQueue.deleteJob();
                break;
            case 3:
                jobQueue.displayQueue();
                break;
            case 4:
                menuOption = 0; // Exit the loop
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
