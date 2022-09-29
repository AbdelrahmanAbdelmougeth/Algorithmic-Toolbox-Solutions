#include <iostream>

int get_change(int m)
{
  // write your code here
  int coins[3] = {1, 3, 4};
  int DP[m + 1];
  for (int i = 0; i < m + 1; i++)
    DP[i] = INT16_MAX;
  DP[0] = 0;

  for (int i = 1; i <= m; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (coins[j] <= i)
      {
        int sub_change = DP[i - coins[j]] + 1;
        if (sub_change != INT16_MAX)
          DP[i] = std::min(DP[i], sub_change);
      }
    }
  }
  return DP[m];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
