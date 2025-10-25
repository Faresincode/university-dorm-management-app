

#pragma once
#include <iostream>
#include <vector>
#include "clsBase.h"
#include "clsSecurity.h"
#include "clsIncidentReport.h"
#include "clsInputValidate.h"
#include "clsGlobalPrint.h"

using namespace std;

class clsSecurityReportsScreen : protected clsBase
{

private:

    static void _PrintSummaryLine(string Title, string Value)
    {
        cout << setw(ScreenWidth - 10) << left << "" << Green << "| " << White<< setw(35) << left << Title << "| " << Yellow << setw(10) << left << Value << White << endl;
    }

    static void _PrintHeader()
    {
        cout << "\n" << setw(ScreenWidth - 10) << left << "" << Green<< "==============================================================\n" << White;
        cout << setw(ScreenWidth - 10) << left << "" << Green
            << "| " << Yellow << setw(35) << left << "Report Category"
            << "| " << Yellow << setw(10) << left << "Count" << White;
        cout << "\n" << setw(ScreenWidth - 10) << left << "" << Green << "==============================================================\n" << White;
    }


public:

    static void ShowSecurityReportsScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\tGenerate Security Reports");

        if (clsInputValidate::IsSureToPerform())
        {
            // Load data
            system("cls");
            clsBase::_DrawScreenHeader("\tGenerate Security Reports");

            vector<clsSecurity> vSecurity = clsSecurity::GetSecurityList();
            vector<clsIncidentReport> vIncidents = clsIncidentReport::GetIncidentsList();


            clsIncidentReport::stIncidentsCount IncidentCounter = clsIncidentReport::CountIncidents();
            // Print summary
            _PrintHeader();
            _PrintSummaryLine("Total Security Staff", to_string(vSecurity.size()));
            _PrintSummaryLine("Total Incidents Reported", to_string(vIncidents.size()));
            _PrintSummaryLine("Open Incidents", to_string(IncidentCounter.Open));
            _PrintSummaryLine("In Review Incidents", to_string(IncidentCounter.InReview));
            _PrintSummaryLine("Resolved Incidents", to_string(IncidentCounter.Resolved));
            _PrintSummaryLine("Closed Incidents", to_string(IncidentCounter.Closed));
            _PrintSummaryLine("Low Severity Incidents", to_string(IncidentCounter.LowSaverity));
            _PrintSummaryLine("Medium Severity Incidents", to_string(IncidentCounter.MediumSaverity));
            _PrintSummaryLine("High Severity Incidents", to_string(IncidentCounter.HighSaverity));

            cout << setw(ScreenWidth - 10) << left << "" << Green<< "=============================================================="<<endl << White;



        }


    }
};

