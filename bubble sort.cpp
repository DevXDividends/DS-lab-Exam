TC:O(n^ 2) SC:O(1)
  #include <iostream>
using namespace std;
void bubble_sort(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        swap(a[j], a[j + 1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
  cout << "swapped array: ";
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
}
int main()
{
  int arr[5] = {10, 9, 8, 7, 5};
  int n = 5;
  bubble_sort(arr, n);
}
