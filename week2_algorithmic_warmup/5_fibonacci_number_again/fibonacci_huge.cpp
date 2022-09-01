#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long pisano_period(long long m)
{
    long long fib_before_prev = 0; // Fibonacci(n-2) % m
    long long fib_prev = 1;        // Fibonacci(n-1) % m
    long long fib_n = 0;           // Fibonacci(n) "Initial Value"

    long long series_repeat_flag = 0;
    long long series_length = 0;

    while (series_repeat_flag != 1)
    {
        fib_n = ((fib_prev % m) + (fib_before_prev % m)) % m;
        fib_before_prev = fib_prev;
        fib_prev = fib_n;

        series_length++;

        if ((fib_n == 1) && (fib_prev == 1) && (fib_before_prev == 0))
            series_repeat_flag++;
    }
    return series_length;
}

long long get_fibonacci_huge_fast(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long pisano_period_length = pisano_period(m);

    n = n % pisano_period_length;
    if (n <= 1)
        return n;

    long long fib_before_prev = 0; // Fibonacci(n-2) % m
    long long fib_prev = 1;        // Fibonacci(n-1) % m
    long long fib_n = 0;           // Fibonacci(n) "Initial Value"

    for (long long i = 1; i < n; i++)
    {
        fib_n = ((fib_prev % m) + (fib_before_prev % m)) % m;
        fib_before_prev = fib_prev;
        fib_prev = fib_n;
    }
    return fib_n;
}

void stress_test_solution()
{
    for (long long fib = 1; fib < 20; fib++)
    {
        for (long long mod = 2; mod < 20; mod++)
        {
            long long fibonacci_naive = get_fibonacci_huge_naive(fib, mod);
            long long fibonnaci_fast = get_fibonacci_huge_fast(fib, mod);
            // Seeing if there is a fail we stop if not continue untill finish
            if (fibonacci_naive != fibonnaci_fast)
            {
                std::cout << "Wrong Answer: " << fibonacci_naive << ' ' << fibonnaci_fast << "\n";
                break;
            }
            std::cout << "Ok \n";
        }
    }
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';

    // stress_test_solution();
}
