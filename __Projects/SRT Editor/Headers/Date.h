#pragma once

#include "MG_Util.h"

namespace MG
{
  class clsDate
  {
  private:
    short _day, _month;
    int _year;

  private:
    // time struct - hours & min & sec format
    // (5)  --> [05]
    // (15)  --> [15]
    static std::string _clock_frm(int16_t _N)
    {
      std::string Str(std::to_string(_N));
      return !(_N / 10) ? ('0' + Str) : Str;
    }

  public:
    // if the input is not valid will return Sytem_Date
    clsDate() : _day(10), _month(9), _year(1997) {}
    clsDate(const char *date, char delim = '/')
    {

      *this = StringToDate(date, delim);
    }
    clsDate(const std::string &date, char delim = '/')
    {

      *this = StringToDate(date, delim);
    }
    clsDate(short day, short month, int year)
    {

      if (isValidDate(day, month, year))
        _day = day, _month = month, _year = year;
      else
        *this = SystemDate();
    }
    clsDate(uint16_t dayOrder, int year)
    {

      if ((dayOrder > 0 || dayOrder <= YearInDays(year)) && (year > 0))
        *this = DayOrderToDate(dayOrder, year);
      else
        *this = SystemDate();
    }

    // void set_day(short day)
    // {
    //   if (day <= MonthInDays(_year, _month))
    //     _day = day;
    // }
    // short get_day()
    // {
    //   return _day;
    // }
    // __declspec(property(get = get_day, put = set_day)) short day;

    // void set_month(short month)
    // {
    //   if (month >= 1 && month <= 12)
    //     _month = month;
    // }
    // short get_month()
    // {
    //   return _month;
    // }
    // __declspec(property(get = get_month, put = set_month)) short month;

    // void set_year(int year)
    // {
    //   if (year > 0)
    //     _year = year;
    // }
    // int get_year()
    // {
    //   return _year;
    // }
    // __declspec(property(get = get_year, put = set_year)) int year;

    // Date tools

    static uint16_t MonthInDays(int year, short month)
    {
      short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

      return isleapyear(year) && (month == 2) ? 29 : NumberOfDays[month - 1];
    }
    static uint16_t MonthInHours(int year, short month)
    {
      return MonthInDays(year, month) * 24;
    }
    static uint32_t MonthInMinutes(int year, short month)
    {
      return MonthInHours(year, month) * 60;
    }
    static uint32_t MonthInSeconds(int year, short month)
    {
      return MonthInMinutes(year, month) * 60;
    }

    static uint16_t YearInDays(int year)
    {
      return isleapyear(year) ? 366 : 365;
    }
    static uint16_t YearInHours(int year)
    {
      return YearInDays(year) * 24;
    }
    static uint32_t YearInMinutes(int year)
    {
      return YearInHours(year) * 60;
    }
    static uint32_t YearInSeconds(int year)
    {
      return YearInMinutes(year) * 60;
    }

