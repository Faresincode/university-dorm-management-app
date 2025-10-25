#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsIncidentReport.h"
#include "clsGlobalPrint.h"
#include "clsGlobalRead.h"
#include "clsUtil.h";

using namespace std;

class clsAddNewIncidentScreen : protected clsBase
{
private:

    static string GenerateNewIncidentID()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Incident ID: ";
        string IncidentID = clsUtil::GenerateID("S.INC");
        while (clsIncidentReport::IsIncidentExist(IncidentID) && IncidentID.length() > 2)
        {
            string IncidentID = clsUtil::GenerateID("S.INC");
        }
        return IncidentID;
    }


    static void ReadFullIncidentInfo(clsIncidentReport &Incident)
    {
        system("cls");
        cout << "\n" << setw(ScreenWidth) << "" << left << "-------------------------------------------------\n";
        cout << setw(ScreenWidth) << "" << left << " Enter Incident Report Details\n";
        cout << setw(ScreenWidth) << "" << left << "-------------------------------------------------\n\n";


        cout << setw(ScreenWidth) << "" << left << "Security ID (Reporter): ";
        Incident.SecurityID = clsGlobalRead::ReadSecurityID();

        cout << setw(ScreenWidth) << "" << left ;
        Incident.IncidentDateTime = clsGlobalRead::ReadDateTime("Read Incident Date/Time (e.g., 2025-10-21 19:30:21): ");

        cout << setw(ScreenWidth) << "" << left << "Incident Type (e.g., Theft, Disturbance, Fire, etc.): ";
        Incident.IncidentType = clsInputValidate::ReadString();

        cout << setw(ScreenWidth) << "" << left << "Description: ";
        Incident.Description = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Select status:\n";
        cout << setw(ScreenWidth) << "" << left << "[1] Open\n";
        cout << setw(ScreenWidth) << "" << left << "[2] InReview\n";
        cout << setw(ScreenWidth) << "" << left << "[3] Resolved\n";
        cout << setw(ScreenWidth) << "" << left << "[4] Closed\n";
        cout << setw(ScreenWidth) << "" << left << "Enter choice [From 1 to 4]: ";
        Incident.Status = (clsIncidentReport::enIncidentStatus)clsInputValidate::ReadNumberBetween<int>(1, 4, "Invalid choice! Please choose 1-3: ");


        cout << "\n" << setw(ScreenWidth) << "" << left << "Select Severity Level:\n";
        cout << setw(ScreenWidth) << "" << left << "[1] Low\n";
        cout << setw(ScreenWidth) << "" << left << "[2] Medium\n";
        cout << setw(ScreenWidth) << "" << left << "[3] High\n";
        cout << setw(ScreenWidth) << "" << left << "Enter choice [From 1 To 3]: ";
        Incident.Severity = (clsIncidentReport::enIncidentSaverity) clsInputValidate::ReadNumberBetween<int>(1, 3, "Invalid choice! Please choose 1-3: ");

        string LastUpdateDateTime = clsDate::GetSystemDateTimeString();

    }
    friend class clsUpdateIncidentScreen;

public:

    static void ShowAddIncidentScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t\tAdd New Incident Report Screen");

        if (clsInputValidate::IsSureToPerform())
        {

            string IncidentID = GenerateNewIncidentID();


            // Read full incident information (from global reader class)
            clsIncidentReport NewIncident = clsIncidentReport::GetAddNewIncidentObject(IncidentID);
            ReadFullIncidentInfo(NewIncident);
            // Save the incident
            clsIncidentReport::enSaveResults SaveResult = NewIncident.SaveIncident();

            // Print result (success, fail, duplicate, etc.)
            clsGlobalPrint::PrintResult(SaveResult, NewIncident);

        }



    }
};
