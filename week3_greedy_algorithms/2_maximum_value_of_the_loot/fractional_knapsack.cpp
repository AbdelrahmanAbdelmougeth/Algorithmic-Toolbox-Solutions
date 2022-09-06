#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

// I made a little changes to the file so there is that struct that holds one item
// with its value and weight and changed the vector according to this change
struct item
{
  int value;
  int weight;
};

/* O(n log(n) + n) ---> n log(n) for sorting the vector and then n to traverse the sorted vector
so the overall Time Complexity O(n log(n))*/
double get_optimal_value(int capacity, vector<item> values_weights)
{
  double value = 0.0;
  // write your code here
  if (capacity == 0)
    return value;

  // Sorting the vector in decreasing oreder according to the value/weight ratio
  std::sort(values_weights.begin(), values_weights.end(), [](const item &item_1, const item &item_2)
            { return (double)item_1.value / (double)item_1.weight > (double)item_2.value / (double)item_2.weight; });

  for (int i = 0; i < values_weights.size(); i++)
  {
    if (values_weights[i].weight <= capacity)
    {
      capacity -= values_weights[i].weight;
      value += (double)values_weights[i].value;
    }
    else
    {
      // as long i got here so the theive got a fraction of weight to fill it
      value += ((double)values_weights[i].value * (double)capacity / (double)values_weights[i].weight);
      break;
    }
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;

  vector<item> values_weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values_weights[i].value >> values_weights[i].weight;
  }

  double optimal_value = get_optimal_value(capacity, values_weights);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  
  return 0;
}
