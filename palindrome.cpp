#include <iostream>
using namespace std;
#define MAX 100

class Stack {
    int top = -1;
    char arr[MAX];

public:
    void push(char val) {
        if (top == MAX - 1) {
            cout << "Stack Overflow - Element can't be inserted" << endl;
        } else {
            top++;
            arr[top] = val;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow - Element can't be deleted" << endl;
        } else {
            top--;
        }
    }

    char peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    void printOriginalAndReversed() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Original string: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i];
        }
        cout << endl;

        cout << "Reversed string: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i];
        }
        cout << endl;
    }

   bool check_palindrome() {
        for (int i = 0; i <= top / 2; ++i) {
            if (arr[i] != arr[top - i]) {
                return false;
            }
        }
        return true;
    }

 };
int main() {
    Stack stack;
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    // Push characters into the stack
    for (char c : s) {
        stack.push(c);
    }

    stack.printOriginalAndReversed();

    if (stack.check_palindrome()) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}

