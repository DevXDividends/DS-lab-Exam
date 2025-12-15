#include <iostream>
using namespace std;

#define SIZE 5

class myqueue {
    int arr[SIZE];
    int front;
    int rear;

public:
    myqueue() {
        front = rear = -1;
    }

    bool isFull() {
        return (rear + 1) % SIZE == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is FULL\n";
            return;
        }

        if (front == -1) {   // first insertion
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = val;
        cout << "Inserted!\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return -1;
        }

        int res = arr[front];

        if (front == rear) {
            front = rear = -1;   // queue becomes empty
        } else {
            front = (front + 1) % SIZE;
        }

        return res;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return;
        }

        int i = front;
        cout << "Queue: ";
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    myqueue q;
    int ch, val;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;

            case 2:
                val = q.dequeue();
                if (val != -1)
                    cout << "Deleted: " << val << endl;
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (ch != 4);

    return 0;
}
