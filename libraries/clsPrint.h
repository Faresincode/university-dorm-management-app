#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include <vector>
#include<iomanip>
#include "clsString.h";
#include "clsMath.h";
#include "clsUtil.h";

using namespace std;

class clsPrint
{

protected:

	string _Text = "";
	int _Number = 0;
	short _Num;

public:

	//============= set and get property ========================
	string getText()
	{
		return _Text;
	}
	void setText(string Text)
	{
		this->_Text = Text;
	}
	__declspec(property(get=getText, put =setText ))string MyText;

	int getNumber()
	{
		return _Number;
	}
	void setNumber(int Number)
	{
		this->_Number = Number;
	}
	__declspec(property(get = getNumber, put = setNumber))int IntNumber;

	short getNum()
	{
		return _Num;
	}
	void setNum(short Num)
	{
		this->_Num = Num;
	}
	__declspec(property(get = getNum, put = setNum))short ShortNum;
	/*_______________definition function ________________________ */
	static void Print(string Text="")
	{
		cout << Text;
	}
	void Print()
	{
		clsPrint::Print(this->_Text);
	}
	static string Tabs(int NumberOfTabs)
	{
		string Tab = "";
		for (int i = 1; i <= NumberOfTabs; i++)
			Tab += "\t";
		return Tab;
	}
	string Tabs()
	{
		return clsUtil::Tabs(_Number);
	}
	
	static void PrintRandomCharacters(clsUtil::enCharType CaracterType, short NumberOfCaracters = 1)
	{
		for (short i = 1; i <= NumberOfCaracters; i++)
		{
			cout << clsUtil::GetRandomCharacter(CaracterType);
		}
	}
	static void PrintRandomUpperLetters(short NumberOfLetter = 1)
	{
		for (short i = 1; i <= NumberOfLetter; i++)
		{
			cout << clsUtil::GetRandomCharacter(clsUtil::enCharType::Capitalletter);
		}
	}
	static void PrintRandomLowerLetters(short NumberOfLetter = 1)
	{
		for (short i = 1; i <= NumberOfLetter; i++)
		{
			cout << clsUtil::GetRandomCharacter(clsUtil::enCharType::SmallLetter);
		}
	}
	static void PrintRandomSpecialCharacters(short NumberOfLetter = 1)
	{
		for (short i = 1; i <= NumberOfLetter; i++)
		{
			cout << clsUtil::GetRandomCharacter(clsUtil::enCharType::SpecialChar);
		}
	}
	static void PrintPrimeNumbers(int From, int To)
	{
		for (int i = From; i <= To; i++)
			if (clsMath::IsPrime(i))
				cout << i << " ";
		cout << endl;
	}
	static void PrintOddNumbers(int From, int To)
	{
		for (int i = From; i <= To; i++)
			if (clsMath::IsOdd(i))
				cout << i << " ";
		cout << endl;
	}
	static void PrintEvenNumbers(int From, int To)
	{
		for (int i = From; i <= To; i++)
			if (clsMath::IsEven(i))
				cout << i << " ";
		cout << endl;
	}
	static void PrintPalindromeNums(int From, int To)
	{
		for (int i = From; i <= To; i++)
			if (clsMath::IsPalindrome(i))
				cout << i << " ";
		cout << endl;
	}
	static void PrintPerfectNumbers(int From, int To)
	{
		for (int i = From; i <= To; i++)
			if (clsMath::IsPerfect(i))
				cout << i << " ";
		cout << endl;
	}

	static void PrintDigitsOfNum(int Number)
	{
		int ReverceOfNumber = clsMath::ReverseNum(Number);
		while (ReverceOfNumber > 0)
		{
			int Remainder = 0;
			Remainder = ReverceOfNumber % 10;
			ReverceOfNumber = ReverceOfNumber / 10;
			cout << Remainder << endl;
		}
	}
	void PrintDigitsOfNum()
	{
		clsPrint::PrintDigitsOfNum(this->_Number);
	}

