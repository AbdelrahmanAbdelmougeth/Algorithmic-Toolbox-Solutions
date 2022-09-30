#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n)
{
  std::vector<int> sequence;
  while (n >= 1)
  {
    sequence.push_back(n);
    if (n % 3 == 0)
    {
      n /= 3;
    }
    else if (n % 2 == 0)
    {
      n /= 2;
    }
    else
    {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int number_of_operations(int number)
{
  if (number == 1)
    return 0;

  int sub_1 = INT16_MAX, div_2 = INT16_MAX, div_3 = INT16_MAX;

  if (number - 1 != 0)
    sub_1 = number_of_operations(number - 1);
  if (number % 2 == 0)
    div_2 = number_of_operations(number / 2);
  if (number % 3 == 0)
    div_3 = number_of_operations(number / 3);

  return std::min(std::min(sub_1, div_2), div_3) + 1;
}

vector<int> construct_operation_sequence(vector<int> &DP)
{
  int n = DP.size() - 1;
  vector<int> operation_sequence;
  
  int i = n;
  while (i > 1)
  {
    operation_sequence.push_back(i);
    if (DP[i - 1] == DP[i] - 1)
      i = i - 1;
    else if (i % 2 == 0 && (DP[i / 2] == DP[i] - 1))
      i = i / 2;
    else if (i % 3 == 0 && (DP[i / 3] == DP[i] - 1))
      i = i / 3;
  }
  operation_sequence.push_back(1);
  reverse(operation_sequence.begin(), operation_sequence.end());
  return operation_sequence;
}

vector<int> number_of_operations_DP(int number)
{
  if (number == 1)
  {
    vector<int> operation_sequence;
    operation_sequence.push_back(1);
    return operation_sequence;
  }

  vector<int> DP(number + 1, INT8_MAX);
  DP[1] = 0;

  for (int i = 2; i <= number; i++)
  {
    DP[i] = DP[i - 1] + 1;
    if (i % 2 == 0)
      DP[i] = std::min(1 + DP[i / 2], DP[i]);
    if (i % 3 == 0)
      DP[i] = std::min(1 + DP[i / 3], DP[i]);
  }

  vector<int> operation_sequence = construct_operation_sequence(DP);
  return operation_sequence;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> sequence = number_of_operations_DP(n);
  // std::cout << number_of_operations(n) << std::endl;
  // std::cout << number_of_operations_DP(n) << std::endl;
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
