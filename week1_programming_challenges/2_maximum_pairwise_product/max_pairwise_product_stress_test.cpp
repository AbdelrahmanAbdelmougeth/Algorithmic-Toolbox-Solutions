#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int> &numbers)
{
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first)
    {
        for (int second = first + 1; second < n; ++second)
        {
            max_product = std::max(max_product,
                                   numbers[first] * numbers[second]);
        }
    }
    return max_product;
}

std::vector<int> ArrayLargestSecondLargest(const std::vector<int> &numbers)
{
    std::vector<int> largest_second_largest(2, INT_MIN);
    int n = numbers.size();
    for (int counter = 0; counter < n; counter++)
    {
        if (numbers[counter] > largest_second_largest[0])
        {
            largest_second_largest[1] = largest_second_largest[0];
            largest_second_largest[0] = numbers[counter];
        }
        if ((numbers[counter] > largest_second_largest[1]) && (numbers[counter] < largest_second_largest[0]))
        {
            largest_second_largest[1] = numbers[counter];
        }
    }
    return largest_second_largest;
}

int MaxPairwiseProductFast(const std::vector<int> &numbers)
{
    std::vector<int> largest_second_largest = ArrayLargestSecondLargest(numbers);
    return largest_second_largest[0] * largest_second_largest[1];
}

int main()
{
    srand(time(NULL));
    int number_of_iterations = rand();
    std::cout << number_of_iterations << "\n";
    for (int i = 0; i < number_of_iterations; i++)
    {
        // Generate a random size for the vector array
        srand(time(0));
        int n = rand() % 10 + 2;
        std::cout << n << "\n";

        // Create a vector and initialize all elements to zero
        std::vector<int> vect(n, 0);

        // Filling the empty vector with random values
        for (int i = 0; i < n; i++)
        {
            vect[i] = (rand() % 1000);
            std::cout << vect[i] << " ";
        }

        // Feeding the vector to our algorithms and get the result
        int pairwise_naive = MaxPairwiseProduct(vect);
        int pairwise_fast = MaxPairwiseProductFast(vect);

        // Seeing if there is a fail we stop if not continue untill finish
        if (pairwise_naive != pairwise_fast)
        {
            std::cout << "\nWrong Answer: " << pairwise_naive << ' ' << pairwise_fast << "\n";
            break;
        }
        std::cout << "\n Ok \n";
    }
    return 0;
}
