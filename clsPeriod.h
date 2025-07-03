#pragma once
#include<iostream>
#include<string>
#include"C:/Users/YUSUF/source/repos/Libraries/clsDate.h"
using namespace std;
class clsPeriod
{
private:
	clsDate _StartDate;
	clsDate _EndDate;
public:


	clsPeriod(clsDate EndDate)
	{
		_StartDate = clsDate::GetSystemDate();
		_EndDate = EndDate;
	}

	clsPeriod(clsDate StartDate,clsDate EndDate)
	{
		_StartDate = StartDate;
		_EndDate = EndDate;
	}

	clsPeriod(string StartDate, string EndDate)
	{
		_StartDate = clsDate::StringToDateStatic(StartDate);
		_EndDate = clsDate::StringToDateStatic(EndDate);
	}

	void SetStartDate(clsDate Date)
	{
		_StartDate = Date;
	}

	clsDate GetStartDate()
	{
		return _StartDate;
	}

	void SetEndDate(clsDate Date)
	{
		_EndDate = Date;
	}

	clsDate GetEndDate()
	{
		return _EndDate;
	}

	__declspec(property(get = GetStartDate, put = SetStartDate)) clsDate StartDate;
	__declspec(property(get = GetEndDate, put = SetEndDate)) clsDate EndDate;

	static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
	{
		if (
			clsDate::CompareDates(Period1._StartDate, Period2._EndDate) == clsDate::enComparisonResult::eAfter
			||
			clsDate::CompareDates(Period2._EndDate, Period1._StartDate) == clsDate::enComparisonResult::eBefore
			)
			return false;
		else
			return true;
	}

	bool IsOverlapPeriods(clsPeriod Period2)
	{
		return IsOverlapPeriods(*this, Period2);
	}

	static int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDay = false)
	{
		return clsDate::GetDifferenceInDays(Period._StartDate, Period._EndDate, IncludeEndDay);
	}

	int PeriodLengthInDays(bool IncludeEndDay = false)
	{
		return PeriodLengthInDays(*this, IncludeEndDay);
	}

	static bool IsDateInPeriod(clsPeriod Period, clsDate DateToCheck)
	{
		return !(clsDate::CompareDates(DateToCheck, Period._StartDate) == clsDate::enComparisonResult::eBefore
			||
			clsDate::CompareDates(DateToCheck, Period._EndDate) == clsDate::enComparisonResult::eAfter
			);
	}

	bool IsDateInPeriod(clsDate DateToCheck)
	{
		return IsDateInPeriod(*this, DateToCheck);
	}

	static int CountOverLapDays(clsPeriod Period1, clsPeriod Period2)
	{
		int OverLapDays = 0;
		int Period1Lenght = PeriodLengthInDays(Period1, true);
		int Period2Lenght = PeriodLengthInDays(Period2, true);

		if (!IsOverlapPeriods(Period1, Period2))
			return 0;

		if (Period1Lenght < Period2Lenght)
		{
			while (clsDate::IsDate1BeforeDate2(Period1._StartDate, Period1._EndDate))
			{
				if (IsDateInPeriod(Period2, Period1._StartDate))
					OverLapDays++;

				Period1._StartDate = clsDate::IncreasDateByOneDay(Period1._StartDate);
			}
		}
		else
		{
			while (clsDate::IsDate1BeforeDate2(Period2._StartDate, Period2._EndDate))
			{
				if (IsDateInPeriod(Period1, Period2._StartDate))
					OverLapDays++;

				Period2._StartDate = clsDate::IncreasDateByOneDay(Period2._StartDate);
			}
		}
		return OverLapDays;
	}

	int CountOverLapDays(clsPeriod Period2)
	{
		return CountOverLapDays(*this, Period2);
	}

};

