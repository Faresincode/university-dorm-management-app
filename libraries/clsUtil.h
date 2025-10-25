#pragma once
#include<iostream>
#include<string>
#include "clsMath.h";
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

class clsUtil
{


private:

	enum enCharType 
	{
		Capitalletter = 1,
		SmallLetter = 2,
		Degit  = 3, 
		SpecialChar = 4 ,
		Punctuation = 5,
		Spaces = 6, 
		All = 7,
		MixChars =8
	};
	enum enLevel 
	{
		EasyLevel = 1, 
		MedLevel = 2, 
		HardLevel = 3 
	};

	friend class clsInputValidate;
	friend class clsPrint;
	short _Number;

public:


	void Srand()
	{
		srand(unsigned(time(NULL)));
	}

	template <typename DataType>
	static DataType RandomNumber(DataType From, DataType To)
	{
		if (From > To)
			clsUtil::Swap<int>(From, To);
		int RandomNumber = rand() % (To - From + 1) + From;
		return RandomNumber;
	}

	static string GenerateID(string IdString)
	{
		return IdString + to_string(clsUtil::RandomNumber(100, 99999));
	}

	static void ResetScreen()
	{
		system("cls");
		system("color 0F");
	}
	static string NumberToText(int Number)
	{

		if (Number == 0)
			return "";

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
			return arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
			return "One Hundred " + NumberToText(Number % 100);

		if (Number >= 200 && Number <= 999)
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);

		if (Number >= 1000 && Number <= 1999)
			return "One Thousand " + NumberToText(Number % 1000);

