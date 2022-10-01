#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w)
{
  // write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i)
  {
    if (current_weight + w[i] <= W)
    {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int optimal_weight_DP(int W, const vector<int> &w)
{
  vector<vector<int>> Dp(w.size() + 1, vector<int>(W + 1));
  for (int i = 0; i <= W; i++)
    Dp[0][i] = 0;
  for (int i = 0; i <= w.size(); i++)
    Dp[i][0] = 0;

  for (int i = 1; i <= w.size(); i++)
    for (int j = 1; j <= W; j++)
    {
      if (j >= w[i - 1])
        Dp[i][j] = std::max(w[i - 1] + Dp[i - 1][j - w[i - 1]],
                           Dp[i - 1][j]);
      else
        Dp[i][j] = Dp[i - 1][j];
    }

  return Dp[w.size()][W];
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight_DP(W, w) << '\n';
}
