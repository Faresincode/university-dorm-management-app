#pragma once
#pragma once
#include <iostream>
#include "clsPerson.h";
using namespace std;




class clsStudentInfo : public clsPerson
{

private:

	string _StudentID;
	string _UniversityName;
	string _Faculty;
	string _Department;
	string _Speciality;

protected:

	enum enYearLevel {  Bac1 = 1, Bac2 = 2, Bac3 = 3, Mst1 = 4, Mst2 = 5, Dr1 = 6, Dr2 = 7,NoLevel=0 };
	enYearLevel _YearLevel;


protected:
	static clsStudentInfo GetStudentInfoEmptyObject()
	{
		return clsStudentInfo("", "", enGender::eNoGender, "", "", "", "", "", "", "", "", enYearLevel::NoLevel, "");

	}



public:

	clsStudentInfo(string FirstName, string LastName, enGender Gender, string DateOfBirth, string Nationality, string Email, string Phone,
		string StudentID,string UniversityName,string Faculty,string Department, enYearLevel YearLevel,string Speciality)
		:clsPerson(FirstName, LastName, Gender,DateOfBirth,Nationality,Email, Phone)
	{
		_StudentID= StudentID;
		_UniversityName = UniversityName;
		_Faculty = Faculty;
		_Department= Department;
		_YearLevel = YearLevel;
		_Speciality = Speciality;


	}




	const string GetStudentID()
	{
		return _StudentID;
	}
	void SetStudentID(string StudentID)
	{
		_StudentID= StudentID;
	}
	__declspec(property(get = GetStudentID, put = SetStudentID)) string StudentID;

	void SetUniversityName(string UniversityName)
	{
		_UniversityName = UniversityName;
	}
	const string GetUniversityName()
	{
		return _UniversityName;
	}
	__declspec(property(get = GetUniversityName, put = SetUniversityName)) string UniversityName;

	void SetFaculty(string Faculty)
	{
		_Faculty = Faculty;
	}
	const string GetFaculty()
	{
		return _Faculty;
	}
	__declspec(property(get = GetFaculty, put = SetFaculty)) string Faculty;


	void SetDepartment(string Department)
	{
		_Department = Department;
	}
	const string GetDepartment()
	{
		return _Department;
	}
	__declspec(property(get = GetDepartment, put = SetDepartment)) string Department;


	void SetYearLevel(enYearLevel Year)
	{
		_YearLevel = Year;
	}
	const enYearLevel GetYearLevel()
	{
		return _YearLevel;
	}
	__declspec(property(get = GetYearLevel, put = SetYearLevel)) enYearLevel YearLevel;


	void SetSpeciality(string Speciality)
	{
		_Speciality = Speciality;
	}
	string GetSpeciality()
	{
		return _Speciality;
	}
	__declspec(property(get = GetSpeciality, put = SetSpeciality)) string Speciality;

	static string  GetYearLevelString(enYearLevel YearLevel)
	{

		switch (YearLevel)
		{
		case enYearLevel::Bac1:
			return "Bac1";
		case enYearLevel::Bac2:
			return "Bac2";
		case enYearLevel::Bac3:
			return "Bac";
		case enYearLevel::Mst1:
			return "Mst1";
		case enYearLevel::Mst2:
			return "Mst2";
		case enYearLevel::Dr1:
			return "Dr1";
		case enYearLevel::Dr2:
			return "Dr2";
		default:
			return "No Level";
		}

	}

	//void Print()
	//{
	//	cout << "\n" << setw(ScreenWidth) << "" << left << Green<<"___________________________________________\n" << White;
	//	cout << "\n" << setw(ScreenWidth) << "" << left << Red<<  "         Student University Info:";
	//	cout << "\n" << setw(ScreenWidth) << "" << left <<Green <<"___________________________________________"<<White;
	//	cout << "\n" << setw(ScreenWidth+1) << "" << left <<Blue<< "Student ID        : " <<White<< _StudentID;
	//	cout << "\n" << setw(ScreenWidth+1) << "" << left <<Blue<< "University Name   : " <<White<< _UniversityName;
	//	cout << "\n" << setw(ScreenWidth+1) << "" << left <<Blue<< "Faculty           : " <<White<< _Faculty;
	//	cout << "\n" << setw(ScreenWidth+1) << "" << left <<Blue<< "Department        : " <<White<< _Department;
	//	cout << "\n" << setw(ScreenWidth+1) << "" << left <<Blue<< "Nationality       : " <<White<< _Nationality;
	//	cout << "\n" << setw(ScreenWidth+1) << "" << left <<Blue<< "YearLevel         : " <<White<< GetYearLevelString(_YearLevel);
	//	cout << "\n" << setw(ScreenWidth+1) << "" << left <<Blue<< "Speciality        : " <<White<< _Speciality;
	//	cout << "\n" << setw(ScreenWidth) << "" << left << Green<<"___________________________________________"<<White << endl;

	//}



};