    //------------------------------Read Date------------------------------------
    static int ReadYear(const char *Message = "")
    {
      int year(0);
      std::cout << Message;
      std::cin >> year;

      while (std::cin.fail() || year <= 0)
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "=> Enter A Year > 0:  ";
        std::cin >> year;
      }
      // to discard any non_numerics in the end of input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return year;
    }
    static short ReadMonth(const char *Message = "")
    {
      short Month;
      std::cout << Message;
      std::cin >> Month;

      while (std::cin.fail() || Month < 1 || Month > 12)
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "=> Enter A Month From 1 to 12:  ";
        std::cin >> Month;
      }
      // to discard any non_numerics in the end of input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return Month;
    }
    static short ReadDay(short MonthDays, const char *Message = "")
    {
      short Day;

      std::cout << Message;
      std::cin >> Day;

      while (std::cin.fail() || Day < 1 || Day > MonthDays)
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "=> Enter A Day From 1 to " << MonthDays << ":  ";
        std::cin >> Day;
      }
      // to discard any non_numerics in the end of input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return Day;
    }

    static clsDate read_date(const char *Message = "") noexcept
    {
      clsDate Date;
      std::cout << Message;

      Date._year = ReadYear("=> Enter A Year:  ");
      Date._month = ReadMonth("=> Enter A Month:  ");
      Date._day = ReadDay(MonthInDays(Date._year, Date._month), "=> Enter A Day:  ");

      return Date;
    }

    static std::string read_sdate(char delim = '/')
    {
      std::string strDate;
      printf("Enter A Date (dd%cmm%cyyyy)?  ", delim, delim);
      std::getline(std::cin >> std::ws, strDate);
      return strDate;
    }
    //---------------------------------------------------------------------------

    static short DayOfWeekOrder(short day, short month, int year)
    {
      short a = (14 - month) / 12;
      short y = year - a;
      short m = month + 12 * a - 2;
      return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
    }
    static short DayOfWeekOrder(const clsDate &Date)
    {
      return DayOfWeekOrder(Date._day, Date._month, Date._year);
    }

    static short DayOfYearOrder(short day, short month, int year)
    {
      short TotalDays(0);

      for (short MonthOrder = 1; MonthOrder < month; MonthOrder++)
        TotalDays += MonthInDays(year, MonthOrder);

      return TotalDays + day;
    }
    static short DayOfYearOrder(const clsDate &Date)
    {
      short TotalDays(0);

      for (short month = 1; month < Date._month; month++)
        TotalDays += MonthInDays(Date._year, month);

      return TotalDays + Date._day;
    }

    static clsDate DayOrderToDate(short DayOfYearOrder, int year)
    {
      clsDate Date;
      Date._year = year;
      Date._month = 1;
      short RemainingDays = DayOfYearOrder;
      short MonthDays = 0;

      while (true)
      {
        MonthDays = MonthInDays(year, Date._month);

        if (RemainingDays > MonthDays)
        {
          RemainingDays -= MonthDays;
          Date._month++;
        }
        else
        {
          Date._day = RemainingDays;
          break;
        }
      }
      return Date;
    }

    static std::string day_name(short DayOfWeakOrder)
    {
      const std::string DaysOfWeek[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
      return DaysOfWeek[DayOfWeakOrder];
    }

    static std::string month_name(short Month)
    {
      const std::string Months[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

      return Months[Month];
    }

    static void print_month_calendar(int year, short month)
    {
      short NumberOfDays = MonthInDays(year, month);
      short StartDayOrder = DayOfWeekOrder(1, month, year) + 1; // the order of the first day of the month (0 -> 6)

      std::cout << "\n\n";
      std::cout << "   __________________" << month_name(month) << "__________________\n\n";
      std::cout << "   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n";

      // Print spaces if the first day isn't 'Sun'
      short Count7Days; // This will count 7 days to print '\n'
      for (Count7Days = 1; Count7Days < StartDayOrder; Count7Days++)
        std::cout << "      ";

      // Print the days
      for (short day = 1; day <= NumberOfDays; day++, Count7Days++)
      {
        printf("%6hu", day);

        if (Count7Days == 7)
        {
          std::cout << "\n\n";
          Count7Days = 0;
        }
      }
      std::cout << "\n   _______________________________________\n";
    }
    static void print_year_calendar(int year)
    {
      printf("\n   _______________________________________\n\n");
      printf("             Calendar  -  %4hu", year);
      printf("\n   _______________________________________\n");

      for (short month = 1; month <= 12; month++)
        print_month_calendar(year, month);

      return;
    }

    static clsDate DateAddDays(clsDate &Date, size_t DaysToAdd)
    {
      short YearDays(0), MonthDays(0);

      // Start from the beginning of the year
      size_t RemainingDays = DaysToAdd + DayOfYearOrder(Date._day, Date._month, Date._year);

      Date._month = 1; // Initialize the month

      // Years loop - This loop make the process faster
      while (true)
      {
        if (RemainingDays > (YearDays = YearInDays(Date._year)))
        {
          RemainingDays -= YearDays;
          Date._year++;
        }
        else
          break;
      }

      // Months & Days loop
      while (true)
      {
        if (RemainingDays > (MonthDays = MonthInDays(Date._year, Date._month)))
        {
          RemainingDays -= MonthDays;

          if (Date._month == 12)
            Date._year++, Date._month = 1;
          else
            Date._month++;
        }
        else
        {
          Date._day = (short)RemainingDays;
          break;
        }
      }
      return Date;
    }

    //------------------------------date check---------------------------------
    static bool isleapyear(const int &year)
    {
      return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
    }

    static bool isDate1BeforeDate2(const clsDate &Date1, const clsDate &Date2)
    {
      // return true if (Date1 before Date2)
      return (Date1._year < Date2._year) ? true : ((Date1._year == Date2._year) ? ((Date1._month < Date2._month) ? true : ((Date1._month == Date2._month) ? Date1._day < Date2._day : false)) : false);
    }
    static bool isDate1EqualToDate2(const clsDate &Date1, const clsDate &Date2)
    {
      // return true if (Date1 & Date1 are equal)
      return (Date1._year == Date2._year) && (Date1._month == Date2._month) && (Date1._day == Date2._day);
    }
    static bool isDate1AfterDate2(const clsDate &Date1, const clsDate &Date2)
    {
      return Date1._year > Date2._year ? true : (Date1._year == Date2._year ? (Date1._month > Date2._month ? true : (Date1._month == Date2._month ? Date1._day > Date2._day : false)) : false);
    }

    static bool is_last_day_in_month(const clsDate &Date)
    {
      return (Date._day == MonthInDays(Date._year, Date._month));
    }
    static bool is_last_month_in_year(short month)
    {
      return (month == 12);
    }

    static bool is_end_of_weak(const clsDate &Date)
    {
      // Sat
      return DayOfWeekOrder(Date) == 6;
    }
    static bool is_weak_end(const clsDate &Date)
    {
      // Fri & Sat
      uint16_t DayOrder = DayOfWeekOrder(Date);
      return (DayOrder == 5 || DayOrder == 6);
    }
    static bool is_business(const clsDate &Date)
    {
      return !is_weak_end(Date);
    }

    static bool isValidDate(const clsDate &Date)
    {
      return Date._year > 0 &&
             (Date._month >= 1 && Date._month <= 12) &&
             (Date._day >= 1 && Date._day <= MonthInDays(Date._year, Date._month));
    }
    static bool isValidDate(short day, short month, int year)
    {
      return year > 0 &&
             (month >= 1 && month <= 12) &&
             (day >= 1 && day <= MonthInDays(year, month));
    }

    static bool isValid_strDate(const std::string &strDate, char delim = '/')
    {
      return isValidDate(StringToDate(strDate, delim));
    }

    static bool isDateBetween(const clsDate &Date, clsDate from, clsDate to)
    {
      if (isDate1AfterDate2(from, to))
        return !(isDate1BeforeDate2(Date, to) || isDate1AfterDate2(Date, from));

      return !(isDate1BeforeDate2(Date, from) || isDate1AfterDate2(Date, to));
    }
    //-------------------------------------------------------------------------

    // -----------------------increase date functions--------------------------
    static clsDate AddOneDay(clsDate &Date)
    {
      is_last_day_in_month(Date) ? (is_last_month_in_year(Date._month) ? (Date._day = Date._month = 1, Date._year++) : (Date._day = 1, Date._month++)) : Date._day++;

      return Date;
    }
    static clsDate AddXDays(clsDate &Date, size_t Days)
    {
      for (size_t i = 1; i <= Days; i++)
        AddOneDay(Date);

      return Date;
    }

    static clsDate AddOneWeak(clsDate &Date)
    {
      for (size_t i = 1; i <= 7; i++)
        AddOneDay(Date);

      return Date;
    }
    static clsDate AddXWeaks(clsDate &Date, size_t Weaks)
    {
      for (size_t i = 1; i <= Weaks; i++)
        AddOneWeak(Date);

      return Date;
    }

    static clsDate AddOneMonth(clsDate &Date)
    {
      (Date._month == 12) ? Date._month = 1, Date._year++ : Date._month++;

      short MaxDaysOfTheNewMonth = MonthInDays(Date._year, Date._month);

      if (MaxDaysOfTheNewMonth < Date._day)
        Date._day = MaxDaysOfTheNewMonth;

      return Date;
    }
    static clsDate AddXMonths(clsDate &Date, size_t Months)
    {
      for (size_t i = 1; i <= Months; i++)
        AddOneMonth(Date);

      return Date;
    }

    static clsDate AddOneYear(clsDate &Date)
    {
      (Date._month == 2 && Date._day == 29) ? Date._year++, Date._day-- : Date._year++;
      return Date;
    }
    static clsDate AddXYears(clsDate &Date, size_t Years)
    {
      Date._year += (int)Years;

      if (Date._month == 2 && Date._day == 29)
        if (MonthInDays(Date._year, 2) == 28)
          Date._day--;

      return Date;
    }

    static clsDate AddOneDecade(clsDate &Date)
    {
      // 10 years
      return AddXYears(Date, 10);
    }
    static clsDate AddXDecades(clsDate &Date, size_t Decades)
    {
      return AddXYears(Date, Decades * 10);
    }

    static clsDate AddOneCentury(clsDate &Date)
    {
      // 100 years
      return AddXYears(Date, 100);
    }

    static clsDate AddOneMillennium(clsDate &Date)
    {
      // 1000 years
      return AddXYears(Date, 1000);
    }
    // ------------------------------------------------------------------------

    //---------------------------decrease date functions-----------------------
    static clsDate SubOneDay(clsDate &Date)
    {
      (Date._day == 1) ? ((Date._month == 1) ? Date._day = 31, Date._month = 12, Date._year-- : Date._day = MonthInDays(Date._year, --Date._month)) : Date._day--;

      return Date;
    }
    static clsDate SubXDays(clsDate &Date, size_t Days)
    {
      for (size_t i = 1; i <= Days; i++)
        SubOneDay(Date);

      return Date;
    }

    static clsDate SubOneWeak(clsDate &Date)
    {
      for (size_t i = 1; i <= 7; i++)
        SubOneDay(Date);

      return Date;
    }
    static clsDate SubXWeaks(clsDate &Date, size_t Weaks)
    {
      for (size_t i = 1; i <= Weaks; i++)
        SubOneWeak(Date);

      return Date;
    }

    static clsDate SubOneMonth(clsDate &Date)
    {
      (Date._month == 1) ? Date._month = 12, Date._year-- : Date._month--;

      short MaxDaysOfNewMonth = MonthInDays(Date._year, Date._month);

      if (MaxDaysOfNewMonth < Date._day)
        Date._day = MaxDaysOfNewMonth;

      return Date;
    }
    static clsDate SubXMonths(clsDate &Date, size_t Months)
    {
      for (size_t i = 1; i <= Months; i++)
        SubOneMonth(Date);

      return Date;
    }

    static clsDate SubOneYear(clsDate &Date)
    {
      (Date._month == 2 && Date._day == 29) ? Date._year--, Date._day-- : Date._year--;
      return Date;
    }
    static clsDate SubXYears(clsDate &Date, size_t Years)
    {
      Date._year -= (int)Years;

      if (Date._month == 2 && Date._day == 29)
        if (MonthInDays(Date._year, 2) == 28)
          Date._day--;

      return Date;
    }

    static clsDate SubOneDecade(clsDate &Date)
    {
      return SubXYears(Date, 10);
    }
    static clsDate SubXDecades(clsDate &Date, size_t Decades)
    {
      return SubXYears(Date, Decades * 10);
    }

    static clsDate SubOneCentury(clsDate &Date)
    {
      return SubXYears(Date, 100);
    }

    static clsDate SubOneMillennium(clsDate &Date)
    {
      return SubXYears(Date, 1000);
    }
    // ------------------------------------------------------------------------

    static void Swap2Dates(clsDate &Date1, clsDate &Date2)
    {
      algorithm::swap(Date1, Date2);
    }

    static size_t DiffInDays(clsDate StartDate, clsDate EndDate, bool IncludeEndDay = false)
    {
      // EndDate must be > StartDate
      if (!isDate1BeforeDate2(StartDate, EndDate))
        Swap2Dates(StartDate, EndDate);

      size_t DiffDays = 0;
      int CurrentYear = StartDate._year;

      short StartDateDays = DayOfYearOrder(StartDate);
      short EndDateDays = DayOfYearOrder(EndDate);

      while (CurrentYear < EndDate._year)
        DiffDays += YearInDays(CurrentYear++);

      DiffDays += (size_t)EndDateDays - (size_t)StartDateDays;

      return IncludeEndDay ? ++DiffDays : DiffDays;
    }
    static long long DiffInDays_n(clsDate StartDate, clsDate EndDate, bool includeEndDay = false)
    {
      short Swap2DatesFlagValue(1);

      if (!isDate1BeforeDate2(StartDate, EndDate))
      {
        Swap2Dates(StartDate, EndDate);
        Swap2DatesFlagValue = -1;
      }

      size_t DiffDays(0);
      int CurrentYear = StartDate._year;

      short StartDate_DayOrder = DayOfYearOrder(StartDate);
      short EndDate_DayOrder = DayOfYearOrder(EndDate);

      while (CurrentYear < EndDate._year)
        DiffDays += YearInDays(CurrentYear++);

      DiffDays += (size_t)EndDate_DayOrder - (size_t)StartDate_DayOrder;

      return includeEndDay ? ++DiffDays * Swap2DatesFlagValue : DiffDays * Swap2DatesFlagValue;
    }

    static clsDate SystemDate()
    {
      clsDate DateNow;
      time_t timenow = time(0);
      tm *LocalTime = localtime(&timenow);

      DateNow._year = LocalTime->tm_year + 1900;
      DateNow._month = LocalTime->tm_mon + 1;
      DateNow._day = LocalTime->tm_mday;

      return DateNow;
    }

    static std::string SystemClock()
    {
      time_t timenow = std::time(0);
      tm *LocalTime = std::localtime(&timenow);
      std::string time = _clock_frm(LocalTime->tm_hour) + ':' + _clock_frm(LocalTime->tm_min) + ':' + _clock_frm(LocalTime->tm_sec);
      return time;
    }

    static std::string SystemDate_Time()
    {
      std::string Date_time = DateToString(SystemDate()) + " - " + SystemClock();
      return Date_time;
    }

    static size_t AgeInDays(const clsDate &DateOfBirth)
    {
      return DiffInDays(DateOfBirth, SystemDate());
    }

    //-----------------------------------------days until the end of ....-----------------------------------------
    static short days_until_the_end_of_weak(short day, short month, int year, bool includeEndDay = false)
    {
      if (includeEndDay)
        return ((6 - DayOfWeekOrder(day, month, year)) + 1);
      return (6 - DayOfWeekOrder(day, month, year));
    }
    static short days_until_the_end_of_weak(const clsDate &Date, bool includeEndDay = false)
    {
      if (includeEndDay)
        return ((6 - DayOfWeekOrder(Date)) + 1);
      return (6 - DayOfWeekOrder(Date));
    }

    static short days_until_the_end_of_month(short day, short month, int year, bool includeEndDay = false)
    {
      if (includeEndDay)
        return ((MonthInDays(year, month) - day) + 1);
      return (MonthInDays(year, month) - day);
    }
    static short days_until_the_end_of_month(const clsDate &Date, bool includeEndDay = false)
    {
      if (includeEndDay)
        return ((MonthInDays(Date._year, Date._month) - Date._day) + 1);
      return (MonthInDays(Date._year, Date._month) - Date._day);
    }

    static short days_until_the_end_of_year(short day, short month, int year, bool includeEndDay = false)
    {
      if (includeEndDay)
        ((YearInDays(year) - DayOfYearOrder(day, month, year)) + 1);
      return (YearInDays(year) - DayOfYearOrder(day, month, year));
    }
    static short days_until_the_end_of_year(const clsDate &Date, bool includeEndDay = false)
    {
      if (includeEndDay)
        return ((YearInDays(Date._year) - DayOfYearOrder(Date)) + 1);
      return (YearInDays(Date._year) - DayOfYearOrder(Date));
    }
    //------------------------------------------------------------------------------------------------------------

    static size_t BusinessDays(clsDate from, clsDate to)
    {
      size_t days(0);

      if (isDate1AfterDate2(from, to))
        Swap2Dates(from, to);

      while (isDate1BeforeDate2(from, to))
      {

        if (is_business(from))
          days++;
        AddOneDay(from);
      }
      return days;
    }

    static uint16_t VacationDays(clsDate from, clsDate to)
    {
      return (uint16_t)BusinessDays(from, to);
    }
    static clsDate VacationReturnDate(clsDate from, uint16_t VacationDays)
    {
      while (VacationDays > 0)
      {
        if (is_business(from))
          VacationDays--;
        AddOneDay(from);
      }

      // To fix if the return date is weakend day
      while (is_weak_end(from))
        AddOneDay(from);

      return from;
    }

    //-----------------------------------Dates compare-------------------------------------
    enum CompareResults
    {
      Before = -1,
      Equal = 0,
      After = 1
    };

    static short compare(const clsDate &Date1, const clsDate &Date2)
    {
      return isDate1BeforeDate2(Date1, Date2) ? Before : (isDate1EqualToDate2(Date1, Date2) ? Equal : After);
    }
    //------------------------------------------------------------------------------------

    //-----------------------------------Date Format-------------------------------
    static std::string DateToString(const clsDate &Date, char separator = '/')
    {
      return std::to_string(Date._day) + separator + std::to_string(Date._month) + separator + std::to_string(Date._year);
    }

    static clsDate StringToDate(const std::string &strDate, char delim = '/')
    {
      clsDate Date;
      std::string arrDate[3], temp;
      uint8_t index(0);

      for (const char &C : strDate)
      {
        if (C == delim)
          arrDate[index++] = temp, temp = "";
        else if (std::isdigit(C))
          temp += C; // only store digits

        if (index == 3)
          break; // to store only 3 numbers - day/month/year
      }
      if (temp != "")
        arrDate[index] = temp; // store year

      // Save date - store 0 if empty ""
      Date._day = (arrDate[0] == "") ? 0 : stoi(arrDate[0]);
      Date._month = (arrDate[1] == "") ? 0 : stoi(arrDate[1]);
      Date._year = (arrDate[2] == "") ? 0 : stoi(arrDate[2]);
      return Date;
    }

    // %d -> day, %m -> month, %y -> year
    static std::string frmt_date(const clsDate *const Date, const char *format = "%d/%m/%y")
    {
      // %d -> day, %m -> month, %y -> year
      std::string frmt = format;
      frmt.replace(frmt.find("%d"), 2, std::to_string(Date->_day));   // replace day
      frmt.replace(frmt.find("%m"), 2, std::to_string(Date->_month)); // replace month
      frmt.replace(frmt.find("%y"), 2, std::to_string(Date->_year));  // replace year
      return frmt;
    }
    // %d -> day, %m -> month, %y -> year
    static std::string frmt_date(const char *format, ...)
    {
      std::string frmdate;
      va_list args;           // argument list variable
      va_start(args, format); // initialize argument list variable (args)

      // any string or array of character have a NULL character ('\0') at the end of it
      // if (*format == '\0') this mean that we reach the end
      while (*format != '\0')
      {
        if (*format == '%')
        {
          format++; // make format pointer points to next character of "format"

          // get & convert the value of the next argument to string & push it to "frmdate"
          // %d -> day, %m -> month, %y -> year, %% -> %
          if (*format == 'd')
            frmdate += std::to_string(va_arg(args, int));
          else if (*format == 'm')
            frmdate += std::to_string(va_arg(args, int));
          else if (*format == 'y')
            frmdate += std::to_string(va_arg(args, int));
          else if (*format == '%')
            frmdate += *format;
        }
        else
          frmdate += *format;
        format++; // make format pointer points to next character of "format"
      }
      va_end(args); // End using argument list variable (args)
      return frmdate;
    }
    //-----------------------------------------------------------------------------

    void print() const noexcept
    {
      short _DayOfWeakOrder = DayOfWeekOrder(*this);
      short _DayOfYearOrder = DayOfYearOrder(*this);

      std::cout << "\n-------------------------------\n";
      printf("- Data             : %hi/%hi/%d\n", _day, _month, _year);
      printf("- Day Of Weak Order: %hi\n", _DayOfWeakOrder);
      printf("- Day Of Year Order: %hi\n", _DayOfYearOrder);
      std::cout << "- Day Name         : " << day_name(_DayOfWeakOrder);
      std::cout << "\n- Month Name       : " << month_name(_month);
      std::cout << "\n-------------------------------\n";
    }

    std::string to_string(const char delim = '/') const noexcept
    {
      return DateToString(*this, delim);
    }

    std::string frmt_date(const char *format = "%d/%m/%y") const noexcept
    {
      return frmt_date(this, format);
    }

    short DayOfWeekOrder() const noexcept
    {
      return DayOfWeekOrder(*this);
    }
    short DayOfYearOrder() const noexcept
    {
      return DayOfYearOrder(*this);
    }

    std::string day_name() const
    {
      return day_name(DayOfWeekOrder(*this));
    }
    std::string month_name()
    {
      return month_name(_month);
    }

    void print_month_calendar()
    {
      print_month_calendar(_year, _month);
    }
    void print_year_calendar()
    {
      print_year_calendar(_year);
    }

    bool isleapyear()
    {
      return isleapyear(_year);
    }

    bool isbefore(const clsDate &Date)
    {
      return isDate1BeforeDate2(*this, Date);
    }
    bool isAfter(const clsDate &Date)
    {
      return isDate1AfterDate2(*this, Date);
    }
    bool isequal(const clsDate &Date)
    {
      return isDate1EqualToDate2(*this, Date);
    }

    short compare(const clsDate &Date)
    {
      // (-1) -> before // (0) -> equal // (1) -> after
      return compare(*this, Date);
    }

    bool is_last_day_in_month()
    {
      return is_last_day_in_month(*this);
    }
    bool is_last_month_in_year()
    {
      return is_last_month_in_year(_month);
    }
    bool is_end_of_weak()
    {
      return is_end_of_weak(*this);
    }
    bool is_weak_end()
    {
      return is_weak_end(*this);
    }
    bool is_business()
    {
      return is_business(*this);
    }
    bool is_valid()
    {
      return isValidDate(*this);
    }

    // increament & decrease
    void add_one_day()
    {
      AddOneDay(*this);
    }
    void sub_one_day()
    {
      SubOneDay(*this);
    }

    void swap(clsDate &Date)
    {
      Swap2Dates(*this, Date);
    }

    void add_days(size_t days)
    {
      DateAddDays(*this, days);
    }

    size_t diff(const clsDate &EndDate, bool includeEndDay = false)
    {
      // return only positive value
      return DiffInDays(*this, EndDate, includeEndDay);
    }
    size_t diff_n(const clsDate &EndDate, bool includeEndDay = false)
    {
      // return negative value if _date is after EndDate
      return DiffInDays_n(*this, EndDate, includeEndDay);
    }

    short days_until_the_end_of_weak(bool includeEndDay = false)
    {
      return days_until_the_end_of_weak(*this, includeEndDay);
    }
    short days_until_the_end_of_month(bool includeEndDay = false)
    {
      return days_until_the_end_of_month(*this, includeEndDay);
    }
    short days_until_the_end_of_year(bool includeEndDay = false)
    {
      return days_until_the_end_of_year(*this, includeEndDay);
    }
  };

}