#include<iostream>
using namespace std;

#define MAX 5

int mystack[MAX], top = -1;
int myqueue[MAX], front = -1, rear = -1;

void push(int val) {
    mystack[++top] = val;
}

int pop() {
    if (top == -1) return -1;
    return mystack[top--];
}

void enqueue(int val) {
    if (front == -1) front = 0;
    myqueue[++rear] = val;
}

int dequeue() {
    int x = myqueue[front++];
    if (front > rear) front = rear = -1;   
    return x;
}

void reverseStack() {
    while (top != -1)
        enqueue(pop());

    while (front != -1)
        push(dequeue());
}

void displayStack() {
    for (int i = top; i >= 0; i--)
        cout << mystack[i] << " ";
    cout << endl;
}

int main() {
    int val;
    for (int i = 0; i < MAX; i++) {
        cout << "Enter values: ";
        cin >> val;
        push(val);
    }

    cout << "Original stack: ";
    displayStack();

    reverseStack();

    cout << "Reversed stack: ";
    displayStack();

    return 0;
}
