#include <iostream>
using namespace std;

#define SIZE 11
#define EMPTY -1
#define DELETED -2

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = EMPTY;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insertKey() {
    int key;
    cout << "Enter key to insert: ";
    cin >> key;

    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != EMPTY && hashTable[index] != DELETED) {
        index = (index + 1) % SIZE;
        if (index == start) {
            cout << "Hash table is FULL\n";
            return;
        }
    }

    hashTable[index] = key;
    cout << "Inserted at slot " << index << endl;
}

void searchKey() {
    int key;
    cout << "Enter key to search: ";
    cin >> key;

    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            cout << "Key found at slot " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }

    cout << "Key not found\n";
}

void deleteKey() {
    int key;
    cout << "Enter key to delete: ";
    cin >> key;

    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            hashTable[index] = DELETED;  // tombstone
            cout << "Key deleted from slot " << index << endl;
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }

    cout << "Key not found\n";
}

void display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            cout << i << " : empty\n";
        else if (hashTable[i] == DELETED)
            cout << i << " : deleted\n";
        else
            cout << i << " : " << hashTable[i] << endl;
    }
}

int main() {
    int choice;
    init();

    do {
        cout << "\n--- Linear Probing Hashing (Mod 11) ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertKey(); break;
            case 2: searchKey(); break;
            case 3: deleteKey(); break;
            case 4: display(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
