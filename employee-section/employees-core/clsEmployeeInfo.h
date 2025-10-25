#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "clsPerson.h";

using namespace std;


class clsEmployeeInfo : public clsPerson
{

private:


	string _JobTitle;
	double _Salary;
	string _HireDate;
	enum enShift;
	enShift _Shift;
	enum enStatus;
	enStatus _Status;

public:
	// Employee ID
	enum enShift { eMorning = 1, eEvening = 2, eNight = 3,eNoShift=0 };
	enum enStatus { eActive = 1, eSuspended = 2, eResigned = 3 , eNoStatus=0};


	// Job Title
	void SetJobTitle(string JobTitle) 
	{ 
		_JobTitle = JobTitle;
	}
	string GetJobTitle() 
	{ 
		return _JobTitle; 
	}
	__declspec(property(get = GetJobTitle, put = SetJobTitle)) string JobTitle;



	// Salary
	void SetSalary(double Salary) 
	{ 
		_Salary = Salary;
	}
	double GetSalary()
	{
		return _Salary;
	}
	__declspec(property(get = GetSalary, put = SetSalary)) double Salary;

	// Hire Date
	void SetHireDate(string HireDate) 
	{ 
		_HireDate = HireDate;
	}
	string GetHireDate() 
	{ 
		return _HireDate;
	}
	__declspec(property(get = GetHireDate, put = SetHireDate)) string HireDate;

	// Shift
	void SetShift(enShift Shift) 
	{
		_Shift = Shift; 
	}
	enShift GetShift() 
	{
		return _Shift; 
	}
	__declspec(property(get = GetShift, put = SetShift)) enShift Shift;

	// Status
	void SetStatus(enStatus Status) 
	{
		_Status = Status;
	}
	enStatus GetStatus() 
	{
		return _Status; 
	}
	__declspec(property(get = GetStatus, put = SetStatus)) enStatus Status;




	clsEmployeeInfo(string JobTitle,double Salary, string HireDate, enShift Shift, enStatus Status, string FirstName, string LastName, enGender Gender, string DateOfBirth, string Nationality, string Email, string Phone)
		:clsPerson(FirstName,  LastName,  Gender,  DateOfBirth,  Nationality,  Email,  Phone)
	{
		_JobTitle = JobTitle;
		_Salary = Salary;
		_HireDate = HireDate;
		_Shift = Shift;
		_Status = Status;
	}

	//void Print() const
	//{
	//	cout << "\n" << setw(ScreenWidth + 1) << "" << left << Green << "-------------------------------------------";
	//	cout << "\n" << setw(ScreenWidth + 1) << "" << left << Red << "          Employee Information";
	//	cout << "\n" << setw(ScreenWidth + 1) << "" << left << Green << "-------------------------------------------\n";
	//	cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Job Title     : " << White << _JobTitle;
	//	cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Salary        : " << White << _Salary;
	//	cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Hire Date     : " << White << _HireDate;
	//	cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Shift         : " << White << ShiftToString(_Shift);
	//	cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Status        : " << White << StatusToString(_Status);
	//	cout << "\n" << setw(ScreenWidth + 1) << "" << left << Green << "-------------------------------------------\n" << White;
	//}


	// 🧠 Helper functions to convert enums to string for printing
	static string ShiftToString(enShift shift)  
	{
		switch (shift) 
		{
		case enShift::eMorning: 
			return "Morning";
		case enShift::eEvening: 
			return "Evening";
		case enShift::eNight: 
			return "Night";
		default: 
			return "No Shift";
		}
	}

	static string StatusToString(enStatus status)  
	{
		switch (status) 
		{
		case enStatus::eActive: 
			return "Active";
		case enStatus::eResigned:
			return "Resigned";
		case enStatus::eSuspended: 
			return "Suspended";
		default:
			return "No Status";
		}
	}

};

