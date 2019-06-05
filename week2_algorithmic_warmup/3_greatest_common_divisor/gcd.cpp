#include <iostream>

int gcd_naive(int a, int b)
{
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++)
  {
    if (a % d == 0 && b % d == 0)
    {
      if (d > current_gcd)
      {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

long long gcd_fast(long long a, long long b)
{
  long long rem, low_val, high_val;
  low_val = a >= b ? b : a;
  high_val = a >= b ? a : b;
  do
  {
    rem = high_val % low_val;
    high_val = low_val;
    low_val = rem;
  } while (rem != 0);
  return high_val;
}

int main()
{
  long long a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
