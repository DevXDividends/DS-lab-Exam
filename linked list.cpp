#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Insert at head
void insertAtHead(Node*& head, int val) {
    Node* nn = new Node(val);
    nn->next = head;
    head = nn;
}

// Insert at position
void insert(Node*& head) {
    int val, pos;
    cout << "Enter value: ";
    cin >> val;
    cout << "Enter position: ";
    cin >> pos;

    if (pos <= 1 || head == nullptr) {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < pos - 1 && temp->next != nullptr) {
        temp = temp->next;
        cnt++;
    }

    Node* nn = new Node(val);
    nn->next = temp->next;
    temp->next = nn;
}

// Delete by value
void deleteNode(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    int val;
    cout << "Enter value to delete: ";
    cin >> val;

    if (head->data == val) {
        Node* del = head;
        head = head->next;
        delete del;
        cout << "Deleted successfully\n";
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Value not found!\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
    cout << "Deleted successfully\n";
}

// Display list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int ch;

    do {
        cout << "\n1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                insert(head);
                break;
            case 2:
                deleteNode(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (ch != 4);

    return 0;
}
