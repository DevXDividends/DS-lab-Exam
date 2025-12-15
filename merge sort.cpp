TC:O(n log n) SC:O(n)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
            temp.emplace_back(a[left++]);
        else
            temp.emplace_back(a[right++]);
    }
    while (left <= mid)
        temp.emplace_back(a[left++]);
    while (right <= high)
        temp.emplace_back(a[right++]);
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}
void merge_sort(int a[], int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
}
int main()
{
    int a[4] = {4, 2, 6, 1};
    int n = 4;
    merge_sort(a, 0, n - 1);
    cout << "sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
