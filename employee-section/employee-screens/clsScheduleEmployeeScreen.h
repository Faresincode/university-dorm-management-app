#pragma once
#include <iostream>
#include <Vector>
#include <iomanip>
#include "Global.h";
#include "clsGlobalPrint.h";
#include "clsBase.h";

using namespace std;



class clsScheduleEmployeeScreen : protected clsBase
{

private:

	static void PrintScheduleEmployeeTable(vector<clsSchedule>vSchedules)
	{

		clsGlobalPrint::PrintScheduleEmployeeTableHeader();
		for (clsSchedule& Schedule : vSchedules)
		{
			clsGlobalPrint::PrintScheduleEmployeeRecordLine(Schedule);
			cout << endl;
		}
		cout << "\n" << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________\n\n" << White;



	}



public:

	static void ShowScheduleEmployeeTableScreen()
	{

		clsBase::_DrawScreenHeader("\t    Employee Schedule Table ");


		if (clsInputValidate::IsSureToPerform())
		{
			system("cls");
			vector<clsSchedule>vSchedules = clsSchedule::GetSchedulesList();
			string Subtitle = "\t\t(" + to_string(vSchedules.size()) + ") Employees";
			clsBase::_DrawScreenHeader("\t    Employee Schedule Table ", Subtitle);

			PrintScheduleEmployeeTable(vSchedules);

		}




	}



};

