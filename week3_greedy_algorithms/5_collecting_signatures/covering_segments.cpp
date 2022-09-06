#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment
{
  int start, end;
};

void draw_in_console(vector<Segment> &segments)
{
  for (int i = 0; i < segments.size(); i++)
  {
    int j = 0;
    while (j <= segments[i].end)
    {
      if (j >= segments[i].start && j <= segments[i].end)
        std::cout << "*";
      else
        std::cout << " ";
      j++;
    }
    std::cout << '\n';
  }
}

void sort_by_left_end(vector<Segment> &segments)
{
  /*Sort by left end*/
  std::sort(segments.begin(), segments.end(), [](const Segment &segment_1, const Segment &segment_2)
            { return segment_1.start < segment_2.start; });
}

void sort_by_right_end(vector<Segment> &segments)
{
  /*Sort by right end*/
  std::sort(segments.begin(), segments.end(), [](const Segment &segment_1, const Segment &segment_2)
            { return segment_1.end < segment_2.end; });
}

void sort_by_lenght(vector<Segment> &segments)
{
  /*Sort by length*/
  std::sort(segments.begin(), segments.end(), [](const Segment &segment_1, const Segment &segment_2)
            { return segment_1.end - segment_1.start < segment_2.end - segment_2.start; });
}

//O(nlogn + n) n log n for sorting the segments and then traversing them n so the overall O(nlogn)
vector<int> optimal_points(vector<Segment> &segments)
{
  vector<int> points;
  // write your code here
  sort_by_right_end(segments);
  int touching_point = segments[0].end;
  points.push_back(touching_point);
  for (size_t i = 1; i < segments.size(); ++i)
  {
    if (!(touching_point >= segments[i].start && touching_point <= segments[i].end))
    {
      touching_point = segments[i].end;
      points.push_back(touching_point);
    }
  }
  return points;
}

int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
}
