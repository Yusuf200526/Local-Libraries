#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class clsString
{
private:
 
	string _Value;
	string _PreviousValue;

public:

	clsString()
	{

	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


	static char InvertLetterCase(char Character)
	{
		return (isupper(Character)) ? tolower(Character) : toupper(Character);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);
		return (Ch1 == 'a' || Ch1 == 'e' || Ch1 == 'i' || Ch1 == 'o' || Ch1 == 'u');
	}

	static string LowerAllString(string S1)
	{
		int Length = S1.length();
		for (int i = 0; i < Length; i++)
		{
			if (S1[i] != ' ' && !ispunct(S1[i]))
				S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	static short Length(string Value)
	{
		return Value.length();
	}

	short Length()
	{
		return Length(_Value);
	}

	void LowerAllString()
	{
		_PreviousValue = _Value;
		_Value = LowerAllString(_Value);
	}

	static string UpperAllString(string S1)
	{
		int Length = S1.length();
		for (int i = 0; i < Length; i++)
		{
			if (S1[i] != ' ' && !ispunct(S1[i]))
				S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	void UpperAllString()
	{
		_PreviousValue = _Value;
		_Value = UpperAllString(_Value);
	}

	static string InvertLettersCase(string S1)
	{
		short Length = S1.length();
		for (short i = 0; i < Length; i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}

	void InvertLettersCase()
	{
		_PreviousValue = _Value;
		_Value = InvertLettersCase(_Value);
	}

	static vector <string> Split(string S1, string Delim = "#//#")
	{
		short pos = 0;
		string sWord;
		vector <string> String;
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				String.push_back(sWord);
			}
			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")
		{
			String.push_back(S1);
		}
		return String;
	}

	vector <string> Split(string Delim = "#//#")
	{
		return Split(_Value, Delim);
	}

	static string JoinString(vector <string>& vString, string Delim = "#//#")
	{
		string S1;
		for (string& Word : vString)
		{
			S1 = S1 + Word + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}

	
	static string ReplaceWord(string S1, string ToReplace, string ReplaceWith, bool MatchCase = 1)
	{
		vector <string> vString = Split(S1, " ");
		for (string& S : vString)
		{
			if (MatchCase)
			{
				if (S == ToReplace)
				{
					S = ReplaceWith;
				}
			}
			else
			{
				if (LowerAllString(S) == LowerAllString(ToReplace))
				{
					S = ReplaceWith;
				}
			}
		}
		return JoinString(vString, " ");
	}

    string ReplaceWord(string ToReplace, string ReplaceWith, bool MatchCase = 1)
	{
		return ReplaceWord(_Value, ToReplace, ReplaceWith, MatchCase);
	}

	static string RemovePuctuation(string S1)
	{
		string S2 = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 = S2 + S1[i];
			}
		}
		return S2;
	}

	void RemovePuctuation()
	{
		_PreviousValue = _Value;
		_Value = RemovePuctuation(_Value);
	}

	static void PrintTheFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
				cout << S1[i] << "\n";
			isFirstLetter = (S1[i] == ' ') ? true : false;
		}
	}

	void PrintTheFirstLetterOfEachWord()
	{
		PrintTheFirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ') ? true : false;
		}
		return S1;
	}

	void UpperFirstLetterOfEachWord()
	{
		_PreviousValue = _Value;
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
	}

	void LowerFirstLetterOfEachWord()
	{
		_PreviousValue = _Value;
		_Value = LowerFirstLetterOfEachWord(_Value);
	}


	static string InvertAllLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}

	void InvertAllLettersCase()
	{
		_PreviousValue = _Value;
		_Value = InvertAllLettersCase(_Value);
	}

	static short CountCapitalLetters(string S1)  
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Counter++;
		}
		return Counter;
	}
	   
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountSpecificLetter(string S1, char Letter, bool MatchCase = 1)
	{
		short Counter = 0, Length = S1.length();
		for (short i = 0; i < Length; i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}
		}
		return Counter;
	}

	short CountSpecificLetter( char Letter, bool MatchCase = 1)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	
	static short CountVowels(string S1)
	{
		short Lenght = S1.length(), Counter = 0;
		for (short i = 0; i < Lenght; i++)
		{
			if (IsVowel(S1[i]))
				Counter++;
		}
		return Counter;

	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static void PrintStringVowelsLetter(string S1)
	{
		short Lenght = S1.length();
		cout << "Vowels in string are: ";
		for (short i = 0; i < Lenght; i++)
		{
			if (IsVowel(S1[i]))
				cout << S1[i] << "    ";
		}
	}

	void PrintStringVowelsLetter()
	{
		PrintStringVowelsLetter(_Value);
	}

	static short CountWords(string S1)
	{
		string delim = " ";
		short pos = 0, Counter = 0;
		string sWord;
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				Counter++;
			}
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			return ++Counter;
		}
		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static string TrimLeft(string S1)
	{
		short Length = S1.length();
		for (short i = 0; i < Length; i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, Length - 100);
			}
		}
		return "";
	}

	void TrimLeft()
	{
		_PreviousValue = _Value;
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		short Length = S1.length();
		for (short i = Length - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return S1;
	}

	void TrimRight()
	{
		_PreviousValue = _Value;
		_Value = TrimRight(_Value);
	}


	static string Trim(string S1)  // review the trim functions
	{
		return TrimRight(TrimLeft(S1));
	}

	void Trim()
	{
		_PreviousValue = _Value;
		_Value = Trim(_Value);
	}

	static string JoinString(string arrString[], short Length, string delim)
	{
		string S1;
		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + delim;
		}
		return S1.substr(0, S1.length() - (delim.length()));
	}

	static string  ReverseWord(string S1)
	{
		vector <string> vString = Split(S1, " ");
		string S2 = "";
		vector<string>::iterator iter;
		iter = vString.end();
		while (iter != vString.begin())
		{
			--iter;
			S2 = S2 + (*iter) + " ";
		}
		return S2.substr(0, S2.length() - 1);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetters(string S1, enWhatToCount
		WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters &&
				isupper(S1[i]))
				Counter++;
			if (WhatToCount == enWhatToCount::SmallLetters &&
				islower(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountLetters(enWhatToCount WhatToCount = enWhatToCount::All)
	{
		return CountLetters(_Value, WhatToCount);
	}

	void  ReverseWordsInString()
	{
		_PreviousValue = _Value;
		_Value = ReverseWord(_Value);
	}

	void CancelOperation()
	{
		_Value = _PreviousValue;
	}

};

