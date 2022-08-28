#include <iostream>

int get_fibonacci_last_digit_naive(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n)
{
    if (n <= 1)
        return n;

    int fib_before_prev = 0; // Fibonacci(n-2) % 10
    int fib_prev = 1;        // Fibonacci(n-1) % 10
    int fib_n = 0;           // Fibonacci(n) "Initial Value"
    for (int i = 1; i < n; i++)
    {
        fib_n = (fib_prev + fib_before_prev) % 10;
        fib_before_prev = fib_prev;
        fib_prev = fib_n;
    }
    return fib_n;
}

int main()
{
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
