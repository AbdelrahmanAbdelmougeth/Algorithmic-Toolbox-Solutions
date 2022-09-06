#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

bool is_better(const string &a, const string &b)
{
  string ab = a + b;
  string ba = b + a;
  if (ab > ba)
    return true;
  return false;
}

void swap(string *a, string *b)
{
  string temp = *a;
  *a = *b;
  *b = temp;
}

// O(n^2)
string largest_number(vector<string> &a)
{
  // write your code here
  std::stringstream ret;
  for (int i = 0; i < a.size(); i++)
    for (size_t j = i + 1; j < a.size(); j++)
    {
      if (!is_better(a[i], a[j]))
      {
        swap(&a[i], &a[j]);
      }
    }
  for (size_t i = 0; i < a.size(); i++)
  {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
