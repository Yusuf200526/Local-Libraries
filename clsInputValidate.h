#pragma once
#include<iostream>
#include<string>
#include"C:\Users\YUSUF\My Repos\LIbraries\clsPeriod.h"
#include"C:\Users\YUSUF\My Repos\LIbraries\clsDate.h"
class clsInputValidate
{
public:

	template <typename T> 
	static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsDateBetween(clsDate DateToCheck, clsDate DateFrom, clsDate DateTo)
	{
		return clsPeriod::IsDateInPeriod(clsPeriod(DateFrom, DateTo), DateToCheck);
	}

	static bool IsDateBetween(clsDate DateToCheck, clsPeriod Period)
	{
		return clsPeriod::IsDateInPeriod(Period, DateToCheck);
	}

	template <typename T> 
	static T ReadNumber(string Message = "Invalid Number , please Enter Again ")
	{
		T Number = 0;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message;
		}
		return Number;
	}

	template <typename T>
	static T ReadPostiveNumber(string Message = "Invalid Number , please Enter Again ")
	{
		T Number = 0;
		Number = ReadNumber<T>();
		while (Number < 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message;
			Number = ReadNumber<T>();
		}
		return Number;
	}

	template <typename T>
	static T ReadNumberBetween(T From, T To, string Message = "Invalid Number , please Enter Again ")
	{
		T Number = 0;
		Number = ReadNumber<T>();
		while (!(IsNumberBetween(Number, From, To)))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message;
			Number = ReadNumber<T>();
		}
		return Number;
	}

	template <typename T>
	static void ReadArrayElements(T Arr1[100], T& Length, string Message = "Invalid Number , please Enter Again ")
	{
		cout << "How Many Integer Numbers do you want to enter? 1 to 100?  ";
		Length = ReadNumber<T>();
		for (int i = 0; i <= Length - 1; i++)
		{
			Arr1[i] = ReadNumber<T>();
		}
	}

	template <typename T>
	static void ReadArrayPositiveElements(T Arr1[100], T& Length, string Message = "Invalid Number , please Enter Again ")
	{
		cout << "How Many  Numbers do you want to enter? 1 to 100?  ";
		Length = ReadNumber<T>();
		for (int i = 0; i <= Length - 1; i++)
		{
			Arr1[i] = ReadNumber<T>();
			while (Arr1[i] < 0)
			{
				cout << Message;
				Arr1[i] = ReadNumber<T>();
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
		getline(cin >> ws, S1);
		return S1;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}



};

