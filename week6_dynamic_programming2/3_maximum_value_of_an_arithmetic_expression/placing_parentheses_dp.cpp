#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>
using std::max;
using std::min;
using std::string;
using std::vector;

long long eval(long long a, long long b, char op)
{
  if (op == '*')
    return a * b;
  else if (op == '+')
    return a + b;
  else
    return a - b;
}

vector<long long> min_and_max(vector<vector<long long>> &M, vector<vector<long long>> &m, int i, int j, const string &exp)
{
  long long MinValue = LLONG_MAX;
  long long MaxValue = LLONG_MIN;

  for (int k = i; k < j; k++)
  {
    long long a = eval(M[i][k], M[k + 1][j], exp[2 * k + 1]);
    long long b = eval(M[i][k], m[k + 1][j], exp[2 * k + 1]);
    long long c = eval(m[i][k], M[k + 1][j], exp[2 * k + 1]);
    long long d = eval(m[i][k], m[k + 1][j], exp[2 * k + 1]);

    MinValue = min(MinValue, min(a, min(b, min(c, d))));
    MaxValue = max(MaxValue, max(a, max(b, max(c, d))));
  }

  vector<long long> min_max{MinValue, MaxValue};
  return min_max;
};

long long get_maximum_value(const string &exp)
{
  // write your code here
  int n = (exp.size() + 1) / 2;

  vector<vector<long long>> M(n, vector<long long>(n, 0));
  vector<vector<long long>> m(n, vector<long long>(n, 0));

  int f = 0;
  for (int i = 0; i < exp.size(); i++)
  {
    if (exp[i] >= 48 && exp[i] <= 57)
    {
      M[f][f] = long(exp[i]) - 48;
      m[f][f] = long(exp[i]) - 48;
      f++;
    }
  }

  for (int s = 0; s < n - 1; s++)
  {
    for (int i = 0; i < n - s - 1; i++)
    {
      int j = i + s + 1;
      vector<long long> min_max = min_and_max(M, m, i, j, exp);

      m[i][j] = min_max[0];
      M[i][j] = min_max[1];
    }
  }

  return M[0][n - 1];
}

int main()
{
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
