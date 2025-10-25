#pragma once
#include<iostream>
#include<string>
#include "clsMath.h";
#include "clsUtil.h";

using namespace std;

class clsInputValidate
{

public:

	/*______________________________________ Definition Functions ________________________________________*/
	static bool IsSureToPerform()
	{
	cout << "\n" << setw(ScreenWidth) << left << "" << Blue << "Are you want to Perform this action ? y/n? " << White;
	return (clsInputValidate::IsAnswerIsYes()) ? true : false;

	}



	static bool IsValidLastInput()
	{
		return !cin.fail();
	}

	template<typename DataType>
	static bool IsNumberBetween(DataType Number, DataType From, DataType To)
	{
		return (Number >= From && Number <= To);
	}

	//=================================================================================================

	template<typename DataType>
	static DataType ReadNumber(string ErrorMessage= "Invalid input, enter number again\n")
	{
		DataType Number;
		while (!(cin >> Number)) 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	//=================================================================================================
	static bool ReadBoolean(string ErrorMessage="Invalid input, (answer with 0 or 1)\n")
	{
		return ReadNumberBetween(0,1,ErrorMessage);
	}

	static bool IsAnswerIsYes(string ErrorMessage ="Invalid input, answer with y/n ?\n ")
	{
		char IsCharacter = ReadCharacter();
		return (IsCharacter == 'y' || IsCharacter == 'Y');
	}

	static string ReadString()
	{
		string S1="";
		getline(cin>>ws, S1);
		return S1;
	}
	
	static char ReadCharacter(string ErrorMessage= "Invalid input, enter character\n")
	{
		string input="";
		while (true)
		{
			getline(cin>>ws, input);
			if (input.length() == 1)
			{
				return input[0];
			}
			else
			{
				cout << ErrorMessage;
			}
		}

	}
	//=================================================================================================

	template<typename DataType>
	static DataType ReadNumberBetween( DataType From, DataType To, string ErrorMessage="Invalid number, enter again\n")
	{
		DataType Number = ReadNumber<DataType>(ErrorMessage);
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber<DataType>(ErrorMessage);
		}
		return Number;
	}

	//=================================================================================================
	template<typename DataType>
	static DataType ReadPositiveNumber(string ErrorMessage = "Invalid input, enter positive number\n")
	{
		DataType  Number = ReadNumber<DataType>(ErrorMessage);
		while (Number <= 0)
		{
			cout << ErrorMessage;
			Number = ReadNumber<DataType>(ErrorMessage);
		}
		return Number;
	}
	//=================================================================================================
	template <typename DataType> 
	static DataType ReadNegativeNumber(string ErrorMessage= "Invalid input, enter negative number\n")
	{
		DataType  Number = ReadNumber<DataType>(ErrorMessage);
		while (Number >= 0)
		{
			cout << ErrorMessage;
			Number = ReadNumber<DataType>(ErrorMessage);
		}
		return Number;
	}
	//=================================================================================================
	
	template <typename DataType,typename arraysize>
	static void ReadArrayOfNumber(DataType arr[], arraysize arrLength=0)
	{
		cout << "\nEnter array elements \n\n";
		for (int i = 0; i <= arrLength - 1; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			arr[i]=ReadNumber<DataType>();
		}
	}

	static void ReadArrayOfCharacter(char arr[], int arrLength = 0)
	{
		cout << "\n Enter array elements \n";
		for (int i = 0; i <arrLength; i++)
		{
			cout << "Element [" << i + 1 << "] : ";
			arr[i]=ReadCharacter();
		}
		cout << endl;
	}

	static void ReadArrayOfString(string arr[], int arrLength = 0)
	{
		cout << "\n Enter array elements \n";
		for (int i = 0; i <arrLength; i++)
		{
			if (i == 0)
			{
				getline(cin >> ws, arr[i]);
				continue;
			}
			cout << "Element [" << i + 1 << "] : ";
			arr[i]= ReadString();
		}
		cout << endl;
	}

	//=================================================================================================
	template<typename DataType=long long>
	static DataType ReadOddNumber(string ErrorMessage= "Invalid input, enter odd number\n")
	{
		DataType Number=ReadNumber<DataType>(ErrorMessage);
		while (!clsMath::IsOdd(Number))
		{
			cout << ErrorMessage;
			Number = ReadNumber<DataType>(ErrorMessage);
		}
		return Number;
	}

	template<typename DataType = long long>
	static DataType ReadEvenNumber(string ErrorMessage = "Invalid input, enter even number\n")
	{
		DataType Number = ReadNumber<DataType>(ErrorMessage);
		while (!clsMath::IsEven(Number))
		{
			cout << ErrorMessage;
			Number = ReadNumber<DataType>(ErrorMessage);
		}
		return Number;
	}
	
	template<typename DataType = long long>
	static DataType ReadPrimeNumber(string ErrorMessage = "Invalid input, enter prime number\n")
	{
		DataType Number = ReadNumber<DataType>(ErrorMessage);
		while (!clsMath::IsPrime(Number))
		{
			cout << ErrorMessage;
			Number = ReadNumber<DataType>(ErrorMessage);
		}
		return Number;
	}

	template<typename DataType = long long>
	static DataType ReadPerfectNumber(string ErrorMessage = "Invalid input, enter Perfect number\n")
	{
		DataType Number = ReadNumber<DataType>(ErrorMessage);
		while (!clsMath::IsPerfect(Number))
		{
			cout << ErrorMessage;
			Number = ReadNumber<DataType>(ErrorMessage);
		}
		return Number;
	}

	template<typename DataType = long long>
	static DataType ReadPalindromeNumber(string ErrorMessage = "Invalid input, enter Palindrome number\n")
	{
		DataType Number = ReadNumber<DataType>(ErrorMessage);
		while (!clsMath::IsPalindrome(Number))
		{
			cout << ErrorMessage;
			Number = ReadNumber<DataType>(ErrorMessage);
		}
		return Number;
	}
	//=================================================================================================
	static clsMath::enOperatorType ReadOperationType(string ErrorMessage)
	{
		short OperatorType = ReadNumber<short>(ErrorMessage);
		while (!(IsNumberBetween(OperatorType, (short)1, (short)5)))
		{
			cout << ErrorMessage;
			OperatorType = ReadNumber<short>(ErrorMessage);
		}
		return (clsMath::enOperatorType)OperatorType;
	}
	static clsUtil::enLevel ReadQuestionLevel(string ErrorMessage)
	{
		short QuestionLevel = ReadNumber<short>(ErrorMessage);
		while (!(IsNumberBetween(QuestionLevel,(short) 1,(short) 3)))
		{
			cout << ErrorMessage;
			QuestionLevel = ReadNumber<short>(ErrorMessage);
		}
		return (clsUtil::enLevel)QuestionLevel;
	}



};

