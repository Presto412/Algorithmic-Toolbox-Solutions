#include <iostream>
#include <vector>

using std::vector;

void print(vector<vector<long long>> v)
{
  for (auto x : v)
  {
    for (auto y : x)
    {
      std::cout << y << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

int lcs2(vector<long long> &a, vector<long long> &b)
{
  //write your code here
  vector<vector<long long>> dp(a.size() + 1, vector<long long>(b.size() + 1, 0));
  // print(dp);
  for (size_t i = 1; i <= a.size(); i++)
  {
    for (size_t j = 1; j <= b.size(); j++)
    {
      if (a[i - 1] == b[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  // print(dp);
  return dp[a.size()][b.size()];
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<long long> b(m);
  for (size_t i = 0; i < m; i++)
  {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
