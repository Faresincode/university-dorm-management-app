#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsBase.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsPatrolSchedule.h"
using namespace std;

class clsViewAllPatrolSchedulesScreen : protected clsBase
{

private:
	friend class clsViewPatrolLogsScreen;

	static void _PrintPatrolScheduleRecordLine(clsPatrolSchedule Patrol)
	{
		cout << setw(2) << left << "" << Green << "| " << White << setw(12) << left << Patrol.PatrolID;
		cout << Green << "| " << White << setw(12) << left << Patrol.SecurityID;
		cout << Green << "| " << White << setw(12) << left << Patrol.StartTime;
		cout << Green << "| " << White << setw(12) << left << Patrol.EndTime;
		cout << Green << "| " << White << setw(12) << left << clsPatrolSchedule::GetPatrolStatusString(Patrol.PatrolStatus);	
		cout << Green << "| " << White << setw(40) << left << Patrol.PatrolLocation;

	}

	static void _PrintPatrolScheduleHeader()
	{
		cout << "\n" << setw(1) << left << "" << Green
			<< "_______________________________________________________________________________________________________________________________________________\n\n" << White;
		cout << setw(2) << left << "" << Green << "| " << White << setw(12) << left << "Patrol ID";
		cout << Green << "| " << White << setw(12) << left << "Security ID";
		cout << Green << "| " << White << setw(12) << left << "Start Time";
		cout << Green << "| " << White << setw(12) << left << "End Time";
		cout << Green << "| " << White << setw(12) << left << "P.Status";
		cout << Green << "| " << White << setw(40) << left << "P.Location";


		cout << "\n" << setw(1) << left << "" << Green
			<< "_______________________________________________________________________________________________________________________________________________\n\n" << White;
	}

	static void _PrintPatrolTable(vector<clsPatrolSchedule> vPatrolLogs)
	{
		if (vPatrolLogs.empty())
		{
			cout << "\n" << setw(ScreenWidth) << left << Red << "No patrol logs available.\n" << White;
			return;
		}

		_PrintPatrolScheduleHeader();

		for (clsPatrolSchedule& Patrol : vPatrolLogs)
		{
			_PrintPatrolScheduleRecordLine(Patrol);
			cout << endl;

		}

		cout << setw(2) << left << "" << Green
			<< "_______________________________________________________________________________________________________________________________________________\n" << White;

	}


public:

	static void ShowAllPatrolSchedulesScreen()
	{

		system("cls");
		clsBase::_DrawScreenHeader("\t    Patrol Schedules List");


		if (clsInputValidate::IsSureToPerform())
		{
			system("cls");

			vector <clsPatrolSchedule> vPatrols = clsPatrolSchedule::GetSchedulesList();

			string Subtitle = "\t\t(" + to_string(vPatrols.size()) + ") Patrol Schedules";
			clsBase::_DrawScreenHeader("\t    Patrol Schedules List", Subtitle);
			_PrintPatrolTable(vPatrols);

		}




	}
};
