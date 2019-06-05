#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

bool greater(string a, string b)
{
  return stoi(a + b) > stoi(b + a);
}
string largest_number(vector<string> a)
{
  //write your code here
  std::stringstream ret;
  // std::cout << a.at(0) << "," << a.size() << "\n";
  while (!a.empty())
  {
    string maxDigit = "0";
    int maxPos = 0;
    size_t i = 0;
    for (i = 0; i < a.size(); i++)
    {
      if (greater(a.at(i), maxDigit))
      {
        // std::cout << a.at(i) << " is greater than " << maxDigit << "\n";
        maxDigit = a.at(i);
        maxPos = i;
      }
    }
    ret << maxDigit;
    a.erase(a.begin() + maxPos);
  }
  string result;
  ret >> result;
  return result;
}

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
