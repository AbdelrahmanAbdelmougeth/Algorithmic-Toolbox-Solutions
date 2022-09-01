#include <iostream>

int fibonacci_sum_naive(long long n)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

// O(1)
int fibonacci_sum_fast(long long m)
{
    // Series of Sum(Fib(0),...,Fib(n)) % 10
    int arr[60] = {0, 1, 2, 4, 7, 2, 0, 3, 4, 8, 3, 2, 6, 9, 6, 6, 3, 0, 4, 5, 0, 6, 7, 4, 2, 7, 0, 8, 9, 8, 8, 7, 6, 4, 1, 6, 8, 5, 4, 0, 5, 6, 2, 9, 2, 2, 5, 8, 4, 3, 8, 2, 1, 4, 6, 1, 8, 0, 9, 0};

    m = m % 60;
    return arr[m];
}

void stress_test_solution()
{
    for (long long fib = 1; fib < 40; fib++)
    {
        long long fibonacci_naive = fibonacci_sum_naive(fib);
        long long fibonnaci_fast = fibonacci_sum_fast(fib);
        // Seeing if there is a fail we stop if not continue untill finish
        if (fibonacci_naive != fibonnaci_fast)
        {
            std::cout << "Wrong Answer: " << fibonacci_naive << ' ' << fibonnaci_fast << "\n";
            break;
        }
        std::cout << "Ok \n";
    }
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);

    // stress_test_solution();
}
