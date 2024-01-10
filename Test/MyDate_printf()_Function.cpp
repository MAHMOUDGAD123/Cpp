#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstdarg>

using namespace std;

// for more visit --->  https://cplusplus.com/reference/cstdarg/

struct sDate
{
  unsigned short Day = 0, Month = 0;
  size_t Year = 0;
};

bool IsDigit(char C)
{
  return (C >= 48 && C <= 57);
}

bool IsLeapYear(size_t Year)
{
  // if (Year % 400 == 0) => true  ---  Year is a leap year
  // else if (Year % 4 == 0) => true  ---  Year is a leap year if (Year % 100 != 0) => true

  return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0));
}

unsigned short NumberOfDaysInAMonth(size_t year, unsigned short month)
{
  unsigned short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  return IsLeapYear(year) && (month == 2) ? 29 : NumberOfDays[month - 1];
}

bool IsValidDate(sDate Date)
{
  return Date.Year > 0 &&
         (Date.Month >= 1 && Date.Month <= 12) &&
         (Date.Day >= 1 && Date.Day <= NumberOfDaysInAMonth(Date.Year, Date.Month));
}

string ReadStringDate(const char *Message = "")
{
  string strDate;
  cout << Message;
  getline(cin >> ws, strDate);
  return strDate;
}

sDate StringToDate(const string &strDate)
{
  // With validation
  sDate Date;
  string arrDate[3], tempstr = "";
  unsigned short Index = 0;

  for (const char &C : strDate)
  {
    if (C == '/')
      arrDate[Index++] = tempstr, tempstr = "";
    else if (IsDigit(C))
      tempstr += C; // only store digits

    if (Index == 3)
      break; // to store only 3 numbers - day/month/year
  }
  if (tempstr != "")
    arrDate[Index] = tempstr; // store year

  // Save date - store 0 if empty ""
  Date.Day = (arrDate[0] == "") ? 0 : stoi(arrDate[0]);
  Date.Month = (arrDate[1] == "") ? 0 : stoi(arrDate[1]);
  Date.Year = (arrDate[2] == "") ? 0 : stoi(arrDate[2]);

  // make sure that this date is a valid date - ask user to enter again if invalid (unsing recursion)
  return (IsValidDate(Date)) ? Date : StringToDate(ReadStringDate("Invalid Date, Enter Again (dd/mm/yyyy)?  "));
}

// %d -> day, %m -> month, %y -> year
string FormatDate(const sDate *Date, const char *format = "%d/%m/%y")
{
  string frm = format;
  frm = frm.replace(frm.find("%d"), 2, to_string(Date->Day));   // replace day
  frm = frm.replace(frm.find("%m"), 2, to_string(Date->Month)); // replace month
  frm = frm.replace(frm.find("%y"), 2, to_string(Date->Year));  // replace year
  return frm;
}

string frmtDate(const char *format, ...)
{
  string frmdate;
  va_list args;           // argument list variable
  va_start(args, format); // initialize argument list variable (args)

  // any string or array of character have a NULL character ('\0') at the end of it
  // if (*format == '\0') this mean that we reach the end
  while (*format != '\0')
  {
    if (*format == '%')
    {
      format++; // make format pointer pionts to next character of "format"

      // get & convert the value of the next argument to string & push it to "frmdate"
      // %d -> day, %m -> month, %y -> year, %% -> %
      if (*format == 'd')
        frmdate += to_string(va_arg(args, int));
      else if (*format == 'm')
        frmdate += to_string(va_arg(args, int));
      else if (*format == 'y')
        frmdate += to_string(va_arg(args, int));
      else if (*format == '%')
        frmdate += *format;
    }
    else
      frmdate += *format;
    format++; // make format pointer pionts to next character of "format"
  }
  va_end(args); // End using argument list variable (args)
  return frmdate;
}



int main(void)
{
  sDate Date;

  /*for (;;)
  {
    Date = StringToDate(ReadStringDate("Please, Enter Date (dd/mm/yyyy)?  "));

    cout << '\n' << FormatDate(&Date) << '\n';
    cout << '\n' << FormatDate(&Date, "%d-%m-%y") << '\n';
    cout << '\n' << FormatDate(&Date, "Day:%d month:%m year:%y") << '\n';

    printf("\n\n-----------------------------------------------------------\n\n");
  }*/

  for (;;)
  {
    Date = StringToDate(ReadStringDate("Please, Enter Date (dd/mm/yyyy)?  "));

    // format using frmDate() function
    cout << frmtDate("\n- Today is: %d-%m-%y so 100%% Tomorrow Is: %d-%m-%y", Date.Day, Date.Month, Date.Year, Date.Day + 1, Date.Month, Date.Year);

    // format using C++ printf() function
    printf("\n- Today is: %hu-%hu-%llu so 100%% Tomorrow Is: %hu-%hu-%llu", Date.Day, Date.Month, Date.Year, Date.Day + 1, Date.Month, Date.Year);

    printf("\n\n-----------------------------------------------------------\n\n");
  }

  return 0;
}