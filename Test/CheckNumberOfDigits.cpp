#include <iostream>
#include <cmath>

using namespace std;

bool Check_HowManyDigits(unsigned int N, const short NumberOfDigits)
{
  unsigned short Counter{0};

  while (N > 0)
  {
    Counter++;
    N /= 10;
  }

  return (Counter == NumberOfDigits);
}

unsigned long long Read_Positive_Int_Number_OfNDigits(const char *Message, short NumberOfDigits)
{
  unsigned long long Number = 0;

  cout << Message;
  cin >> Number;

  while (cin.fail() || !((Number >= 0) && Check_HowManyDigits(Number, NumberOfDigits)))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "-> Invalid Number, Enter A [" << NumberOfDigits << "] Digits Number? |--> ";
    cin >> Number;
  }

  return Number;
}

int main()
{
  unsigned long N{(unsigned long)Read_Positive_Int_Number_OfNDigits("-> Enter A Number: ", 3)};

  cout << N << endl;

  (Check_HowManyDigits(N, 3)) ? cout << "Success" : cout << "Fail";

  return 0;
}