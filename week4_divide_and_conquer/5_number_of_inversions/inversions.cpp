#include <iostream>
#include <vector>

using std::vector;

//O(n log n) as merge sort
long long count_and_merge(vector<int> &a, size_t l, size_t m, size_t r)
{
  int n1 = m - l + 1, n2 = r - m;
  vector<int> left(n1);
  vector<int> right(n2);
  for (int i = 0; i < n1; i++)
    left[i] = a[l + i];
  for (int i = 0; i < n2; i++)
    right[i] = a[m + 1 + i];

  long long number_of_inversions = 0; int i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
  {
    if (left[i] <= right[j])
    {
      a[k] = left[i];
      i++;
    }
    else
    {
      a[k] = right[j];
      j++;
      number_of_inversions = number_of_inversions + (n1 - i);
    }
    k++;
  }
  while (i < n1)
  {
    a[k] = left[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    a[k] = right[j];
    j++;
    k++;
  }
  return number_of_inversions;
}

long long get_number_of_inversions(vector<int> &a, size_t left, size_t right)
{
  long long number_of_inversions = 0;
  if (left < right)
  {
    int mid = left + (right - left) / 2;
    number_of_inversions += get_number_of_inversions(a, left, mid);
    number_of_inversions += get_number_of_inversions(a, mid + 1, right);
    number_of_inversions += count_and_merge(a, left, mid, right);
  }
  return number_of_inversions;
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
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a,0, a.size()-1) << '\n';
}
