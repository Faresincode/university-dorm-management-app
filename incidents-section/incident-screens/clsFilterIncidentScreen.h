

#pragma once
#include <iostream>
#include <vector>
#include "clsBase.h"
#include "clsIncidentReport.h"
#include "clsInputValidate.h"
#include "clsGlobalPrint.h"
#include "clsGlobalRead.h";

using namespace std;

class clsFilterIncidentScreen : protected clsBase
{

private:

    enum enFilterOption { eByStatus = 1, eBySeverity = 2, eBySecurityID = 3, eByType = 4, eAll = 5,eExit=6 };

    static void GoBackToFilterMenu()
    {
        cout << "\n\nPress any key to go back To filtre menue... ";
        system("pause >0");
        ShowFilterIncidentScreen();

    }

    static void _ShowFilterMenu()
    {


        cout << "\n" << setw(ScreenWidth) << "" << Green << "================ Incident Filter Menu ================\n" << White;
        cout << setw(ScreenWidth) << "" << left << " [1] Filter By Status\n";
        cout << setw(ScreenWidth) << "" << left << " [2] Filter By Severity\n";
        cout << setw(ScreenWidth) << "" << left << " [3] Filter By Security ID\n";
        cout << setw(ScreenWidth) << "" << left << " [4] Filter By Incident Type\n";
        cout << setw(ScreenWidth) << "" << left << " [5] Show All\n";
        cout << setw(ScreenWidth) << "" << left << " [6] Exit\n";

        cout << setw(ScreenWidth) << "" << Green << "=====================================================\n" << White;
        cout << setw(ScreenWidth) << "" << Yellow << "Choose a filter option [ From 1 To 6 ]: " << White;
        enFilterOption choice = (enFilterOption)clsInputValidate::ReadNumberBetween<short>(1, 6);
        _PerformFiltredIncidents(choice);

    }

    static void _PrintFilteredIncidents(vector<clsIncidentReport> vFiltered)
    {
        for (clsIncidentReport& Incident : vFiltered)
        {
            clsGlobalPrint::PrintIncidentInfo(Incident);
            cout << "\n\n";
        }
    }

    static void _PerformFiltredIncidents(enFilterOption choice)
    {

        vector<clsIncidentReport> vIncidents = clsIncidentReport::GetIncidentsList();
        vector<clsIncidentReport> vFiltered;

        switch (choice)
        {
        case eByStatus:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Status [1=Open, 2=InReview, 3=Resolved, 4=Closed]: ";
            short Status = clsInputValidate::ReadNumberBetween<short>(1, 4);
            vFiltered = clsIncidentReport::GetIncidentListByStatus((clsIncidentReport::enIncidentStatus)Status);
            _PrintFilteredIncidents(vFiltered);

            GoBackToFilterMenu();
            break;
        }

        case eBySeverity:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Severity [1=Low, 2=Medium, 3=High]: ";
            short Severity = clsInputValidate::ReadNumberBetween<short>(1, 3);
            vFiltered = clsIncidentReport::GetIncidentListBySaverity((clsIncidentReport::enIncidentSaverity)Severity);
            _PrintFilteredIncidents(vFiltered);
            GoBackToFilterMenu();

            break;
        }

        case eBySecurityID:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Security ID: ";
            string SecID = clsGlobalRead::ReadSecurityID();
            vFiltered = clsIncidentReport::GetIncidentListBySeCurityID(SecID);
            _PrintFilteredIncidents(vFiltered);

            GoBackToFilterMenu();

            break;
        }

        case eByType:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Incident Type: ";
            string type = clsInputValidate::ReadString();
            vFiltered = clsIncidentReport::GetIncidentListByType(type);
            _PrintFilteredIncidents(vFiltered);

            GoBackToFilterMenu();

            break;
        }

        case eAll:
            _PrintFilteredIncidents(vIncidents);
            GoBackToFilterMenu();
            break;
        case eExit:
            break;


        default:
            _PrintFilteredIncidents(vIncidents);
            GoBackToFilterMenu();        
            break;
        }



    }

public:

    static void ShowFilterIncidentScreen()
    {

        system("cls");

        clsBase::_DrawScreenHeader("\tFilter Incident Reports Screen");



        _ShowFilterMenu();
        

    }
};



