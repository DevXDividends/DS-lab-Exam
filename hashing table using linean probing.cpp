#include <iostream>
using namespace std;

#define SIZE 11

int hashTable[SIZE];

// Initialize hash table
void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash function (Mod 11)
int hashFunction(int key) {
    return key % SIZE;
}

// Insert using Linear Probing
void insertKey() {
    int key;
    cout << "Enter key to insert: ";
    cin >> key;

    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == start) {
            cout << "Hash Table is FULL\n";
            return;
        }
    }

    hashTable[index] = key;
    cout << "Key " << key << " inserted at slot " << index << endl;
}

// Search using Linear Probing
void searchKey() {
    int key;
    cout << "Enter key to search: ";
    cin >> key;

    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1) {
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

// Display hash table
void display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            cout << i << " : empty\n";
        else
            cout << i << " : " << hashTable[i] << endl;
    }
}

// Main menu
int main() {
    int choice;
    init();

    do {
        cout << "\n--- Linear Probing Hashing (Mod 11) ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertKey();
                break;
            case 2:
                searchKey();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
