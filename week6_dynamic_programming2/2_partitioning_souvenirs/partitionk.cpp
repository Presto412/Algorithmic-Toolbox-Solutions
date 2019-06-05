#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
struct bucket
{
    int currentSum = 0;
    bool bucketFull = false;
    vector<int> values;
};
bool compareFunc(int a, int b)
{
    return a >= b;
}
void print(vector<bucket> b)
{
    for (auto x : b)
    {
        std::cout << x.currentSum << "," << x.bucketFull << ", values:";
        for (auto y : x.values)
        {
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int partition3(vector<int> &A, int k)
{
    int sum = 0;
    for (auto x : A)
    {
        sum += x;
    }
    if (sum % k != 0)
    {
        return 0;
    }
    int bucketSize = sum / k;
    vector<bucket> buckets(k);
    std::sort(A.begin(), A.end(), compareFunc);
    for (size_t i = 0; i < A.size(); i++)
    {
        print(buckets);
        if (i > A.size() - 1)
        {
            return 0;
        }
        if (A[i] > bucketSize)
        {
            return 0;
        }
        for (size_t j = 0; j < buckets.size(); j++)
        {
            if (A[i] + buckets[j].currentSum == bucketSize)
            {
                buckets[j].values.push_back(A[i]);
                buckets[j].bucketFull = true;
                buckets[j].currentSum = bucketSize;
                break;
            }
            else if (A[i] + buckets[j].currentSum < bucketSize)
            {
                buckets[j].values.push_back(A[i]);
                buckets[j].currentSum += A[i];
                break;
            }
        }
    }
    for (size_t j = 0; j < buckets.size(); j++)
    {
        if (!buckets[j].bucketFull)
            return 0;
    }

    return 1;
}

int main()
{
    int n;
    // std::cin >> n;
    vector<int> A = {10, 10, 10, 7, 7, 7, 7, 7, 7, 6, 6, 6};
    // for (size_t i = 0; i < A.size(); ++i)
    // {
    //     std::cin >> A[i];
    // }
    std::cout << partition3(A, 3) << '\n';
}
