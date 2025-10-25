

#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsIncidentReport.h";
#include "clsGlobalRead.h";
#include "clsGlobalPrint.h";

using namespace std;

class clsDeleteIncidentScreen : protected clsBase
{

private:

    static void _PrintSpecificIncidentRecordLine(clsIncidentReport Incident)
    {
        cout << setw(ScreenWidth - 10) << left << "" << Green << "| " << White << setw(15) << left << Incident.IncidentID;
        cout << Green << "| " << White << setw(20) << left << Incident.IncidentType;
        cout << Green << "| " << White << setw(20) << left << clsIncidentReport::GetIncidentStatusString(Incident.Status);
    }

    static void _PrintSpecificIncidentHeader()
    {
        cout << "\n" << setw(ScreenWidth - 10) << left << "" << Green << "---------------------------------------------------------------\n" << White;
        cout << setw(ScreenWidth - 10) << left << "" << Green << "| " << Yellow << setw(15) << left << "Incident ID";
        cout << Green << "| " << Yellow << setw(20) << left << "Incident Type";
        cout << Green << "| " << Yellow << setw(20) << left << "Status" << White;
        cout << "\n" << setw(ScreenWidth - 10) << left << "" << Green << "---------------------------------------------------------------\n" << White;
    }

    static void _PrintSpecificIncidentTable(vector<clsIncidentReport> vIncidents)
    {
        _PrintSpecificIncidentHeader();
        for (clsIncidentReport& incident : vIncidents)
        {
            _PrintSpecificIncidentRecordLine(incident);
            cout << endl;
        }
        cout << setw(ScreenWidth - 10) << left << "" << Green << "---------------------------------------------------------------" << White << endl;

    }

    static void _PrintSmallIncidentListInfo()
    {
        vector<clsIncidentReport> vIncidents = clsIncidentReport::GetIncidentsList();

        if (vIncidents.empty())
        {
            cout << setw(ScreenWidth) << "" << left << Red << "No Incident Reports Available In The System!\n" << White;
        }
        else
        {
            _PrintSpecificIncidentTable(vIncidents);
        }
    }

public:

    static void ShowDeleteIncidentScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\tDelete Incident Report Screen\n");

        if (clsInputValidate::IsSureToPerform())
        {

            _PrintSmallIncidentListInfo();

            string IncidentID = clsGlobalRead::ReadIncidentID();
            clsIncidentReport IncidentToDelete = clsIncidentReport::FindIncident(IncidentID);
            clsGlobalPrint::PrintIncidentInfo(IncidentToDelete);

            cout << "\n" << setw(ScreenWidth) << "" << left << "Are you sure you want to delete this Incident Report permanently? [Y/N]: ";
            if (clsInputValidate::IsAnswerIsYes())
            {
                if (IncidentToDelete.DeleteIncident())
                {
                    cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Incident Report Deleted Successfully :-)\n" << White;
                }
                else
                {
                    cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error: Incident Report was not deleted.\n" << White << endl;
                }
            }

        }

    }
};
