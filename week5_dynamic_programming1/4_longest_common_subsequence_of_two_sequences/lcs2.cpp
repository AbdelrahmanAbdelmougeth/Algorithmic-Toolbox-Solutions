#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b)
{
  // write your code here
  int m = a.size(), n = b.size();
  int DP[m + 1][n + 1];

  for (int i = 0; i <= m; i++)
    DP[i][0] = 0;
  for (int i = 0; i <= n; i++)
    DP[0][i] = 0;

  for (int i = 1; i <= m; i++)
    for (size_t j = 1; j <= n; j++)
    {
      if (a[i - 1] == b[j - 1])
        DP[i][j] = 1 + DP[i - 1][j - 1];
      else
        DP[i][j] = std::max(DP[i][j - 1], DP[i - 1][j]);
    }

  return DP[m][n];
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++)
  {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
