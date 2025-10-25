#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsSecurity.h"
#include "clsSecurityListScreen.h"
#include "clsFindSecurityScreen.h"
#include "clsUpdateSecurityInfoScreen.h"
#include "clsDeleteSecurityScreen.h"
#include "clsAddNewSecurityScreen.h"
#include "clsManageVisitorMenuScreen.h"
#include "clsManageIncidentMenuScreen.h"
#include "clsSecurityReportsScreen.h"
#include "clsManagePatrolMenuScreen.h";

using namespace std;

class clsManageSecurityMenuScreen : protected clsBase
{
private:

    enum enSecurityMenuOptions
    {
        eShowSecurityList = 1,
        eFindSecurity = 2,
        eUpdateSecurityInfo = 3,
        eDeleteSecurity = 4,
        eSetPatrolSchedules = 5,
        eShowVisitorLogs = 6,
        eAddNewSecurity = 7,
        eReportIncident = 8,
        eGenerateSecurityReports = 9,
        eExit = 10
    };

    
    static void _GoBackToSecurityMenu()
    {
        cout << "Press any key to go back to Security Menu...";
        system("pause>0");
        ShowSecurityMenuScreen();
    }

    static short _ReadSecurityMenuOption()
    {
        cout << setw(ScreenWidth) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 10, "Enter Number between 1 to 10: ");
        return Choice;
    }

    static void ShowSecurityList()
    {
        clsSecurityListScreen::ShowSecurityListScreen();
    }

    static void FindSecurity()
    {
        clsFindSecurityScreen::ShowFindSecurityScreen();
    }

    static void UpdateSecurityInfo()
    {
        clsUpdateSecurityInfoScreen::ShowUpdateSecurityInfoScreen();
    }

    static void DeleteSecurity()
    {
        clsDeleteSecurityScreen::ShowDeleteSecurityScreen();
    }

    static void ManagePatrolSchedulesMenu()
    {
        clsManagePatrolMenuScreen::ShowPatrolSchedulesMenuScreen();
    }

    static void ShowVisitorLogs()
    {
        clsManageVisitorMenuScreen::ShowVisitorMenuScreen();
    }

    static void AddNewSecurity()
    {
        clsAddNewSecurityScreen::ShowAddNewSecurityScreen();
    }

    static void ReportIncident()
    {
        clsManageIncidentMenuScreen::ShowIncidentReportMenuScreen();
    }

    static void GenerateSecurityReports()
    {
        clsSecurityReportsScreen::ShowSecurityReportsScreen();
    }

    static void _PerformSecurityMenuOption(enSecurityMenuOptions SecurityMenuOption)
    {
        switch (SecurityMenuOption)
        {
        case enSecurityMenuOptions::eShowSecurityList:
            system("cls");
            ShowSecurityList();
            _GoBackToSecurityMenu();
            break;

        case enSecurityMenuOptions::eFindSecurity:
            system("cls");
            FindSecurity();
            _GoBackToSecurityMenu();
            break;

        case enSecurityMenuOptions::eUpdateSecurityInfo:
            system("cls");
            UpdateSecurityInfo();
            _GoBackToSecurityMenu();
            break;

        case enSecurityMenuOptions::eDeleteSecurity:
            system("cls");
            DeleteSecurity();
            _GoBackToSecurityMenu();
            break;

        case enSecurityMenuOptions::eSetPatrolSchedules:
            system("cls");
            ManagePatrolSchedulesMenu();
            _GoBackToSecurityMenu();
            break;

        case enSecurityMenuOptions::eShowVisitorLogs:
            system("cls");
            ShowVisitorLogs();
            _GoBackToSecurityMenu();
            break;

        case enSecurityMenuOptions::eAddNewSecurity:
            system("cls");
            AddNewSecurity();
            _GoBackToSecurityMenu();
            break;

        case enSecurityMenuOptions::eReportIncident:
            system("cls");
            ReportIncident();
            _GoBackToSecurityMenu();
            break;

        case enSecurityMenuOptions::eGenerateSecurityReports:
            system("cls");
            GenerateSecurityReports();
            _GoBackToSecurityMenu();
            break;

        case enSecurityMenuOptions::eExit:
        default:
            break;
        }
    }
    

public:

    static void ShowSecurityMenuScreen()
    {

        if (!clsBase::_CheckAccessRights(clsLogin::eManageSecurity))
        {
            return;
        }

        system("cls");
        clsBase::_DrawScreenHeader("\tManage Dorm Security Screen");

        
        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n";
        cout << setw(ScreenWidth) << left << "" << Red << "\tManage Dorm Security Menu\n";
        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;

        cout << setw(ScreenWidth) << left << "" << " [1]   Show Security Staff List.\n";
        cout << setw(ScreenWidth) << left << "" << " [2]   Find Security Staff.\n";
        cout << setw(ScreenWidth) << left << "" << " [3]   Update Security Info.\n";
        cout << setw(ScreenWidth) << left << "" << " [4]   Delete Security Staff.\n";
        cout << setw(ScreenWidth) << left << "" << " [5]   Manage Patrol Schedules Menu.\n";
        cout << setw(ScreenWidth) << left << "" << " [6]   Manage View Visitor Logs Menu.\n";
        cout << setw(ScreenWidth) << left << "" << " [7]   Add New Security Staff.\n";
        cout << setw(ScreenWidth) << left << "" << " [8]   Manage Report Incident.\n";
        cout << setw(ScreenWidth) << left << "" << " [9]   Generate Security Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [10]  Exit.\n";

        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;

        _PerformSecurityMenuOption((enSecurityMenuOptions)_ReadSecurityMenuOption());
    }
   

};
