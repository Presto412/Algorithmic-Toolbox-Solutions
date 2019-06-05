#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct weightValuePair
{
  int weight, value;
  double vw;
};

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;
  // write your code here
  vector<weightValuePair> triplets;
  for (unsigned long long i = 0; i < weights.size(); i++)
  {
    weightValuePair k;
    k.weight = weights[i];
    k.value = values[i];
    k.vw = values.at(i) * 1.0 / weights.at(i);
    triplets.push_back(k);
  }
  std::sort(triplets.begin(), triplets.end(), [](const weightValuePair &a, const weightValuePair &b) -> bool {
    return a.vw > b.vw;
  });

  for (unsigned long long i = 0; i < triplets.size(); i++)
  {
    if (capacity <= 0)
    {
      break;
    }
    if (triplets[i].weight <= capacity)
    {
      value += triplets[i].value;
      capacity -= triplets[i].weight;
    }
    else
    {
      value += triplets[i].vw * capacity;
      capacity = 0;
    }
  }
  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
