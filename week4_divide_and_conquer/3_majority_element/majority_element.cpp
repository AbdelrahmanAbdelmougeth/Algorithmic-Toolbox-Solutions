#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

// Implementation of Boyer–Moore majority vote algorithm
int get_majority_element(vector<int> &a)
{
  int majority_element = a[0];
  int counter = 1;
  // Here we get a little probability that there is a majority element
  for (int i = 0; i < a.size(); i++)
  {
    (majority_element == a[i]) ? counter++ : counter--;
    if (counter == 0)
    {
      majority_element = a[i];
      counter = 1;
    }
  }
  // we need to make sure that there is really a majority element
  counter = 0;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] == majority_element)
      counter++;
  }
  if (counter > a.size() / 2)
    return 1;
  return 0;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a) << '\n';
}
