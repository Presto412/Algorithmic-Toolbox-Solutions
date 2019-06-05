#include <iostream>
#include <vector>

using std::vector;

vector<int> v;
int sumtoget(int start, int sum)
{
  if (sum == 0)
  {
    return 1;
  }
  v.push_back(start);
  if (start > sum)
  {
    return -1;
  }
  int value = sumtoget(start + 1, sum - start);
  if (value == -1)
  {
    v.pop_back();
    v.pop_back();
    return sumtoget(start + 1, sum);
  }
  if (value == 1)
  {
    return 1;
  }
  return sumtoget(start + 1, sum - start);
}

vector<int> optimal_summands(int n)
{
  vector<int> summands;
  int sum = sumtoget(1, n);
  if (sum == -1)
  {
    return summands;
  }
  else
  {
    summands = v;
  }
  return summands;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << v.size() << '\n';
  for (size_t i = 0; i < v.size(); ++i)
  {
    std::cout << v[i] << ' ';
  }
}
