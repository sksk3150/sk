#include <iostream>
#include <string>
using namespace std;

// Node structure for a singly linked list
struct Node {
    int PRN;
    string name;
    Node* next;

    Node(int prn, string nm) : PRN(prn), name(nm), next(nullptr) {}
};

class PinnacleClub {
private:
    Node* head; // Pointer to the president
    Node* tail; // Pointer to the secretary

public:
    PinnacleClub() : head(nullptr), tail(nullptr) {}

    // Add President
    void addPresident(int prn, string name) {
        Node* newNode = new Node(prn, name);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = head; // If the list was empty, tail is also the president
        }
        cout << "President added: " << name << endl;
    }

    // Add Secretary
    void addSecretary(int prn, string name) {
        Node* newNode = new Node(prn, name);
        if (tail == nullptr) {
            head = tail = newNode; // If the list was empty
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "Secretary added: " << name << endl;
    }

    // Add Member
    void addMember(int prn, string name) {
        if (head == nullptr) {
            cout << "Add a president first before adding members." << endl;
            return;
        }
        Node* newNode = new Node(prn, name);
        newNode->next = head->next; // Insert after president
        head->next = newNode;
        cout << "Member added: " << name << endl;
    }

    // Delete a member
    void deleteMember(int prn) {
        if (head == nullptr) {
            cout << "The list is empty. No member to delete." << endl;
            return;
        }

        if (head->PRN == prn) {
            // Deleting the president
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "President deleted." << endl;
            if (head == nullptr) tail = nullptr; // If the list is now empty
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr && curr->PRN != prn) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Member with PRN " << prn << " not found." << endl;
        } else {
            prev->next = curr->next;
            if (curr == tail) {
                // Deleting the secretary
                tail = prev;
            }
            delete curr;
            cout << "Member with PRN " << prn << " deleted." << endl;
        }
    }

    // Compute total number of members
    int totalMembers() {
        int count = 0;
        Node* curr = head;

        while (curr != nullptr) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    // Display members
    void displayMembers() {
        if (head == nullptr) {
            cout << "The club has no members." << endl;
            return;
        }

        cout << "Club Members:" << endl;
        Node* curr = head;
        while (curr != nullptr) {
            cout << "PRN: " << curr->PRN << ", Name: " << curr->name << endl;
            curr = curr->next;
        }
    }
};

int main() {
    PinnacleClub club;
    int choice, prn;
    string name;

    while (true) {
        cout << "\n--- Pinnacle Club Menu ---\n";
        cout << "1. Add President\n";
        cout << "2. Add Secretary\n";
        cout << "3. Add Member\n";
        cout << "4. Delete Member\n";
        cout << "5. Display Members\n";
        cout << "6. Total Members\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter PRN: ";
                cin >> prn;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                club.addPresident(prn, name);
                break;

            case 2:
                cout << "Enter PRN: ";
                cin >> prn;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                club.addSecretary(prn, name);
                break;

            case 3:
                cout << "Enter PRN: ";
                cin >> prn;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                club.addMember(prn, name);
                break;

            case 4:
                cout << "Enter PRN of Member to delete: ";
                cin >> prn;
                club.deleteMember(prn);
                break;

            case 5:
                club.displayMembers();
                break;

            case 6:
                cout << "Total Members: " << club.totalMembers() << endl;
                break;

            case 7:
                cout << "Exiting Program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}