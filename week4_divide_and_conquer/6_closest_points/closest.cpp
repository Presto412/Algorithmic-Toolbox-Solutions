#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::min;
using std::pair;
using std::sort;
using std::string;
using std::vector;

struct point
{
  long long x, y;
};
void print(vector<point> a)
{
  for (auto x : a)
  {
    std::cout << x.x << "," << x.y << "|";
  }
  std::cout << "\n";
}
long long min(long long a, long long b)
{
  return a > b ? b : a;
}
bool sortByX(point p1, point p2)
{
  return p1.x < p2.x;
}
bool sortByY(point p1, point p2)
{
  return p1.y < p2.y;
}
double get_distance(point p1, point p2)
{
  return pow(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2), 0.5);
}

double _minimal_distance(vector<point> x, vector<point> y)
{
  if (x.size() == 1)
  {
    return 9999999999999.9;
  }
  if (x.size() == 2)
  {
    return get_distance(x[0], x[1]);
  }
  if (x.size() == 3)
  {
    return min(min(get_distance(x[0], x[2]), get_distance(x[0], x[1])), get_distance(x[1], x[2]));
  }

  int mid = x.size() % 2 == 0 ? (x.size() - 1) / 2 : x.size() / 2;
  // std::cout << "x size is:" << x.size() << "\n";
  // std::cout << "mid is:" << mid << "\n";
  vector<point> xl = x;
  vector<point> xr = x;
  xl.erase(xl.begin() + mid + 1, xl.end());
  xr.erase(xr.begin(), xr.begin() + mid + 1);

  vector<point> yl, yr;
  point midPoint = x[mid];
  for (size_t i = 0; i < y.size(); i++)
  {
    if (y[i].x <= midPoint.x)
      yl.push_back(y[i]);
    else
      yr.push_back(y[i]);
  }

  double d1 = _minimal_distance(xl, yl);
  double d2 = _minimal_distance(xr, yr);
  double d = d1 > d2 ? d2 : d1;

  vector<point> y_final;
  for (size_t i = 0; i < y.size(); i++)
  {
    if (y[i].x >= mid - d && y[i].x <= mid + d)
    {
      y_final.push_back(y[i]);
    }
  }
  for (size_t i = 0; i < y_final.size(); i++)
  {
    for (size_t j = i + 1; j < min(i + 9, y_final.size()); j++)
    {
      if (y_final[j].y - y_final[i].y > d)
      {
        break;
      }
      double distance = get_distance(y_final[i], y_final[j]);
      if (distance < d)
      {
        d = distance;
      }
    }
  }
  return d;
}

double minimal_distance(vector<long long> x, vector<long long> y)
{
  vector<point> all_points;
  for (size_t i = 0; i < x.size(); i++)
  {
    point p;
    p.x = x[i];
    p.y = y[i];
    all_points.push_back(p);
  }
  vector<point> x_sorted_points = all_points;
  sort(x_sorted_points.begin(), x_sorted_points.end(), sortByX);
  vector<point> _x = x_sorted_points;
  vector<point> y_sorted_points = all_points;
  sort(y_sorted_points.begin(), y_sorted_points.end(), sortByY);
  double result = _minimal_distance(x_sorted_points, y_sorted_points);
  return result;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<long long> x(n);
  vector<long long> y(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
