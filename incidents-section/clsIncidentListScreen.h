

#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsIncidentReport.h"

using namespace std;

class clsIncidentListScreen : protected clsBase
{

private:

	static void PrintIncidentTableRecordLine(clsIncidentReport Incident)
	{
		cout << setw(2) << left << "" << Green << "| " << White << setw(13) << left << Incident.IncidentID;
		cout << Green << "| " << White << setw(13) << left << Incident.SecurityID;
		cout << Green << "| " << White << setw(22) << left << Incident.IncidentDateTime;
		cout << Green << "| " << White << setw(30) << left << Incident.IncidentType;
		cout << Green << "| " << White << setw(8 ) << left << clsIncidentReport::GetSeverityString(Incident.Severity);
		cout << Green << "| " << White << setw(10) << left << clsIncidentReport::GetIncidentStatusString(Incident.Status);
		cout << Green << "| " << White << setw(22) << left << Incident.LastUpdateDateTime;
	}

	static void PrintIncidentTableHeader()
	{
		cout << "\n" << setw(1) << left << "" << Green
			<< "_______________________________________________________________________________________________________________________________________________\n\n" << White;

		cout << setw(2) << left << "" << Green << "| " << White << setw(13) << left << "Incident ID";
		cout << Green << "| " << White << setw(13) << left << "Security ID";
		cout << Green << "| " << White << setw(22) << left << "Date/Time";
		cout << Green << "| " << White << setw(30) << left << "Incident Type";
		cout << Green << "| " << White << setw(8 ) << left << "Severity";
		cout << Green << "| " << White << setw(10) << left << "Status";
		cout << Green << "| " << White << setw(22) << left << "Last Update";

		cout << "\n" << setw(1) << left << "" << Green
			<< "_______________________________________________________________________________________________________________________________________________\n\n" << White;
	}

	static void PrintIncidentTable(vector <clsIncidentReport> vIncidents)
	{

		PrintIncidentTableHeader();
		for (clsIncidentReport& Incident : vIncidents)
		{
			PrintIncidentTableRecordLine(Incident);
			cout << endl;
		}

		cout << setw(1) << left << "" << Green
			<< "_______________________________________________________________________________________________________________________________________________\n" << White << endl;
	}


public:

	static void ShowIncidentListScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\tIncident Reports List");


		if (clsInputValidate::IsSureToPerform())
		{
			system("cls");

			vector <clsIncidentReport> vIncidents = clsIncidentReport::GetIncidentsList();

			string Subtitle = "\t\t(" + to_string(vIncidents.size()) + ") Incidents";
			clsBase::_DrawScreenHeader("\tIncident Reports List", Subtitle);

			if (vIncidents.size() == 0)
			{
				cout << Red << "| " << White << setw(15) << left << "No Incident Available in the system"<<White;
			}
			else
			{
				PrintIncidentTable(vIncidents);

			}


		}





	}
};
