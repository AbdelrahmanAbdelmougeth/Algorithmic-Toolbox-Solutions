#include <iostream>

int fibonacci_sum_squares_naive(long long n)
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
        sum += current * current;
    }

    return sum % 10;
}

// O(1)
int fibonacci_sum_squares_fast(long long n)
{
    int arr[30] = {0, 1, 2, 6, 5, 0, 4, 3, 4, 0, 5, 6, 2, 1, 0, 0, 9, 8, 4, 5, 0, 6, 7, 6, 0, 5, 4, 8, 9, 0};

    n = n % 30;
    return arr[n];
}

void stress_test_solution()
{
    for (long long fib = 0; fib < 40; fib++)
    {
        long long fibonacci_naive = fibonacci_sum_squares_naive(fib);
        long long fibonnaci_fast = fibonacci_sum_squares_fast(fib);
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
    std::cout << fibonacci_sum_squares_fast(n);

    // stress_test_solution();
}
