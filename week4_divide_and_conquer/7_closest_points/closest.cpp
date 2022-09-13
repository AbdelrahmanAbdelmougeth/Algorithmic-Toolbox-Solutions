#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <float.h>

using std::min;
using std::pair;
using std::string;
using std::vector;

struct Point
{
  long long x, y;
};

bool sort_according_to_x(const Point &point_1, const Point &point_2)
{
  if (point_1.x < point_2.x)
    return true;
  return false;
}

bool sort_according_to_y(const Point &point_1, const Point &point_2)
{
  if (point_1.y < point_2.y)
    return true;
  return false;
}

double calculate_distance(const Point &p1, const Point &p2)
{
  return std::sqrt(std::pow((p2.y - p1.y), 2) + std::pow((p2.x - p1.x), 2) * 1.0);
}

double minimum_distance_naive(vector<Point> &points)
{
  double minimum_distance = DBL_MAX;
  for (int i = 0; i < points.size(); i++)
    for (int j = i + 1; j < points.size(); j++)
      minimum_distance = std::min(minimum_distance, calculate_distance(points[i], points[j]));
  return minimum_distance;
}

double min_strip(vector<Point> &in_strip)
{
  int s = in_strip.size();
  double minimum = DBL_MAX;
  for (int i = 0; i < in_strip.size(); i++)
  {
    for (int j = i + 1; j < std::min(i + 7, s); j++)
    {
      double d_if = calculate_distance(in_strip[i], in_strip[j]);
      if (d_if < minimum)
        minimum = d_if;
    }
  }
  return minimum;
}


//O(n log n)
/*https://www.youtube.com/watch?v=ldHA8UcQI9Q*/
double minimum_distance_fast(vector<Point> &x_sorted, vector<Point> &y_sorted)
{
  // write your code here
  int n = x_sorted.size();
  if (n <= 3)
    return minimum_distance_naive(x_sorted);

  int mid = n / 2;
  Point mid_point = x_sorted[mid];
  vector<Point> x_sorted_left(x_sorted.cbegin(), x_sorted.cbegin() + mid);
  vector<Point> x_sorted_right(x_sorted.cbegin() + mid, x_sorted.cend());
  vector<Point> y_sorted_left;
  vector<Point> y_sorted_right;

  for (int i = 0; i < y_sorted.size(); i++)
  {
    if (y_sorted[i].x <= mid_point.x)
      y_sorted_left.push_back(y_sorted[i]);
    else
      y_sorted_right.push_back(y_sorted[i]);
  }

  double d_left = minimum_distance_fast(x_sorted_left, y_sorted_left);
  double d_right = minimum_distance_fast(x_sorted_right, y_sorted_right);
  double d = std::min(d_left, d_right);

  vector<Point> in_strip;
  for (int i = 0; i < y_sorted.size(); i++)
    if (y_sorted[i].x > mid_point.x - d || y_sorted[i].x < mid_point.x + d)
      in_strip.push_back(y_sorted[i]);

  return std::min(d, min_strip(in_strip));
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<Point> points(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> points[i].x >> points[i].y;
  }
  vector<Point> x_sorted(points.begin(), points.end());
  vector<Point> y_sorted(points.begin(), points.end());

  std::sort(x_sorted.begin(), x_sorted.end(), sort_according_to_x);
  std::sort(y_sorted.begin(), y_sorted.end(), sort_according_to_y);

  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimum_distance_fast(x_sorted, y_sorted) << "\n";
}
