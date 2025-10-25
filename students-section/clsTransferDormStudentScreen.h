#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsStudentDorm.h";
#include "clsInputValidate.h";


using namespace std;

class clsTransferDormStudentScreen : protected clsBase
{
private:





	static void _ReadNewDormBuilding(clsStudentDorm &DormStudent)
	{
		cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Dorm Building ? ";
		DormStudent.DormBuilding = clsInputValidate::ReadCharacter();
	}

	static void _ReadNewRoomNumber(clsStudentDorm& DormStudent)
	{
		cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Room Number ? ";
		DormStudent.RoomNumber = clsInputValidate::ReadNumber<short>();
	}

	static void _ReadNewBedNumber(clsStudentDorm& DormStudent)
	{
		cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Room Number ? ";
		DormStudent.BedNumber = clsInputValidate::ReadNumber<short>();
	}

	static void _PrintDormStudent(clsStudentDorm Student)
	{
		cout <<"\n"<< setw(ScreenWidth) << "" << left << Green <<   "==========================================";
		cout <<"\n"<< setw(ScreenWidth) << "" << left << Blue <<    "        Updated Dorm Student Info : "<<White;
		cout <<"\n"<< setw(ScreenWidth+1) << "" << left << Green << "==========================================" << White;
		cout <<"\n"<< setw(ScreenWidth+1) << "" << left << " Student Dorm Id   : " << Student.StudentDormId ;
		cout <<"\n"<< setw(ScreenWidth+1) << "" << left << " Student ID        : " << Student.StudentID ;
		cout <<"\n"<< setw(ScreenWidth+1) << "" << left << " Full Name         : " << Student.FullName() ;
		cout <<"\n"<< setw(ScreenWidth+1) << "" << left << " Gender            : " << char(Student.Gender);
		cout <<"\n"<< setw(ScreenWidth+1) << "" << left << " Residence Name    : " << Student.ResidenceName ;
		cout <<"\n"<< setw(ScreenWidth+1) << "" << left << " Dorm Building     : " << Student.DormBuilding ;
		cout <<"\n"<< setw(ScreenWidth+1) << "" << left << " Room Number       : " << Student.RoomNumber ;
		cout <<"\n"<< setw(ScreenWidth+1) << "" << left << " Bed Number        : " << Student.BedNumber ;
		cout <<"\n"<< setw(ScreenWidth+1) << "" << left << " Admission Date    : " << Student.AdmissionDate;
		cout <<"\n"<< setw(ScreenWidth+1) << "" << left << " Checkout Date     : " << Student.CheckoutDate ;
		cout <<"\n"<< setw(ScreenWidth+1) << "" << left << " Status            : " << clsStudentDorm::GetStatusString(Student.Status);
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================" << White << endl;

	}

	static string _ReadStudentDormId()
	{
		cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Student Dorm: ";
		string DormStudentId = clsInputValidate::ReadString();

		if (DormStudentId == "exit")
			return "exit";
		while (!clsStudentDorm::IsDormStudentExist(DormStudentId))
		{
			cout << clsUtil::Yellow() << "\n" << setw(ScreenWidth) << "" << left << "Dorm Student is not found, choose another one:  " << White;
			DormStudentId = clsInputValidate::ReadString();
			if (DormStudentId == "exit")
				return "exit";
		}
		return DormStudentId;

	}

	static void _ReadDestination(clsStudentDorm &DormStudent)
	{
		_ReadNewDormBuilding(DormStudent);
		_ReadNewRoomNumber(DormStudent);
		_ReadNewBedNumber(DormStudent);

	}

	static void _PrintResult(clsStudentDorm::enSaveResults SaveResult, clsStudentDorm Student)
	{

		switch (SaveResult)
		{
		case clsStudentDorm::enSaveResults::svSucceeded:
		{
			cout << Green << "\n" << setw(ScreenWidth) << "" << left << "Student Info Updated Successfully :-)\n" << White;
			_PrintDormStudent(Student);
			break;
		}
		case clsStudentDorm::enSaveResults::svFaildEmptyObject:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error account was not saved because it's Empty" << White;
			break;
		}

		}


	}


public:

	static void ShowInternalTransferDormStudentScreen()
	{
		system("cls");

		_DrawScreenHeader("\tInternal Transfer Dorm Student Screen");
		if (clsInputValidate::IsSureToPerform())
		{
			string DormStudentId = _ReadStudentDormId();

			clsStudentDorm DormStudent = clsStudentDorm::FindByDormId(DormStudentId);
			_PrintDormStudent(DormStudent);

			cout << "\n" << setw(ScreenWidth) << "" << left << "Are you sure you want to perform this operation? y/n? ";
			if (clsInputValidate::IsAnswerIsYes())
			{
				_ReadDestination(DormStudent);

				clsStudentDorm::enSaveResults SaveResult = DormStudent.Save();
				_PrintResult(SaveResult, DormStudent);

			}
		}


	}



};

