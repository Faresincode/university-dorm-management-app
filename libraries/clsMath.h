#pragma once
#include <iostream>
#include <cmath>
using namespace std;


class clsMath
{

private:



public:

	enum enOperatorType { eAdd = 1, eSub = 2, eMul = 3, eDiv = 4, eMode = 5 };

	template <typename DataType=double>
	static bool IsFloat(DataType Number)
	{
		return clsMath::FractionPart(Number) != 0;
		//return std::floor(Number) != Number;
	}

	//================================== Is Positive =============================================
	template <typename DataType> 
	static bool IsPositive(DataType Number)
	{
		return (Number > 0);

	}

	//================================== Is Negative =================================================
	template <typename DataType>
	static bool IsNegative(DataType Number)
	{
		return (Number < 0);
	}

	//===============================================================================================

	template<typename DataType=short>
	static bool IsZero(DataType Number)
	{
		return (Number == 0);
	}

	template<typename DataType = int>
	static bool IsLeapYear(DataType Year)
	{
		// if year is divisible by 4 AND not divisible by 100
		// OR if year is divisible by 400
		// then it is a leap year
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	template<typename DataType = long long>
	static bool IsOdd(DataType Number)
	{
		//if numebr has franction part so float or double heis return false directly
		if (clsMath::IsFloat(Number))
		{
			return false; // not an integer
		}
		return (Number % 2 != 0);

	}

	template<typename DataType = long long>
	static bool IsEven(DataType Number)
	{
		if (clsMath::IsFloat(Number))
		{
			return false; // not an integer
		}
		return (Number % 2 == 0);
	}

	template<typename DataType = long long>
	static bool IsPrime(DataType Number)
	{

		DataType M = round(Number / 2);
		for (int counter = 2; counter <= M; counter++)
			if (Number % counter == 0)
				return 0;
		return 1;
	}

	template<typename DataType = long long>
	static bool IsPalindrome(DataType Number)
	{
		return (Number == clsMath::ReverseNum(Number));
	}

	template<typename DataType = long long>
	static bool IsPerfect(DataType Number)
	{
		DataType Sum = 0;
		for (DataType i = 1; i < Number; i++)
		{
			if (Number % i == 0)
				Sum += i;
		}

		return Number == Sum;
	}
	//===============================================================================================
	template <typename DataType>
	static DataType RandomNumber(DataType From, DataType To)
	{
		if (From > To)
			swap(From, To);
		return rand() % (To - From + 1) + From;
	}

	template <typename DataType>
	static DataType ReverseNum(DataType Number)
	{
		Number = int (Number);
		int Remainder = 0;
		int Reversed = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Reversed = Reversed * 10 + Remainder;
		}
		return Reversed;
	}

	template <typename DataType=double>
	static DataType FractionPart(DataType Number)
	{
		return Number - int(Number);
	}


	template <typename DataType = int>
	static DataType SumDigits(DataType Number)
	{
		short Remainder = 0;
		DataType Sum = 0;
		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Sum = Sum + Remainder;
		}
		return Sum;
	}

	template <typename DataType = int>
	static string NumberToText(DataType Number)
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
	//===============================================================================================

	template <typename DataType>
	static DataType Abs(DataType Number)
	{
		return (Number < 0) ? Number * -1 : Number;
	}

	//===============================================================================================
	template <typename DataType = float>
	static DataType Sqrt(DataType Number)
	{
		return pow(Number, 0.5);
	}

	template <typename DataType=float>
	static DataType Ceil(DataType Number)
	{
		if (abs(FractionPart(Number)) > 0)
		{
			if (Number > 0)
				return int(Number) + 1;
			else
				return int(Number);
		}
		else
			return Number;
	}

	template <typename DataType = float>
	static DataType Floor(DataType Number)
	{
		if (Number > 0)
			return int(Number);
		else
			return int(Number) - 1;
	}

	template <typename DataType = float>
	static DataType Round(DataType Number)
	{
		int IntPart = int(Number);
		if (abs(FractionPart(Number)) >= .5)
		{
			if (Number > 0)
				return ++IntPart;
			else
				return --IntPart;
		}
		else
			return IntPart;
	}

	//===============================================================================================
	template <typename DataType>
	static float Half(DataType Num)
	{
		return (float)(Num / 2);
	}

	//===============================================================================================
	template <typename DataType>
	static void Swap( DataType & A, DataType& B)
	{
		DataType Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	//===============================================================================================

	template <typename DataType>
	static DataType Opposite(DataType Number)
	{
		return Number * -1;
	}

	template <typename DataType, typename DataType2>
	static double Sum(DataType Number1, DataType2 Number2)
	{
		return (Number1 + Number2 );
	}

	template <typename DataType, typename DataType2>
	static double Subtract(DataType Number1, DataType2 Number2)
	{
		return (Number1 - Number2 );
	}

	template <typename DataType, typename DataType2>
	static double Multiplicate(DataType Number1, DataType2 Number2)
	{
		return (Number1 * Number2 );
	}

	template <typename DataType, typename DataType2>
	static double Divide(DataType Number1, DataType2 Number2)
	{

		return (Number1 / Number2 );
	}

	template <typename DataType, typename DataType2>
	static double Mode2Num(DataType Number1, DataType2 Number2)
	{
		return Number1 % Number2;
	}

	template <typename DataType>
	static DataType Square(DataType x) 
	{
		return x * x; 
	}

	template<typename DataType>
	static DataType Calculate2Num(DataType Num1, DataType Num2, enOperatorType OpType)
	{
		switch (OpType)
		{
		case enOperatorType::eAdd:
		{
			return (Num1 + Num2);
		}
		case enOperatorType::eSub:
		{
			return (Num1 - Num2);
		}
		case enOperatorType::eMul:
		{
			return (Num1 * Num2);
		}
		case enOperatorType::eDiv:
		{
			return (Num1 / Num2);
		}
		case enOperatorType:: eMode:
		{
			return (Num1 % Num2);
		}
		default:
			return (Num1 + Num2);
		}
	}

	//===============================================================================================


};