		if (Number >= 2000 && Number <= 999999)
			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);

		if (Number >= 1000000 && Number <= 1999999)
			return "One Million " + NumberToText(Number % 1000000);

		if (Number >= 2000000 && Number <= 999999999)
			return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);

		if (Number >= 1000000000 && Number <= 1999999999)
			return "One Billion " + NumberToText(Number % 1000000000);
		else
			return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);

	}

	static char GetRandomCharacter(enCharType CharType)
	{

		//updated this method to accept mixt chars
		if (CharType == MixChars)
		{
			//Capital/Small/Digits only
			CharType = (enCharType)clsMath::RandomNumber(1, 3);
		}

		switch (CharType)
		{

		case enCharType::SmallLetter:
		{
			return char(clsMath::RandomNumber(97, 122));
		}
		case enCharType::Capitalletter:
		{
			return char(clsMath::RandomNumber(65, 90));
		}
		case enCharType::SpecialChar:
		{
			return char(clsMath::RandomNumber(33, 47));
		}
		case enCharType::Degit:
		{
			return char(clsMath::RandomNumber(48, 57));
		}
		default:
		{
			return char(clsMath::RandomNumber(65, 90));
		}
		}
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

	static string BackSlashN(int NumberOfBackSlashN)
	{
		string BackSlash = "";
		for (int i = 1; i <= NumberOfBackSlashN; i++)
			BackSlash += "\n";
		return BackSlash;
	}
	string BackSlashN()
	{
		return clsUtil::BackSlashN(_Number);
	}

	static string EncryptText(string text, int EncryptedKey=2)
	{
		for (int i = 0; i < text.length(); i++)
			text[i] = char((int)text[i] + EncryptedKey);
		return text;
	}
	static string DecryptText(string text, int EncryptedKey=2)
	{
		for (int i = 0; i < text.length(); i++)
			text[i] = char((int)text[i] - EncryptedKey);
		return text;
	}
	static string GenerateWord(enCharType CaracterType, int length)
	{
		string Word = "";
		for (int i = 1; i <= length; i++)
			Word = Word + GetRandomCharacter(CaracterType);
		return Word;
	}
	static string GenerateKey(enCharType CaracterType= enCharType::Capitalletter)
	{
		string Key = "";
		Key = GenerateWord(CaracterType, 4) + "-";
		Key = Key + GenerateWord(CaracterType, 4) + "-";
		Key = Key + GenerateWord(CaracterType, 4) + "-";
		Key = Key + GenerateWord(CaracterType, 4);
		return Key;
	}
	static void GenerateKeys(int NumberOfKeys)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey() << endl;
		}
	} 
	static char OperationTypeCaracter(clsMath::enOperatorType OpType)
	{
		char arrOperationType[5] = { '+','-','*','/','%' };
		return arrOperationType[OpType - 1];
	}

	template<typename Datatype>
	static void Swap(Datatype& A, Datatype& B)
	{
		Datatype Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void ShuffleArray(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			Swap(arr[clsMath::RandomNumber(1, arrLength) - 1], arr[clsMath::RandomNumber(1, arrLength) - 1]);
	}
	static void FillArrayWithRandomNumber(int arr[], int& arrLength, int From, int To)
	{
		cout << "\n Enter array length \n";
		cin >> arrLength;
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber<int>(From, To);
	}
	static void FillArrayWithRandomWords(string arr[], int& arrLength, enCharType CharacterType)
	{
		cout << "\n Enter array length \n";
		cin >> arrLength;
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(enCharType::MixChars, 1);
	}
	static void FillArrayWithRandomKey(string arr[], int& arrLength,enCharType CharacterType)
	{
		cout << "\n Enter array length \n";
		cin >> arrLength;
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharacterType);
	}
	static void ShuffleArray(string arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			Swap(arr[RandomNumber<int>(1, arrLength) - 1], arr[RandomNumber<int>(1, arrLength) - 1]);
	}
	
	static string LevelText(enLevel QuestionLevel)
	{
		string arrQuestionLevel[3] = { "Easy","Med","Hard" };
		return arrQuestionLevel[QuestionLevel - 1];
	}
	static string WinOrFaiLText(bool IsWin)
	{
		if (IsWin)
			return " Win :-) \n";
		else
			" Fail :-( \n";
	}
	static void PrintFibonacciUsingRecursion(short Number, int Prev1, int Prev2)
	{
		int FebNumber = 0;
		if (Number > 0)
		{
			FebNumber = Prev2 + Prev1;
			Prev2 = Prev1;
			Prev1 = FebNumber;
			cout << FebNumber << " ";
			PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
		}
	}

	const static string Red()
	{
		return "\033[31m"; 
	}
	const static string Green() 
	{
		return "\033[32m";
	}
	const static string Yellow() 
	{
		return "\033[33m"; 
	}
	const static string Blue() 
	{
		return "\033[34m"; 
	}
	const static string White() 
	{ 
		return "\033[0m"; 
	}

	static const string Centre()
	{
		cout<<setw(50);
		return "";
	}

	static void AddDataLineToFile(string  stDataLine,string FileName)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);
		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	static vector<string>LoadDataFromFile(string FileName)
	{
		vector<string>vLines;
		fstream MyFile;
		MyFile.open(FileName, ios::in);//Read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				if (Line != "")
				{
					vLines.push_back(Line);
				}

			}
			MyFile.close();
		}

		return vLines;
	}

	static void SaveDataToFile(vector<string>vLines,string FileName)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);//write Mode
		if (MyFile.is_open())
		{
			string Line;
			for (string& line: vLines)
			{
				MyFile << line << endl;
			}
			MyFile.close();
		}
	}

	static bool RemoveEmptyLineInFile(string FileName)
	{
		vector <string>vLines = clsUtil::LoadDataFromFile(FileName);
		vector<string>NewVector;
		for (string& line : vLines)
		{
			if (!(line.empty()))
				NewVector.push_back(line);

		}
		clsUtil::SaveDataToFile(NewVector, FileName);
		return true;
	}

	template<typename Datatype>
	static bool IsElementInVector(Datatype ElementToCheck, vector<Datatype>vElements)
	{

		for (Datatype& element : vElements)
		{
			if (element == ElementToCheck)
				return true;
		}
		return false;
	}


};

