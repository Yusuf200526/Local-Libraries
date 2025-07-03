#pragma once
#include<iostream>
#include<string>
#include"C:/Users/YUSUF/source/repos/Libraries/clsPeriod.h"
#include"C:/Users/YUSUF/source/repos/Libraries/clsDate.h"
class clsInputValidate
{
public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate DateToCheck,clsDate DateFrom,clsDate DateTo)
	{
		return clsPeriod::IsDateInPeriod(clsPeriod(DateFrom, DateTo), DateToCheck);
	}

	static bool IsDateBetween(clsDate DateToCheck,clsPeriod Period)
	{
		return clsPeriod::IsDateInPeriod(Period, DateToCheck);
	}

	static int ReadIntNumber(string Message="Invalid Number , please Enter Again ")
	{
		int Number = 0;
		while (!(cin>>Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message;
		}
		return Number;
	}

	static double ReadDblNumber(string Message = "Invalid Number , please Enter Again ")
	{
		double Number = 0;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message;
		}
		return Number;
	}

	static int ReadPostiveIntNumber(string Message = "Invalid Number , please Enter Again ")
	{
		int Number = 0;
		Number = ReadIntNumber();
		while (Number<0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadPostiveDblNumber(string Message = "Invalid Number , please Enter Again ")
	{
		double Number = 0;
		Number = ReadDblNumber();
		while (Number < 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To,string Message = "Invalid Number , please Enter Again ")
	{
		int Number = 0;
		Number = ReadIntNumber();
		while(!(IsNumberBetween(Number,From,To)))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message;
			Number = ReadIntNumber();
		}
		return Number;
	}


	static double  ReadDblNumberBetween( double From, double To,string Message = "Invalid Number , please Enter Again ")
	{
		double Number = 0;
		Number = ReadIntNumber();
		while (!(IsNumberBetween(Number, From, To)))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static void ReadArrayIntElements(int Arr1[100], int& Length,string Message = "Invalid Number , please Enter Again ")
	{
		cout << "How Many Integer Numbers do you want to enter? 1 to 100?  ";
		Length = ReadIntNumber();
		for (int i = 0; i <= Length - 1; i++)
		{
			Arr1[i] = ReadIntNumber();
		}
	}

	static void ReadArrayIntPositiveElements(int Arr1[100], int& Length,string Message = "Invalid Number , please Enter Again ")
	{
		cout << "How Many Integer Numbers do you want to enter? 1 to 100?  ";
		Length = ReadIntNumber();
		for (int i = 0; i <= Length - 1; i++)
		{
			Arr1[i] = ReadIntNumber();
			while (Arr1[i]<0)
			{
				cout << Message;
				Arr1[i] = ReadIntNumber();
			}
		}
	}

	static void ReadArrayDblElements(double Arr1[100], int& Length)
	{
		cout << "How Many Integer Numbers do you want to enter? 1 to 100?  ";
		Length = ReadIntNumber();
		for (int i = 0; i <= Length - 1; i++)
		{
			Arr1[i] = ReadDblNumber();
		}

	}

	static void ReadArrayDblPositiveElements(double Arr1[100], int& Length,string Message = "Invalid Number , please Enter Again ")
	{
		cout << "How Many Integer Numbers do you want to enter? 1 to 100?  ";
		Length = ReadIntNumber();
		for (int i = 0; i <= Length - 1; i++)
		{
			Arr1[i] = ReadDblNumber();
			while (Arr1[i] < 0)
			{
				cout << Message;
				Arr1[i] = ReadDblNumber();
			}
		}

	}

	static char ReadCharacter()
	{
		char C1;
		cout << "Please Enter your character ?\n";
		cin >> C1;
		return C1;
	}

	static string ReadString()
	{
		string S1 = "";
		getline(cin>>ws, S1);
		return S1;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	

};

