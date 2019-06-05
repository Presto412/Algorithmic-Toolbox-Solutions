#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;

int main()
{
  long long n, m;
  std::cin >> n >> m;
  vector<long long> starts(n), ends(n);
  for (long long unsigned int i = 0; i < starts.size(); i++)
  {
    starts[i] = 5;
  }
  std::cout << starts[starts.size() - 1];
}
