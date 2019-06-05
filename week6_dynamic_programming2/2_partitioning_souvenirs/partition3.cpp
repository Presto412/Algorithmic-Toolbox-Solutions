#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
bool compareFunc(int a, int b)
{
  return a >= b;
}

int partition3(vector<int> &A)
{
  int sum = 0;
  for (auto x : A)
  {
    sum += x;
  }
  if (sum % 3 != 0)
  {
    return 0;
  }
  int bucketSize = sum / 3;
  vector<int> bucket1, bucket2, bucket3;
  vector<int> used(A.size());
  bool bucket1Full = false, bucket2Full = false, bucket3Full = false;
  int bucket1CurrSum = 0, bucket2CurrSum = 0, bucket3CurrSum = 0;
  std::sort(A.begin(), A.end(), compareFunc);
  int i = 0;
  while (!bucket1Full || !bucket2Full || !bucket3Full)
  {
    std::cout << "A[i]:" << A[i] << ",bucket1:" << bucket1CurrSum << "," << bucket1Full << ",bucket2:" << bucket2CurrSum << "," << bucket2Full << ",bucket3:" << bucket3CurrSum << "," << bucket3Full << "\n";
    if (i >= A.size() - 1)
    {
      return 0;
    }
    if (A[i] > bucketSize)
    {
      return 0;
    }
    if (!bucket1Full)
    {
      if (A[i] + bucket1CurrSum == bucketSize)
      {
        // used[i] = 1;
        bucket1.push_back(A[i]);
        bucket1Full = true;
        bucket1CurrSum = bucketSize;
        i++;
        continue;
      }
      else if (A[i] + bucket1CurrSum < bucketSize)
      {
        // used[i] = 1;
        bucket1.push_back(A[i]);
        bucket1CurrSum += A[i];
        i++;
        continue;
      }
    }
    if (!bucket2Full)
    {
      if (A[i] + bucket2CurrSum == bucketSize)
      {
        // used[i] = 1;
        bucket2.push_back(A[i]);
        bucket2CurrSum = bucketSize;
        bucket2Full = true;
        i++;
        continue;
      }
      else if (A[i] + bucket2CurrSum < bucketSize)
      {
        // used[i] = 1;
        bucket2.push_back(A[i]);
        bucket2CurrSum += A[i];
        i++;
        continue;
      }
    }
    if (!bucket3Full)
    {
      if (A[i] + bucket3CurrSum == bucketSize)
      {
        used[i] = 1;
        bucket3.push_back(A[i]);
        bucket3Full = true;
        bucket3CurrSum = bucketSize;
        i++;
        continue;
      }
      else if (A[i] + bucket3CurrSum < bucketSize)
      {
        used[i] = 1;
        bucket3.push_back(A[i]);
        bucket3CurrSum += A[i];
        i++;
        continue;
      }
    }
  }
  //write your code here

  return 1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i)
  {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
