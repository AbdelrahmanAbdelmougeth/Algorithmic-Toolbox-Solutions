#include <iostream>
#include <vector>
#include <algorithm>

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
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


int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
