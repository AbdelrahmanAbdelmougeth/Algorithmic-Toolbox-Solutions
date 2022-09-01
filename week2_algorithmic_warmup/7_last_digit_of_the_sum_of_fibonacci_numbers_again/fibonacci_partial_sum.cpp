#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i)
    {
        if (i >= from)
        {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to)
{
    /*You can use the vector as well as the regular array*/
    // vector<long long> vect = {0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1};

    int arr[60] = {0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1};

    long long sum = 0;

    long long index = from % 60;
    long long end_index = to % 60;
    while (true)
    {
        sum += arr[index % 60];
        if (index % 60 == end_index)
            break;
        index++;
    }
    return sum % 10;
}

void stress_test_solution()
{
    for (long long from = 1; from < 20; from++)
    {
        for (long long to = 2; to < 20; to++)
        {
            long long fibonacci_naive = get_fibonacci_partial_sum_naive(from, to);
            long long fibonnaci_fast = get_fibonacci_partial_sum_fast(from, to);
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
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';

    // stress_test_solution();
}
