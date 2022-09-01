#include <iostream>

long long lcm_naive(int a, int b)
{
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
}

/*While Loop Euclidean Algorithm*/
int gcd_euclidean_algorithm(int a, int b)
{
  int remainder = 0;
  while (b != 0)
  {
    remainder = a % b;
    a = b;
    b = remainder;
  }
  return a;
}

long long int lcm_fast(int a, int b)
{
  // Always be aware of the casting problem you can't do int with long long int
  return (long long int)(((long long)a * (long long)b) / (long long int)gcd_euclidean_algorithm(a, b));
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
