Insertion sort 
TC:o(n^2) SC:O(1)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int a[],int n)
{

  for (int i = 0; i < n; i++) // i = index of current element from unsorted part
  {
    int j = i;
    // Move current element to correct position in sorted part
    while (j > 0 && a[j - 1] > a[j])
    {
      swap(a[j - 1], a[j]);
      j--;
    }
  }

  cout << "Sorted array: ";
  for (int i = 0; i < 6; i++) // fixed loop size to 6 so all elements print
  {
    cout << a[i] << " ";
  }
}

int main()
{
  int a[6] = {10, 9, 8, 7, 6, 5};
  insertion_sort(a,6);
  return 0;
}
