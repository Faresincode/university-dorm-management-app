#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsIncidentReport.h"
#include "clsGlobalPrint.h"
#include "clsGlobalRead.h"
#include "clsAddNewIncidentScreen.h";
using namespace std;

class clsUpdateIncidentScreen : protected clsBase
{

private:


    enum enWhatToUpdate
    {
        eIncidentType = 1,
        eDescription = 2,
        eSeverity = 3,
        eStatus = 4,
        eSecurityID = 5,
        eAll = 6,
        eExit=7
    };

    static void _PerformUpdateMenuScreen(enWhatToUpdate WhatToUpdate, clsIncidentReport& Incident)
    {
        switch (WhatToUpdate)
        {
        case eIncidentType:
        {
            cout << setw(ScreenWidth) << "" << left << "Incident Type (e.g., Theft, Disturbance, Fire, etc.): ";
            Incident.IncidentType = clsInputValidate::ReadString();
            break;
        }

        case eDescription:
        {
            cout << setw(ScreenWidth) << "" << left << "Description: ";
            Incident.Description = clsInputValidate::ReadString();
            break;
        }

        case eSeverity:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Select Severity Level:\n";
            cout << setw(ScreenWidth) << "" << left << "[1] Low\n";
            cout << setw(ScreenWidth) << "" << left << "[2] Medium\n";
            cout << setw(ScreenWidth) << "" << left << "[3] High\n";
            cout << setw(ScreenWidth) << "" << left << "Enter choice [From 1 To 3]: ";
            Incident.Severity = (clsIncidentReport::enIncidentSaverity)clsInputValidate::ReadNumberBetween<int>(1, 3, "Invalid choice! Please choose 1-3: ");
            break;
        }

        case eStatus:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Select status:\n";
            cout << setw(ScreenWidth) << "" << left << "[1] Open\n";
            cout << setw(ScreenWidth) << "" << left << "[2] InReview\n";
            cout << setw(ScreenWidth) << "" << left << "[3] Resolved\n";
            cout << setw(ScreenWidth) << "" << left << "[4] Closed\n";
            cout << setw(ScreenWidth) << "" << left << "Enter choice [From 1 to 4]: ";
            Incident.Status = (clsIncidentReport::enIncidentStatus)clsInputValidate::ReadNumberBetween<int>(1, 4, "Invalid choice! Please choose 1-3: ");
            break;
        }

        case eSecurityID:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Security Staff ID: ";
            Incident.SecurityID = clsGlobalRead::ReadSecurityID();
            break;
        }

        case eAll:
        {
            clsAddNewIncidentScreen::ReadFullIncidentInfo(Incident);
            break;
        }
        case eExit:
            return;

        default:
            clsAddNewIncidentScreen::ReadFullIncidentInfo(Incident);
            break;
        }

    }

    static void _ShowUpdateMenuScreen(clsIncidentReport& Incident)
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================";
        cout << "\n" << setw(ScreenWidth) << "" << left << Red << "        Update Incident Info Menu Screen";
        cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
        cout << "\n" << setw(ScreenWidth) << "" << left << " [1] Incident Type";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [2] Description";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [3] Severity";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [4] Status";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [5] Security ID";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [6] Update All";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [7] Exit ";

        cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================\n\n";

        cout << setw(ScreenWidth) << "" << left << Yellow << "What do you want to update (1 to 7)? : " << White;
        _PerformUpdateMenuScreen((enWhatToUpdate)clsInputValidate::ReadNumberBetween<short>(1, 7), Incident);
    }

public:

    static void ShowUpdateIncidentInfoScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t\tUpdate Incident Report Screen\n");

        if (clsInputValidate::IsSureToPerform())
        {
            string IncidentID = clsGlobalRead::ReadIncidentID();
            clsIncidentReport Incident = clsIncidentReport::FindIncident(IncidentID);
            clsGlobalPrint::PrintIncidentInfo(Incident);
            _ShowUpdateMenuScreen(Incident);

            clsIncidentReport::enSaveResults SaveResult = Incident.SaveIncident();
            clsGlobalPrint::PrintResult(SaveResult, Incident);




        }



    }
};
