#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2)
{
  // write your code here
  int m = str1.length(), n = str2.length();
  int DP[m + 1][n + 1];

  for (int i = 0; i <= m; i++)
    DP[i][0] = i;
  for (int i = 0; i <= n; i++)
    DP[0][i] = i;

  for (int i = 1; i <= m; i++)
    for (size_t j = 1; j <= n; j++)
    {
      if (str1[i - 1] == str2[j - 1])
        DP[i][j] = DP[i - 1][j - 1];
      else
        DP[i][j] = 1 + std::min(std::min(DP[i][j - 1], DP[i - 1][j]), DP[i - 1][j - 1]);
    }

  return DP[m][n];
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
