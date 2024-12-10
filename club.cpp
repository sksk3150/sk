#include <iostream>
#include <string>

using namespace std;

// Node structure to hold student information
struct Node {
    string prn;
    string name;
    Node* next;
    Node(string p, string n) : prn(p), name(n), next(nullptr) {}
};

// Function to add a new member at the end of the list
void addMember(Node*& head, string prn, string name) {
    Node* newNode = new Node(prn, name);
    if (head == nullptr) {
        head = newNode; // List is empty, new node becomes the head
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Add new node at the end
    }
}

// Function to delete a member by PRN
void deleteMember(Node*& head, string prn) {
    if (head == nullptr) {
        cout << "The list is empty. Nothing to delete." << endl;
        return;
    }

    // Special case: deleting the first node
    if (head->prn == prn) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = nullptr;
    Node* current = head;

    while (current && current->prn != prn) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Member with PRN " << prn << " not found." << endl;
        return;
    }

    // Deleting the node
    prev->next = current->next;
    delete current;
}

// Function to display all members
void displayMembers(Node* head) {
    if (head == nullptr) {
        cout << "No members in the club." << endl;
        return;
    }

    Node* current = head;
    cout << "Club Members:" << endl;
    while (current) {
        cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
        current = current->next;
    }
}

// Function to count the total number of members
int countMembers(Node* head) {
    int count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

// Main function to create a menu-driven interface
int main() {
    Node* head = nullptr; // Head of the list

    int choice;
    string prn, name;

    bool menu = true;
    while (menu) {
        cout << "\nMenu:\n";
        cout << "1. Add Member\n";
        cout << "2. Delete Member\n";
        cout << "3. Display Members\n";
        cout << "4. Count Members\n";
        cout << "5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter PRN: ";
                cin >> prn;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                addMember(head, prn, name);
                break;
            }
            case 2: {
                cout << "Enter PRN to delete: ";
                cin >> prn;
                deleteMember(head, prn);
                break;
            }
            case 3: {
                displayMembers(head);
                break;
            }
            case 4: {
                cout << "Total members in the list: " << countMembers(head) << endl;
                break;
            }
            case 5:
                menu = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
