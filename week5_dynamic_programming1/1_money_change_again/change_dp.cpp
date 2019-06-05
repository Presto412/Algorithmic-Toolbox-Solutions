#include <iostream>

int get_change(int m)
{

  //write your code here
  int coins[] = {1, 3, 4};
  int min_num_coins[m + 1];
  min_num_coins[0] = 0;
  int numCoins = 0;
  for (int i = 1; i <= m; i++)
  {
    min_num_coins[i] = 9999999;
    for (int j = 0; j < 3; j++)
    {
      if (i >= coins[j])
      {
        numCoins = min_num_coins[i - coins[j]] + 1;
        if (numCoins < min_num_coins[i])
        {
          min_num_coins[i] = numCoins;
        }
      }
    }
  }
  return min_num_coins[m];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
