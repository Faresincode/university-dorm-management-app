#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsStudentDorm.h";
#include "clsInputValidate.h";


using namespace std;



class clsGenerateReportScreen :  protected clsBase
{


private:




	static void _DrawBuildingScreenTableHeader()
	{
		cout << "\n" << setw(ScreenWidth) << "" << left <<Green<< "--------------------------------------------" <<White;
		cout << "\n" << setw(ScreenWidth) << "" << left <<Green<< "| " << Yellow<<setw(12) << "Building" << left;
		cout<<Green<< "| " <<Yellow<<setw(16) << "Students Number" << left;
		cout << "\n" << setw(ScreenWidth) << "" << left <<Green<< "--------------------------------------------" <<White;

		

	}

	static void _PrintDormBuildingTableline(char DormBuilding, vector<clsStudentDorm> vStudentsList)
	{
		cout << "\n" << setw(ScreenWidth) << "" << left <<Green<< "| " << White<<setw(12) << DormBuilding << left;
		cout <<Green<< "| " <<White<< setw(16) << clsStudentDorm::GetStudentsCountPerDormBuilding(DormBuilding, vStudentsList) << left;

	}

	static void _PrintDormBuildingTable(vector<clsStudentDorm> vStudentsList)
	{


		cout << "\n" << setw(ScreenWidth+1) << "" << left << Blue << "Student Count Per Dorm Building Table : \n"<<White;

		_DrawBuildingScreenTableHeader();

		for (clsStudentDorm& Student : vStudentsList)
		{
			_PrintDormBuildingTableline(Student.DormBuilding, vStudentsList);
		}

		cout << "\n" << setw(ScreenWidth) << "" << left <<Green<< "--------------------------------------------"<<White<<endl;

	}

	//============================================================================================

	static void _DrawDormRoomsScreenTableHeader()
	{
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "--------------------------------------------";
		cout << "\n" << setw(ScreenWidth) << "" << left << "| " << Yellow<<setw(12) << "Building" << left;
		cout << Green<<"| " << Yellow<<setw(9) << "Room" << left;
		cout <<Green<< "| " << Yellow<<setw(16) << "Students Number" << left;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "--------------------------------------------";



	}

	static void _PrintDormRoomsTableline(char DormBuilding,short RoomNumber, vector<clsStudentDorm> vStudentsList)
	{
		cout << "\n" << setw(ScreenWidth) << "" << left <<Green<< "| " << White<<setw(12) << DormBuilding << left;
		cout << Green<<"| " << White<<setw(9) << RoomNumber << left;

		cout <<Green<< "| " <<White<< setw(16) << clsStudentDorm::GetStudentsCountPerRoomNumber(RoomNumber, vStudentsList) << left;

	}

	static void _PrintDormRoomsTable(vector<clsStudentDorm> vStudentsList)
	{


		cout << "\n" << setw(ScreenWidth+1) << "" << left << Blue << "Student Count Per Room Number Table \n";

		_DrawDormRoomsScreenTableHeader();
		for (clsStudentDorm& Student : vStudentsList)
		{
			_PrintDormRoomsTableline(Student.DormBuilding,Student.RoomNumber, vStudentsList);
		}

		cout << "\n" << setw(ScreenWidth) << "" << left <<Green<< "--------------------------------------------"<<White << endl;

	}
	
	//============================================================================================

	static void _PrintComplainSummary()
	{

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "--------------------------------------------" << White;

		cout << "\n\n" << setw(ScreenWidth+1) << "" << left << Blue << "Complains Summary : \n" << White;

		vector<clsStudentDorm::stComplaint>vComplains = clsStudentDorm::GetComplaintsList();
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Total Number Of Complains         : " << vComplains.size();
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Resolved Complains                : " << clsStudentDorm::GetCountComplainPerStatus(clsStudentDorm::enComplainStatus::eResolved, vComplains);
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Pending Complains                 : " << clsStudentDorm::GetCountComplainPerStatus(clsStudentDorm::enComplainStatus::eInPending, vComplains);
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "InProgress Complains              : " << clsStudentDorm::GetCountComplainPerStatus(clsStudentDorm::enComplainStatus::eInProgress, vComplains);
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Dismissed Complains               : " << clsStudentDorm::GetCountComplainPerStatus(clsStudentDorm::enComplainStatus::eDismissed, vComplains) ;

		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "--------------------------------------------" << White << endl;


	}

	static void _PrintDormStatusSummary(vector<clsStudentDorm> vStudentsList)
	{

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "--------------------------------------------" << White;
		cout << "\n\n" << setw(ScreenWidth+1) << "" << left << Blue << "Dorm Status Summary : \n" << White;
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Number Of Active Students         : " << clsStudentDorm::GetStudentsCountByStatus(clsStudentDorm::enStatus::eActive, vStudentsList);
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Number Of eTransferred Students   : " << clsStudentDorm::GetStudentsCountByStatus(clsStudentDorm::enStatus::eTransferred, vStudentsList);
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Number Of Checked_out Students    : " << clsStudentDorm::GetStudentsCountByStatus(clsStudentDorm::enStatus::eChecked_out, vStudentsList);
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Number Of Pending Students        : " << clsStudentDorm::GetStudentsCountByStatus(clsStudentDorm::enStatus::ePending, vStudentsList);
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Number Of Suspended Students      : " << clsStudentDorm::GetStudentsCountByStatus(clsStudentDorm::enStatus::eSuspended, vStudentsList);
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Number Of NoStatus Students       : " << clsStudentDorm::GetStudentsCountByStatus(clsStudentDorm::enStatus::eNoStatus, vStudentsList);
		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "--------------------------------------------" << White<<endl;

	}


public:


	static void showGenerateReportScreen()
	{

		system("cls");
		clsBase::_DrawScreenHeader("   Generate Student Dorm Report Screen");

		if (clsInputValidate::IsSureToPerform())
		{
			system("cls");
			vector<clsStudentDorm> vStudentsList = clsStudentDorm::GetStudentsDormList();
			string Subtitle = "\t\t(" +to_string(vStudentsList.size()) + ") Students";

			clsBase::_DrawScreenHeader("   Generate Student Dorm Report Screen", Subtitle);

		
			_PrintDormStatusSummary(vStudentsList);

			_PrintDormBuildingTable(vStudentsList);

			_PrintDormRoomsTable(vStudentsList);

			_PrintComplainSummary();

		}



	}




};

