#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// My Solution
int min1(vector<int> list)
{
  // sort form smaller to bigger
  sort(list.begin(), list.end());

  return list.front();
}
int max1(vector<int> list)
{
  // sort form smaller to bigger
  sort(list.begin(), list.end());

  return list.back();
}

// Another Solution
int min2(vector<int> list)
{
  return *min_element(list.begin(), list.end());
}
int max2(vector<int> list)
{
  return *max_element(list.begin(), list.end());
}


// Another Solution
int min3(vector<int> list)
{
  int* ptr = &list.at(0);

  for(int& n : list)
  {
    if(n < *ptr)
      ptr = &n;
  }

  return *ptr;
}
int max3(vector<int> list)
{
  int *ptr = &list.at(0);

  for (int &n : list)
  {
    if (n > *ptr)
      ptr = &n;
  }

  return *ptr;
}

int main()
{
  vector<int> V{78, 54, 13, 640, -85, 76, -371, -180, 49, 10};

  cout << endl
       << endl;

  cout << "Max = " << max3(V) << endl;
  cout << "Min = " << min3(V) << endl;

  cout << endl
       << endl;

  return 0;
}