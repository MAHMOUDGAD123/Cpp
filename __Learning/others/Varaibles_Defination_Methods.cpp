#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  // Integer & float
  int i1 = 10;
  int i2(10);
  int i3{10};
  float f1 = 10.5;
  float f2(10.5);
  float f3{10.5};

  // char
  char c1 = 'M';
  char c2('M');
  char c3{'M'};

  // string
  string s1 = "Mahmoud";
  string s2{"Mahmoud"};
  string s3("Mahmoud");
  string s4(7, 'M'); // MMMMMMM
  char s5[8] = "Mahmoud";
  char s6[] = "Mahmoud";
  char s7[8]("Mahmoud");

  // Vector
  vector<int> V1 = {1, 2, 3, 4, 5, 6, 7};
  vector<int> V2{1, 2, 3, 4, 5, 6, 7};
  vector<int> V3(7, 3); // { 3,3,3,3,3,3,3 }

  // Array
  int arr1[7] = {1, 2, 3, 4, 5, 6, 7};
  int arr2[]{1, 2, 3, 4, 5, 6, 7};

  return 0;
}