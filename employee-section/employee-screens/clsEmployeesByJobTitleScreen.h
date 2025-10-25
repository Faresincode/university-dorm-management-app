#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsEmployee.h";
#include "clsGlobalPrint.h";


using namespace std;


class clsEmployeesByJobTitleScreen : protected clsBase
{


private:

	static string ReadJobTitle()
	{

		cout << "\n" << setw(ScreenWidth) << "" << left << "Read Job Title: ";
		string JobTitle = clsInputValidate::ReadString();
		return JobTitle;
	}

	static void PrintEmployeeTableByJob(vector <clsEmployee> vEmployeesByJob)
	{

		clsGlobalPrint::PrintEmployeeHeader();
		for (clsEmployee& Employee : vEmployeesByJob)
		{
			clsGlobalPrint::PrintEmployeeRecordLine(Employee);
			cout << endl;
		}

		cout << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________" << White << endl;


	}


public:


	static void ShowEmployeesListByJobTitleScreen()
	{

		clsBase::_DrawScreenHeader("\tEmployees List By Job Title Screen");

		if (clsInputValidate::IsSureToPerform())
		{
			string JobTitle = ReadJobTitle();

			vector <clsEmployee> vEmployeesByJob = clsEmployee::GetEmployeeListByJob(JobTitle);

			if (vEmployeesByJob.size() == 0)
			{
				cout << "\n" << setw(ScreenWidth) << "" << left <<Red<< "Sorry! No Employee With this job Title \n\n"<<White;
				return;
			}
			else
			{
				system("cls");
				string Subtitle = "\t\t(" + to_string(vEmployeesByJob.size()) + ") Employees";
				clsBase::_DrawScreenHeader("\t  Employees List By Job Title Screen", Subtitle);
				PrintEmployeeTableByJob(vEmployeesByJob);

			}

		}







	}




};

