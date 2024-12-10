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
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a member by PRN
void deleteMember(Node*& head, string prn) {
    if (!head) {
        cout << "The list is empty. Nothing to delete." << endl;
        return;
    }

    // Special case: deleting the president or the secretary (first node)
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

    if (!current) {
        cout << "Member with PRN " << prn << " not found." << endl;
        return;
    }

    // Deleting the node
    prev->next = current->next;
    delete current;
}

// Function to display all members
void displayMembers(Node* head) {
    if (!head) {
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

// Function to concatenate two linked lists
Node* concatenateLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* temp = head1;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = head2;

    return head1;
}

// Main function to create a menu-driven interface
int main() {
    Node* head1 = nullptr;  // Head for List 1
    Node* head2 = nullptr;  // Head for List 2
    int choice, position;
    string prn, name;

    bool menu = true;
    while (menu) {
        cout << "\nMenu:\n";
        cout << "1. Add Member\n";
        cout << "2. Delete Member\n";
        cout << "3. Display Members\n";
        cout << "4. Count Members\n";
        cout << "5. Merge Lists\n";
        cout << "6. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                int listChoice;
                cout << "\nSelect list to add member:\n";
                cout << "1. List 1\n";
                cout << "2. List 2\n";
                cin >> listChoice;
                if (listChoice == 1 || listChoice == 2) {
                    cout << "Enter PRN: ";
                    cin >> prn;
                    cout << "Enter Name: ";
                    cin.ignore();
                    getline(cin, name);

                    if (listChoice == 1) {
                        addMember(head1, prn, name);
                    } else {
                        addMember(head2, prn, name);
                    }
                } else {
                    cout << "Invalid choice. Try again." << endl;
                }
                break;
            }
            case 2: {
                int listChoice;
                cout << "\nSelect list to delete member:\n";
                cout << "1. List 1\n";
                cout << "2. List 2\n";
                cin >> listChoice;
                if (listChoice == 1 || listChoice == 2) {
                    cout << "Enter PRN to delete: ";
                    cin >> prn;

                    if (listChoice == 1) {
                        deleteMember(head1, prn);
                    } else {
                        deleteMember(head2, prn);
                    }
                } else {
                    cout << "Invalid choice. Try again." << endl;
                }
                break;
            }
            case 3: {
                int listChoice;
                cout << "\nSelect list to display members:\n";
                cout << "1. List 1\n";
                cout << "2. List 2\n";
                cin >> listChoice;
                if (listChoice == 1) {
                    displayMembers(head1);
                } else if (listChoice == 2) {
                    displayMembers(head2);
                } else {
                    cout << "Invalid choice. Try again." << endl;
                }
                break;
            }
            case 4: {
                cout << "Total members in List 1: " << countMembers(head1) << endl;
                cout << "Total members in List 2: " << countMembers(head2) << endl;
                break;
            }
            case 5: {
                Node* mergedList = concatenateLists(head1, head2);
                cout << "Merged List:" << endl;
                displayMembers(mergedList);
                break;
            }
            case 6:
                menu = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
