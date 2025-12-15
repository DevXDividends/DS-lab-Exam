#include <iostream>
using namespace std;

#define MAX 100

/* ---------- INSERTION SORT ---------- */
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            swap(a[j - 1], a[j]);
            j--;
        }
    }
}

/* ---------- BUBBLE SORT ---------- */
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

/* ---------- MERGE SORT ---------- */
void merge(int a[], int low, int mid, int high) {
    int temp[MAX];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }

    while (i <= mid) temp[k++] = a[i++];
    while (j <= high) temp[k++] = a[j++];

    for (int x = low; x <= high; x++)
        a[x] = temp[x];
}

void mergeSort(int a[], int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(a, low, mid);
    mergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}

/* ---------- QUICK SORT ---------- */
int partition(int a[], int low, int high) {
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

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

/* ---------- BINARY SEARCH ---------- */
int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

/* ---------- FIBONACCI SEARCH ---------- */
int fibonacciSearch(int a[], int n, int key) {
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
    int a[MAX], n = 0, choice;

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
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> a[i];
        }

        else if (choice == 2) {
            int ch;
            cout << "1. Insertion Sort\n2. Bubble Sort\nChoose: ";
            cin >> ch;
            if (ch == 1) insertionSort(a, n);
            else bubbleSort(a, n);

            cout << "Sorted Array: ";
            for (int i = 0; i < n; i++) cout << a[i] << " ";
            cout << endl;
        }

        else if (choice == 3) {
            int ch;
            cout << "1. Merge Sort\n2. Quick Sort\nChoose: ";
            cin >> ch;
            if (ch == 1) mergeSort(a, 0, n - 1);
            else quickSort(a, 0, n - 1);

            cout << "Sorted Array: ";
            for (int i = 0; i < n; i++) cout << a[i] << " ";
            cout << endl;
        }

        else if (choice == 4) {
            int key, ch;
            cout << "Enter element to search: ";
            cin >> key;
            cout << "1. Binary Search\n2. Fibonacci Search\nChoose: ";
            cin >> ch;

            int idx = (ch == 1) ? binarySearch(a, n, key)
                                : fibonacciSearch(a, n, key);

            if (idx != -1) cout << "Found at index " << idx << endl;
            else cout << "Not Found\n";
        }

    } while (choice != 5);

    return 0;
}
