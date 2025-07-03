#pragma once
#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include"C:/Users/YUSUF/source/repos/Libraries/clsString.h"
using namespace std;
class clsDate
{
private :
 
	short _Day = 0;
	short _Month = 0;
	short _Year = 0;
public:

	clsDate()
	{
		time_t t = time(0);

		tm* now = localtime(&t);

		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
	}

	clsDate(string Date)
	{
		vector <string> vDate = clsString::Split(Date, "/");
		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short NumberOfDays, short Year)
	{
		clsDate Date  = GetDateFromDayOrderInAYear(NumberOfDays, Year);
		_Day = Date._Day;
		_Month = Date._Month;
		_Year = Date._Year;
	}

	void SetDay(short Day)
	{
		_Day = Day;
	}

	short GetDay()
	{
		return _Day;
	}

	void SetMonth(short Month)
	{
		_Month = Month;
	}

	short GetMonth()
	{
		return _Month;
	}

	void SetYear(short Year)
	{
		_Year = Year;
	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetDay, put = SetDay))short Day;
	__declspec(property(get = GetMonth, put = SetMonth))short Month;
	__declspec(property(get = GetYear, put = SetYear))short Year;

	void Print()
	{
		cout << DateToString() << endl;
	}

	static bool IsLeapYear(short Year)
	{
		return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static clsDate GetDateFromDayOrderInAYear(int DataOrderInYear, short Year)
	{
		clsDate Date;
		int RemainingDays = DataOrderInYear;
		Date._Year = Year;

		Date._Month = 1;
		short MonthDays = 0;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Year, Date._Month);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	
	static short NumberOfDaysInAYear(short Year)
	{
		return (IsLeapYear(Year)) ? 366 : 365;
	}

	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}

	short  NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}

	short NumberOfMinutesInAYear()
	{
		return NumberOfMinutesInAYear(_Year);
	}

	static short NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}

	short NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(_Year);
	}

	static short NumberOfDaysInAMonth(short Year, short Month)
	{
		if (Month < 1 || Month>12)
		{
			return 0;
		}
		short arrNumberOfDays[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : arrNumberOfDays[Month];
	}

	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Year, _Month);
	}

	static short NumberOfHoursInAMonth(short Year, short Month)
	{
		return NumberOfDaysInAMonth(Year, Month) * 24;
	}

	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Year, _Month);
	}

	static short NumberOfMinutesInAMonth(short Year, short Month)
	{
		return NumberOfHoursInAMonth(Year, Month) * 60;
	}

	short NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Year, _Month);
	}

	static short NumberOfSecondsInAMonth(short Year, short Month)
	{
		return NumberOfMinutesInAMonth(Year, Month) * 60;
	}

	short NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Year, _Month);
	}

	static short DayOfWeekOrder(clsDate Date)
	{
		short a = ((14 - Date._Month) / 12);
		short y = Date._Year - a;
		short m = Date._Month + (12 * a) - 2;

		return (Date._Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(*this);
	}

	static string DayOfWeekName(short DayOrder)
	{
		string DaysName[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saterday" };
		return DaysName[DayOrder];
	}

	string DayOfWeekName()
	{
		return DayOfWeekName(DayOfWeekOrder());
	}

	static string MonthOfYearName(short Month)
	{
		string arrNameOfMonths[13] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return arrNameOfMonths[Month];
	}

	string MonthOfYearName()
	{
		return MonthOfYearName(_Month);
	}

	static void PrintMonthCalender(clsDate Date)
	{
		short CurrentDay = DayOfWeekOrder(Date);

		short NumberOfDays = NumberOfDaysInAMonth(Date._Year, Date._Month);

		printf("\n\n  _______________%s_______________\n\n",
			MonthOfYearName(Date._Month).c_str());
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;
		for (i = 0; i < CurrentDay; i++)
		{
			printf("     ");
		}
		for (short j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n __________________________________\n\n");
	}

	void PrintMonthCalender()
	{
		PrintMonthCalender(*this);
	}


	static void PrintMonthCalender(clsDate Date,short Month)
	{
		short CurrentDay = DayOfWeekOrder(Date);

		short NumberOfDays = NumberOfDaysInAMonth(Date._Year, Date._Month);

		printf("\n\n  _______________%s_______________\n\n",
			MonthOfYearName(Date._Month).c_str());
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;
		for (i = 0; i < CurrentDay; i++)
		{
			printf("     ");
		}
		for (short j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n __________________________________\n\n");
	}

	void PrintMonthCalender(short Month)
	{
		PrintMonthCalender(*this,Month);
	}

	static void PrintYearCalender(clsDate Date)
	{
		printf("\n\n  _________________________________\n\n");
		printf("           Calender - %d", Date._Year);
		printf("\n  _________________________________\n");
		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalender(Date,i );
		}

	}

	void PrintYearCalender()
	{
		PrintYearCalender(*this);
	}

	static int NumberOfDaysFormTheBeginingOfTheYear(short Year, short Month, short Day)
	{
		int TotalDays = 0;
		for (short i = 1; i < Month; i++)
		{
			TotalDays += NumberOfDaysInAMonth(Year, i);
		}
		TotalDays += Day;
		return TotalDays;
	}

	int NumberOfDaysFormTheBeginingOfTheYear()
	{
		return NumberOfDaysFormTheBeginingOfTheYear(_Year, _Month, _Day);
	}

	static clsDate AddDaysToDate(clsDate Date, int DaysToAdd)
	{
		int RemainingDays = DaysToAdd + NumberOfDaysFormTheBeginingOfTheYear(Date._Year, Date._Month, Date._Day);
		Date._Month = 1;
		int MonthDays = 0;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._Year, Date._Month);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;

				if (Date._Month > 12)
				{
					Date._Year++;
					Date._Month = 1;
				}

			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	void AddDaysToDate(int DaysToAdd)
	{
		AddDaysToDate(*this, DaysToAdd);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month) ?
			true : (Date1._Month == Date2._Month) ? (Date1._Day < Date2._Day) : false : false);
	}

    bool IsDate1BeforeDate2(clsDate Date2)
	{
		IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualsToDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}

	bool IsDate1EqualsToDate2(clsDate Date2)
	{
		return IsDate1EqualsToDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date._Day == NumberOfDaysInAMonth(Date._Year, Date._Month));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static clsDate IncreasDateByOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Day = 1;
				Date._Month = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month = 1;
			}
		}
		else
		{
			Date._Day++;
		}
		return Date;
	}

	void IncreasDateByOneDay()
	{
		IncreasDateByOneDay(*this);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate Temp;

		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludEndDay = false)
	{

		long Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreasDateByOneDay(Date1);
		}

		return (IncludEndDay) ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludEndDay);
	}

	static int CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		clsDate CurrentDate = GetSystemDate();
		return GetDifferenceInDays(DateOfBirth, CurrentDate, 1);
	}

	static clsDate GetSystemDate()
	{
		short Day, Month, Year;
		time_t t = time(0);

		tm* now = localtime(&t);

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return clsDate(Day, Month, Year);
	}


	static clsDate IncreaseDateByXDays(clsDate &Date, int HowManyDays)
	{
		for (int i = 1; i <= HowManyDays; i++)
		{
			Date = IncreasDateByOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByXDays(int HowManyDays)
	{
		 IncreaseDateByXDays(*this, HowManyDays);
	}

	static clsDate IncreaseDateByOneWeek(clsDate & Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = IncreasDateByOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}


	static clsDate IncreasDateByXWeeks(clsDate &Date, short HowManyWeeks)
	{
		for (short i = 1; i <= HowManyWeeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreasDateByXWeeks(int HowManyWeeks)
	{
		IncreasDateByXWeeks(*this, HowManyWeeks);
	}

	static clsDate IncreaseDateByOneMonth(clsDate &Date)
	{
		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}

		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void IncreaseDateByOneMonth()
	{
		 IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreasDateByXMonths(clsDate& Date, int HowManyMonths)
	{
		for (short i = 1; i <= HowManyMonths; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreasDateByXMonths(int HowManyMonths)
	{
		 IncreasDateByXMonths(*this, HowManyMonths);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date._Year++;
		return Date;
	}

	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	
	static clsDate IncreaseDateByXYears(clsDate &Date, short HowManyYears)
	{
		Date._Year += HowManyYears;
		return Date;
	}

	void IncreaseDateByXYears(int HowManyMonths)
	{
		 IncreaseDateByXYears(*this, HowManyMonths);
	}

	static clsDate IncreaseDateByOneDecade(clsDate &Date)
	{
		Date._Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}


	static clsDate IncreaseDateByXDecades(clsDate &Date, short HowManyDecades)
	{
		Date._Year += (HowManyDecades * 10);
		return Date;
	}

	void IncreaseDateByXDecades(int HowManyMonths)
	{
		 IncreaseDateByXDecades(*this, HowManyMonths);
	}

	static clsDate IncreaseDateByOneCentury(clsDate &Date)
	{
		Date._Year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}


	static clsDate IncreaseDateByOneMillennium(clsDate &Date)
	{
		Date._Year += 1000;
		return Date;
	}


	void IncreaseDateByOneMillennium()
	{
		 IncreaseDateByOneMillennium(*this);
	}

	static bool IsFirstMonthInYear(short Month)
	{
		return (Month == 1);
	}

	bool IsFirstMonthInYear()
	{
		return IsFirstMonthInYear(_Month);
	}

	static bool IsFirstDayInMonth(clsDate Date)
	{
		return (Date._Day == 1);
	}

	bool IsFirstDayInMonth()
	{
		return IsFirstDayInMonth(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate &Date)
	{
		if (IsFirstDayInMonth(Date))
		{
			if (IsFirstMonthInYear(Date._Month))
			{
				Date._Day = 31;
				Date._Month = 12;
				Date._Year--;
			}
			else
			{
				Date._Month--;
				Date._Day = NumberOfDaysInAMonth(Date._Year, Date._Month);
			}
		}
		else
		{
			Date._Day--;
		}
		return Date;
	}

	void DecreaseDateByOneDay()
	{
		 DecreaseDateByOneDay(*this);
	}


	static clsDate DecreaseDateByXDays(clsDate &Date, int HowManyDays)
	{
		for (int i = 1; i <= HowManyDays; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXDays(int HowManyDays)
	{
		 DecreaseDateByXDays(*this,HowManyDays);
	}


	static clsDate DecreaseDateByOneWeek(clsDate &Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		 DecreaseDateByOneWeek(*this);
	}


	static clsDate DecreaseDateByXWeeks(clsDate &Date, short HowManyWeeks)
	{
		for (short i = 1; i <= HowManyWeeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(short HowManyWeeks)
	{
		 DecreaseDateByXWeeks(*this, HowManyWeeks);
	}

	static clsDate DecreaseDateByOneMonth(clsDate &Date)
	{
		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
		{
			Date._Month--;
		}
		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date._Year, Date._Month);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		 DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate &Date, short HowManyMonths)
	{
		for (short i = 1; i <= HowManyMonths; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short HowManyMonths)
	{
		 DecreaseDateByXMonths(*this, HowManyMonths);
	}


	static clsDate DecreaseDateByOneYear(clsDate &Date)
	{
		Date._Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate &Date, short HowManyYears)
	{
		Date._Year -= HowManyYears;
		return Date;
	}

	void DecreaseDateByXYears(short HowManyYears)
	{
		 DecreaseDateByXYears(*this, HowManyYears);
	}


	static clsDate DecreaseDateByOneDecade(clsDate &Date)
	{
		Date._Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		 DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(clsDate &Date, short HowManyDecades)
	{
		Date._Year -= (HowManyDecades * 10);
		return Date;
	}

	void DecreaseDateByXDecades(short HowManyDecades)
	{
		 DecreaseDateByXDecades(*this, HowManyDecades);
	}

	static clsDate DecreaseDateByOneCentury(clsDate &Date)
	{
		Date._Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		 DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate &Date)
	{
		Date._Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		 DecreaseDateByOneMillennium(*this);
	}

	static short DaysUntilEndOfYear(clsDate Date)
	{
		clsDate EndOfYearDate;

		EndOfYearDate._Day = 31;
		EndOfYearDate._Month = 12;
		EndOfYearDate._Year = Date._Year;

		return GetDifferenceInDays(Date, EndOfYearDate, true);
	}

	short DaysUntilEndOfYear()
	{
		return DaysUntilEndOfYear(*this);
	}

	static short DaysUntilEndOfWeek(clsDate Date)
	{
		return 6 - (DayOfWeekOrder(Date));
	}

	short DaysUntilEndOfWeek()
	{
		return DaysUntilEndOfWeek(*this);
	}


	static short DaysUntilEndOfMonth(clsDate Date)
	{
		clsDate EndOfMonthDate;

		EndOfMonthDate._Day = NumberOfDaysInAMonth(Date._Year, Date._Month);
		EndOfMonthDate._Month = Date._Month;
		EndOfMonthDate._Year = Date._Year;

		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	}

	short DaysUntilEndOfMonth()
	{
		return DaysUntilEndOfMonth(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		/*short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex >= 0 && DayIndex <= 4);*/

		return (!IsWeekEnd(Date));
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return (DayOfWeekOrder(Date) == 6);
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static short CalculateBusinessDadys(clsDate DateFrom, clsDate DateTo)
	{
		short DaysCount = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;

			DateFrom = IncreasDateByOneDay(DateFrom);
		}
		return DaysCount;
	}

	static short CalculateActualVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		return CalculateBusinessDadys(DateFrom, DateTo);
	}

	static clsDate  GetReturnFromVacatoinToWorkDate(clsDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		// ensure that we don't start with weekend
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreasDateByOneDay(DateFrom);
		}

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{
			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreasDateByOneDay(DateFrom);
		}
		//ensure that we don't finish with weekend
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreasDateByOneDay(DateFrom);
		}

		return DateFrom;
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualsToDate2(Date1, Date2));
	}

	bool IsDate1AfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

    enum enComparisonResult { eBefore = -1, eEqual = 0, eAfter = 1 };

	static enComparisonResult CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
		{
			return enComparisonResult::eBefore;
		}
		if (IsDate1EqualsToDate2(Date1, Date2))
		{
			return enComparisonResult::eEqual;
		}
		return enComparisonResult::eAfter;
	}

	enComparisonResult CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	}

	static bool IsValidDate(clsDate Date)
	{
		if (Date._Year < 1)
		{
			return false;
		}
		if (Date._Month < 1 || Date._Month > 12)
		{
			return false;
		}
		if (Date._Day<1 || Date._Day > NumberOfDaysInAMonth(Date._Year, Date._Month))
		{
			return false;
		}
		return true;
	}

	bool IsValid()
	{
		return IsValidDate(*this);
	}

	static clsDate StringToDateStatic(string DateString)
	{
		clsDate Date;

		vector <string> vDateString = clsString::Split(DateString, "/");

		Date._Day = stoi(vDateString[0]);
		Date._Month = stoi(vDateString[1]);
		Date._Year = stoi(vDateString[2]);


		return Date;

	}

	void StringToDate(string DateString)
	{
		*this = StringToDateStatic(DateString);
    }


	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + '/' + to_string(Date._Month) + '/' + to_string(Date._Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";
		FormattedDateString = clsString::ReplaceWord(DateFormat, "dd", to_string(Date._Day));
		FormattedDateString = clsString::ReplaceWord(FormattedDateString, "mm", to_string(Date._Month));
		FormattedDateString = clsString::ReplaceWord(FormattedDateString, "yyyy", to_string(Date._Year));

		return FormattedDateString;
	}

	string FormatDate(string DateFormat = "dd/mm/yyyy")
	{
		return FormatDate(*this, DateFormat);
	}

};

