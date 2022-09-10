#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

// This function takes last element as
// pivot, places the pivot element at
// its correct position in sorted
// array, and places all smaller
// (smaller than pivot) to left of pivot
// and all greater elements to right
int partition(vector<int> &arr, int low, int high)
{
  int pivot = arr[low];
  int i = low - 1, j = high + 1;

  while (true)
  {

    // Find leftmost element greater than
    // or equal to pivot
    do
    {
      i++;
    } while (arr[i] < pivot);

    // Find rightmost element smaller than
    // or equal to pivot
    do
    {
      j--;
    } while (arr[j] > pivot);

    // If two pointers met
    if (i >= j)
      return j;

    swap(arr[i], arr[j]);
  }
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
// In Hoare partition the low element is selected
// as first pivot
int partition_r(vector<int> &arr, int low, int high)
{
  // Generate a random number in between
  // low .. high
  srand(time(NULL));
  int random = low + rand() % (high - low);

  // Swap A[random] with A[high]
  swap(arr[random], arr[low]);

  return partition(arr, low, high);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low  --> Starting index,
// high  --> Ending index
void quickSort(vector<int> &arr, int low, int high)
{
  while (low < high)
  {
    // pi is partitioning index,
    // arr[p] is now at right place
    int pi = partition_r(arr, low, high);

    // Separately sort elements before
    // partition and after partition
    quickSort(arr, low, pi);
    low = pi + 1;
  }
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  quickSort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
