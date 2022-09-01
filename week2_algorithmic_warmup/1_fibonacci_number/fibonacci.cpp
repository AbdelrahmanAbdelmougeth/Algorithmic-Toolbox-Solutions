#include <iostream>
#include <cassert>

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n)
{
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n)
{
    // write your code here
    if (n <= 1)
        return n;

    int fib_prev = 1;         //Fibonacci(n-1)
    int fib_before_prev = 0;  //Fibonacci(n-2)
    int fib_n = 0;            //Fibonacci(n)
    for (int i = 1; i < n; i++)
    {
        fib_n = fib_prev + fib_before_prev;
        fib_before_prev = fib_prev;
        fib_prev = fib_n;
    }
    return fib_n;
}

void test_solution()
{
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);

    int fibonacci_f = 0;
    int fibonacci_n = 0;
    for (int n = 0; n < 40; ++n)
    {
        int fibonacci_f = fibonacci_fast(n);
        int fibonacci_n = fibonacci_naive(n);
        std::cout << fibonacci_n << "  "
                  << fibonacci_f << "\n";
        assert(fibonacci_f == fibonacci_n);
    }
}

int main()
{
    /*Code*/
    int n = 0;
    std::cin >> n;
    std::cout << fibonacci_fast(n) << '\n';

    // std::cout << fibonacci_naive(n) << '\n';
    // test_solution();
    return 0;
}
