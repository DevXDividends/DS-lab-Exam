#include <bits/stdc++.h>
using namespace std;

/* ---------- INSERTION SORT ---------- */
void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            swap(a[j - 1], a[j]);
            j--;
        }
    }
}

/* ---------- BUBBLE SORT ---------- */
void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

/* ---------- MERGE SORT ---------- */
void merge(vector<int>& a, int low, int mid, int high) {
    vector<int> temp;
    int i = low, j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }

    while (i <= mid) temp.push_back(a[i++]);
    while (j <= high) temp.push_back(a[j++]);

    for (int k = low; k <= high; k++)
        a[k] = temp[k - low];
}

void mergeSort(vector<int>& a, int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

/* ---------- QUICK SORT ---------- */
int partition(vector<int>& a, int low, int high) {
    int pivot = a[low];
    int i = low, j = high;

    while (i < j) {
        while (a[i] <= pivot && i < high) i++;
        while (a[j] > pivot) j--;
        if (i < j) swap(a[i], a[j]);
    }
    swap(a[low], a[j]);
    return j;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

/* ---------- BINARY SEARCH ---------- */
int binarySearch(vector<int>& a, int key) {
    int low = 0, high = a.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

/* ---------- FIBONACCI SEARCH ---------- */
int fibonacciSearch(vector<int>& a, int key) {
    int n = a.size();
    int fib2 = 0, fib1 = 1;
    int fib = fib1 + fib2;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;
    while (fib > 1) {
        int i = min(offset + fib2, n - 1);

        if (a[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (a[i] > key) {
            fib = fib2;
            fib1 -= fib2;
            fib2 = fib - fib1;
        }
        else return i;
    }

    if (fib1 && offset + 1 < n && a[offset + 1] == key)
        return offset + 1;

    return -1;
}

/* ---------- MAIN MENU ---------- */
int main() {
    vector<int> a;
    int choice;

    do {
        cout << "\n--- Sorting + Searching Menu ---\n";
        cout << "1. Read Array\n";
        cout << "2. Insertion / Bubble Sort\n";
        cout << "3. Merge / Quick Sort\n";
        cout << "4. Search (Binary / Fibonacci)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "Enter number of elements: ";
            cin >> n;
            a.resize(n);
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++) cin >> a[i];
        }

        else if (choice == 2) {
            int ch;
            cout << "1. Insertion Sort\n2. Bubble Sort\nChoose: ";
            cin >> ch;
            if (ch == 1) insertionSort(a);
            else bubbleSort(a);
            cout << "Sorted Array: ";
            for (int x : a) cout << x << " ";
            cout << endl;
        }

        else if (choice == 3) {
            int ch;
            cout << "1. Merge Sort\n2. Quick Sort\nChoose: ";
            cin >> ch;
            if (ch == 1) mergeSort(a, 0, a.size() - 1);
            else quickSort(a, 0, a.size() - 1);
            cout << "Sorted Array: ";
            for (int x : a) cout << x << " ";
            cout << endl;
        }

        else if (choice == 4) {
            int key, ch;
            cout << "Enter element to search: ";
            cin >> key;
            cout << "1. Binary Search\n2. Fibonacci Search\nChoose: ";
            cin >> ch;

            int idx = (ch == 1) ? binarySearch(a, key)
                                : fibonacciSearch(a, key);

            if (idx != -1) cout << "Found at index " << idx << endl;
            else cout << "Not Found\n";
        }

    } while (choice != 5);

    return 0;
}
