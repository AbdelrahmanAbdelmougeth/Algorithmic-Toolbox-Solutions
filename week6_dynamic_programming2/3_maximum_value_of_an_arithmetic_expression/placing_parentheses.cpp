#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::max;
using std::min;
using std::string;
using std::vector;

long long eval(long long a, long long b, char op){
  if (op == '*')
  {
    return a * b;
  }
  else if (op == '+')
  {
    return a + b;
  }
  else
  {
    assert(0);
  }
  return 0;
}

bool isDigit(char c)
{
  if (c == '+' || c == '*' || c == '-')
    return true;
  return false;
}

int evalExpressionMax(string str)
{
  if (str.size() == 1)
    return (int)str[0] - 48; // to return the ascci code for the

  int ans = INT_MIN;
  for (int i = 0; i < str.length(); i++)
  {
    if (isDigit(str[i]))
    {
      int tempAns = 0, ELeft = 0, ERight = 0;
      ELeft = evalExpressionMax(str.substr(0, i));
      ERight = evalExpressionMax(str.substr(i + 1));
      tempAns = eval(ELeft, ERight, str[i]);
      ans = max(ans, tempAns);
    }
  }
  return ans;
}

long long get_maximum_value(const string &exp)
{
  return 0;
}
int main()
{
  // print1ton(10);
  string s;
  std::cin >> s;
  std::cout << evalExpressionMax(s);
}
