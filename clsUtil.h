#pragma once
#include<iostream>
#include<string>
#include"C:\Users\YUSUF\My Repos\LIbraries\clsDate.h"
using namespace std;
class clsUtil
{
public:
	enum enCharType { CapitalLetter = 1, SmallLetter = 2, Digit = 3, SpecialCharacter = 4, MixChars = 5 };

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		//function to generate random Number in Range. 
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));
		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));
		case enCharType::Digit:
			return char(RandomNumber(48, 57));
		case enCharType::SpecialCharacter:
			return char(RandomNumber(33, 47));
		case enCharType::MixChars:
			return char(RandomNumber(33, 122));
		default:
			return char(RandomNumber(33, 47));
		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string word = "";
		for (int i = 1; i <= Length; i++)
		{
			word = word + GetRandomCharacter(CharType);
		}
		return word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key = "";
		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);
		return Key;
	}

	static void GenerateKeys(int NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : " << GenerateKey(CharType) << "\n";
		}
	}

	static void Swap(int& Num1, int& Num2)
	{
		int Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}

	static void Swap(double& Num1, double& Num2)
	{
		double Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;
	}

	static void Swap(string& S1, string& S2)
	{
		string Temp;
		Temp = S1;
		S1 = S2;
		S2 = Temp;
	}

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate Temp;
		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}

	static void ShuffleArray(int arrElements[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arrElements[RandomNumber(1, arrLength) - 1], arrElements[RandomNumber(1, arrLength) - 1]);  //important idea // swaping between indexis randomly
		}
	}

	static void ShuffleArray(string arrElements[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arrElements[RandomNumber(1, arrLength) - 1], arrElements[RandomNumber(1, arrLength) - 1]);  //important idea // swaping between indexis randomly
		}
	}

	static void FillArrayWithRandomNumbers(int arrElements[100], short arrLength, short NumbersFrom, short NumbersTo)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arrElements[i] = RandomNumber(NumbersFrom, NumbersTo);
		}
		cout << endl;
	}

	static void FillArrayWithRandomKeys(string arrKeys[100], int NumberOfKeys, enCharType CharType) // make it Random Keys and Random word 
	{
		for (int i = 0; i < NumberOfKeys; i++)
		{
			arrKeys[i] = GenerateKey(CharType);
		}
	}

	static void FillArrayWithRandomWords(string arrKeys[100], int NumberOfWords, enCharType CharType, short WordLength) // make it Random Keys and Random word 
	{
		for (int i = 0; i < NumberOfWords; i++)
		{
			arrKeys[i] = GenerateWord(CharType, WordLength);
		}
	}

	static void Tabs(short NumberOfTabs)
	{
		for (short i = 1; i <= NumberOfTabs; i++)
		{
			cout << "\t";
		}
	}

	static string  EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static string DecryptText(string EncryptedText, short EncryptionKey)
	{

		for (int i = 0; i < EncryptedText.length(); i++)
		{
			EncryptedText[i] = char((int)EncryptedText[i] - EncryptionKey);
		}
		return EncryptedText;
	}

	static void PrintArray(string arr[100], short Length, string Seperater = "")
	{
		for (short i = 0; i < Length; i++)
		{
			cout << arr[i] << Seperater;
		}
	}

	static void PrintArray(int arr[100], short Length, string Seperater = "")
	{
		for (short i = 0; i < Length; i++)
		{
			cout << arr[i] << Seperater;
		}
	}

	static string NumberToText(long long  Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"
			,"Ten","Eleven","Twelve","Thirteen","Fourteen",
			"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return arr[Number] + "";
		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return " One hundred " + NumberToText(Number % 100) + "";
		}
		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + " hundred " + NumberToText(Number % 100) + "";
		}
		if (Number >= 1000 && Number <= 1999)
		{
			return " One thousand " + NumberToText(Number % 1000) + "";
		}
		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + " thousand " + NumberToText(Number % 1000) + "";
		}
		if (Number >= 1000000 && Number <= 1999999)
		{
			return " One million " + NumberToText(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + " million " + NumberToText(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return " One billion " + NumberToText(Number % 1000000000);
		}
		if (Number >= 2000000000 && Number <= 999999999999)
		{
			return NumberToText(Number / 1000000000) + " billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return "";
		}
	}

};

