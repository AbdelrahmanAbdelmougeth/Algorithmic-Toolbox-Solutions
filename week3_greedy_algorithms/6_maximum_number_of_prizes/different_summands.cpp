#include <iostream>
#include <vector>
#include <cmath>

using std::floor;
using std::sqrt;
using std::vector;

/*
If we knew the maximum number of summonds possible we will generate a vey simple algorithm

I found this on stack overflow :-
The smallest number that can be made with at least k different summands is just the sum of all numbers from 1 to k. Any number smaller than that will have fewer summands... at most k-1.

Gauss has a formula for the sum of numbers from 1 to k. It's just k(k+1)/2.

You just need to find the largest k such that k(k+1)/2 <= n. From the above, you know that if k were any larger, then you could not divide n into that many summands, so this is the largest possible answer.

It's also very easy to actually generate k summands that add to n -- it's just the sum of all numbers from 1 to k-1, and then whatever is left over (n - k(k-1)/2).

You can solve for k directly:

k(k+1)/2 <= n

k² + k - 2n <=0

k <= (sqrt(8n+1)-1)/2

The last step is via the quadratic formula. Since you want the largest possible k, it's just

k = floor((sqrt(8n+1)-1)/2)
*/

//O(n)
vector<int> optimal_summands(int n)
{
  int k = (sqrt(8 * (long long)n + 1) - 1) / 2;
  vector<int> summands(k, 0);
  int i = 0;
  int summand = 1;
  while (n)
  {
    if (i == summands.size() - 1)
    {
      summands[i] = n;
      break;
    }
    summands[i] = summand;
    n -= summand;
    summand++;
    i++;
  }
  return summands;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
}
