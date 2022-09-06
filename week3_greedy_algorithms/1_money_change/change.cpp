#include <iostream>

int get_change(int m)
{
  // write your code here
  int denominations[3] = {10, 5, 1};
  int coin_numbers = 0;
  int index = 0;
  while (m)
  {
    if (m >= denominations[index])
    {
      coin_numbers++;
      m = m - denominations[index];
    }
    else
    {
      index++;
    }
  }
  return coin_numbers;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