	static void PrintKeys(int NumberOfKeys=0)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << clsUtil::GenerateKey() << endl;
		}
	}

	static char OperationTypeCaracter(clsUtil::enCharType OpType)
	{
		char arrOperationType[5] = { '+','-','*','/','%' };
		return arrOperationType[OpType - 1];
	}
	static string LevelText(clsUtil::enLevel QuestionLevel)
	{
		string arrQuestionLvel[3] = { "Easy","Med","Hard" };
		return arrQuestionLvel[QuestionLevel - 1];
	}
	static string WinOrFaiLText(bool IsWin=0)
	{
		if (IsWin)
			return " Win :-) \n";
		else
			" Fail :-( \n";
	}
	static void SetScreenColor(bool IsCorrect=0)
	{
		if (IsCorrect)
		{
			system("color 2F");//green screen color

		}
		else
		{
			system("color 4F");//red screen color
			cout << "\a";
		}
	}
	static void PrintGameResultsScreen()
	{
		cout << Tabs(2) << "______________________________________________________  \n";
		cout << Tabs(2) << "                   +++ Game Result +++ \n";
		cout << Tabs(2) << "--------------------------------------------------------\n\n";
	}
	static void ShowGameOverScreen()
	{
		cout << "\n\n____________________________________________________________\n";
		cout << "                    + + + G a m e O v e r + + +                   \n";
		cout << "___________________________________________________________________\n\n";
	}

	static void PrintFibonatchiSerie(int Number)
	{
		int  FebonatchiNumber = 0;
		int Previous2 = 0, Previous1 = 1;
		//cout << "1 ";
		for (short i = 0; i < Number; ++i)
		{
			cout << FebonatchiNumber << " ";

			Previous2 = Previous1;

			Previous1 = FebonatchiNumber;

			FebonatchiNumber = Previous1 + Previous2;

		}


	}
	static void PrintFibonacciUsingRecurssion(short Number, int Prev1, int Prev2)
	{
		int FebNumber = 0;
		if (Number > 0)
		{
			FebNumber = Prev2 + Prev1;
			Prev2 = Prev1;
			Prev1 = FebNumber;
			cout << FebNumber << " ";
			PrintFibonacciUsingRecurssion(Number - 1, Prev1, Prev2);
		}
	}
	
	static void PrintFirstLetterOfWords(string S1)
	{

		bool IsFirstLetter = true;
		cout << "\n First Lettrer of this string \n";
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && IsFirstLetter)
				cout << S1[i] << endl;
			IsFirstLetter = ((S1[i] == ' ') ? true : false);
		}
	}
	void PrintFirstLetterOfWords()
	{
		clsPrint::PrintFirstLetterOfWords(this->_Text);
	}

	static void PrintVowels(string S1)
	{

		short Counter = 0;
		cout << "\n Vowels In String are : ";
		for (short i = 0; i < S1.length(); i++)
		{
			if (clsString::IsVowel(S1[i]))
				cout << S1[i] << "   ";
		}
		cout << endl;

	}
	void PrintVowels()
	{
		clsPrint::PrintVowels(this->_Text);
	}

	static void PrintEachWord(string S1)
	{
		string delim = " "; // delimiter
		cout << "\nYour string wrords are: \n\n";
		short pos = 0;
		string sWord; // define a string variable// use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			cout << S1 << endl; // it print last word of the string.
		}
	}
	void PrintEachWord()
	{
		clsPrint::PrintEachWord(_Text);
	}
	
	static void SaveStringToFile(string FileName,string S1)
	{

		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);//append mode the combiler say to c++ so go open the file or if his not iwist make it and open it to write or to append and give the priority to apped
		if (MyFile.is_open())
		{
			MyFile << S1 << "\n";
			MyFile.close();
		}


	}
	void SaveStringToFile(string FileName)
	{
		clsPrint::SaveStringToFile(FileName, _Text);
	}

	string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder - 1];
	}
	void PrintDayName()
	{
		cout<<clsPrint::DayShortName(this->_Num);
	}

	string MonthShortName(short MonthOfYearOrder)
	{
		string arrMonthNames[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return arrMonthNames[MonthOfYearOrder - 1];
	}
	void PrintMonthName()
	{
		cout << clsPrint::MonthShortName(this->_Num);
	}

	void PrintDaysLineFormat()
	{
		for (short i = 1; i <= 7; i++)
			cout << setw(6) << DayShortName(i) << "";
		cout << endl;

	}



};

