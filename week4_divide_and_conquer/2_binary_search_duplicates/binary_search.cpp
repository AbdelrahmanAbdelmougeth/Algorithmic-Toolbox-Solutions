#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

// O(log n)
int binary_search(const vector<int> &a, int x)
{
  int left = 0, right = (int)a.size() - 1, index_of_first_occurance = -1;
  while (left <= right)
  {
    int mid = (left + right) / 2;
    if (a[mid] > x)
      right = mid - 1;
    else if (a[mid] < x)
      left = mid + 1;
    else
    {
      index_of_first_occurance = mid;
      right = mid - 1;
      // For the last occurance that's the only change
      // left = mid + 1;
    }
  }
  return index_of_first_occurance;
}

int linear_search(const vector<int> &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i)
  {
    // replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
