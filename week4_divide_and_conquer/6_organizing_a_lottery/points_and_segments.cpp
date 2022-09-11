#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Segment
{
  int start, end;
};

// type = -2 (start_segment) ,0 (end_segment),-1 (point)
// Taht is not a random choice because the algorithm is designed that the end comes after the point if they repeated
struct Point
{
  int location, type, index;
};

/*
Points and segments on GFG https://www.geeksforgeeks.org/find-number-of-segments-covering-each-point-in-an-given-array/
*/
/*
Points and segments on Stack Overflow https://stackoverflow.com/questions/33752703/points-and-segments/33752996#33752996
*/
/*
You can use sweep line algorithm to solve this problem.

First, break each segment into two points, open and close points.

Add all these points together with those m points, and sort them based on their locations.

Iterating through the list of points, maintaining a counter, every time you encounter an open point, increase the counter, and if you encounter an end point, decrease it. If you encounter a point in list m point, the result for this point is the value of counter at this moment.
*/
/*
For example 2, we have:

1 3
-10 10
-100 100 0

After sorting, what we have is:

-100 -10 0 10 100

At point -100, we have `counter = 0`

At point -10, this is open point, we increase `counter = 1`

At point 0, so result is 1

At point 10, this is close point, we decrease `counter = 0`

At point 100, result is 0

So, result for point -100 is 0, point 100 is 0 and point 0 is 1 as expected.
*/
/*Time complexity is O((n + m) log (n + m)).*/

bool func(const Point &point_1, const Point &point_2)
{
  if (point_1.location < point_2.location)
    return true;
  if (point_1.location == point_2.location && point_1.type < point_2.type)
    return true;
  return false;
}
vector<int> fast_count_segments(vector<Segment> &segments, vector<int> points)
{
  vector<int> cnt(points.size());
  vector<Point> all_points;
  for (int i = 0; i < segments.size(); i++)
  {
    all_points.push_back({segments[i].start, -2, -999});
    all_points.push_back({segments[i].end, 0, -999});
  }
  for (int i = 0; i < points.size(); i++)
    all_points.push_back({points[i], -1, i});

  // std::sort(all_points.begin(), all_points.end(), [](const Point &point_1, const Point &point_2)
  //           { return point_1.location < point_2.location /*|| point_1.type < point_2.type*/; });
  std::sort(all_points.begin(), all_points.end(), func);

  // for (int i = 0; i < all_points.size(); i++)
  //   std::cout << all_points[i].location << " " << all_points[i].type << "\n";
  // std::cout << '\n';

  int counter = 0;
  for (int i = 0; i < all_points.size(); i++)
  {
    if (all_points[i].type == -1)
    {
      cnt[all_points[i].index] = counter;
    }
    if (all_points[i].type == -2)
      counter++;
    if (all_points[i].type == 0)
      counter--;
  }
  return cnt;
}

vector<int> naive_count_segments(vector<Segment> &segments, vector<int> points)
{
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++)
  {
    for (size_t j = 0; j < segments.size(); j++)
    {
      cnt[i] += segments[j].start <= points[i] && points[i] <= segments[j].end;
    }
  }
  return cnt;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); i++)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++)
  {
    std::cin >> points[i];
  }
  // use fast_count_segments fast_count_segments
  vector<int> cnt = fast_count_segments(segments, points);
  for (size_t i = 0; i < cnt.size(); i++)
  {
    std::cout << cnt[i] << ' ';
  }
}
