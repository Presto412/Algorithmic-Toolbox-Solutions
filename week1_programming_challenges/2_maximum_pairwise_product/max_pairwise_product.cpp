#include <iostream>
#include <vector>
#include <algorithm>

long long int MaxPairwiseProduct(const std::vector<int> &numbers)
{
    long long int max_product = 0;
    int n = numbers.size();
    int first = -1;
    int second = -1;
    for (int i = 0; i < n; i++)
    {
        int number = numbers.at(i);
        if (number > first)
        {
            second = first;
            first = number;
        }
        else if (number > second)
        {
            second = number;
        }
    }

    max_product = ((long long)first) * second;
    return max_product;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
