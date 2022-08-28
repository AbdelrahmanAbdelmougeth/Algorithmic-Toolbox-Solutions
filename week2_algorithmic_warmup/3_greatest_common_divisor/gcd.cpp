#include <iostream>

int gcd_naive(int a, int b)
{
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++)
  {
    if (a % d == 0 && b % d == 0)
    {
      if (d > current_gcd)
      {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
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

/*Recursive Euclidean Algorithm*/
int gcd_recursive(int a, int b)
{
  if(b == 0)
    return a;

  gcd_recursive(b , a % b);  
}

int main()
{
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_euclidean_algorithm(a, b) << std::endl;
  // std::cout << gcd_recursive(a, b) << std::endl;

  // std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
