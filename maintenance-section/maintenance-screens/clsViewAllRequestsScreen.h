#pragma once
#include <iostream>
#include <vector>
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsMaintenance.h";

using namespace std;


class clsViewAllRequestsScreen : protected clsBase
{

private:
	friend class clsMaintenanceListByStatusScreen;

	static void PrintMainRequestRecordLine(clsMaintenance Request)
	{

		cout << setw(2) << left << "" << Green << "| " << White << setw(12) << left << Request.RequestID;
		cout << Green << "| " << White << setw(15) << left << Request.DormBuilding;
		cout << Green << "| " << White << setw(8) << left << Request.RoomNumber;
		cout << Green << "| " << White << setw(15) << left << Request.IssueType;
		cout << Green << "| " << White << setw(12) << left << clsMaintenance::GetPriorityLevelString (Request.Priority);
		cout << Green << "| " << White << setw(15) << left << clsMaintenance::GetStatusString(Request.Status);
		cout << Green << "| " << White << setw(20) << left << Request.AssignedStaffID;
		cout << Green << "| " << White << setw(25) << left << Request.RequestDate;



	}

	static void PrintMainRequestHeader()
	{

		cout << "\n" << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________\n\n" << White;



		cout << setw(2) << left << "" << Green << "| " << White << setw(12) << left << "Request ID";
		cout << Green << "| " << White << setw(15) << left << "Dorm Building";
		cout << Green << "| " << White << setw(8) << left <<  "Room";
		cout << Green << "| " << White << setw(15) << left << "Issue Type";
		cout << Green << "| " << White << setw(12) << left << "Priority";
		cout << Green << "| " << White << setw(15) << left << "Status";
		cout << Green << "| " << White << setw(20) << left << "Assigned Staff ID";
		cout << Green << "| " << White << setw(25) << left << "Request Date";
		cout << "\n" << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________\n\n" << White;

	}




public:

	static void ShowAllMaintenanceRequestsScreen()
	{
		system("cls");

		clsBase::_DrawScreenHeader("\t    Maintenance Requests List");

		if (clsInputValidate::IsSureToPerform())
		{
			system("cls");
			vector <clsMaintenance> vMainRequests = clsMaintenance::GetMaintenanceRequestsList();
			string Subtitle = "\t\t(" + to_string(vMainRequests.size()) + ") Employees";

			clsBase::_DrawScreenHeader("\t    Maintenance Requests List", Subtitle);

			PrintMainRequestHeader();
			for (clsMaintenance& Request : vMainRequests)
			{
				PrintMainRequestRecordLine(Request);
				cout << endl;
			}

			cout << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________" << White << endl;



		}





	}

};

