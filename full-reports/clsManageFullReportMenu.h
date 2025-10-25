
#pragma once
#include <iostream>
#include <iomanip>
#include "clsBase.h"
#include "clsInputValidate.h"

// Include report screens from each module
#include "clsGenerateReportScreen.h"
#include "clsEmployeeReportsScreen.h"
#include "clsGenerateRoomReportsScreen.h"
#include "clsGenerateFinanceReportsScreen.h"
#include "clsSecurityReportsScreen.h"
#include "clsMaintenanceReportsScreen.h"
#include "clsGeneratePatrolReportScreen.h";
using namespace std;

class clsManageFullReportMenu : protected clsBase
{
private:

    enum enReportsMenuOptions
    {
        eStudentReports = 1,
        eEmployeeReports = 2,
        eRoomReports = 3,
        eFinanceReports = 4,
        eSecurityReports = 5,
        eMaintenanceReports = 6,
        ePatrolReport = 7,
        eExit = 8
    };

    static void _GoBackToReportsMenu()
    {
        cout << "\nPress any key to go back to Reports Menu...";
        system("pause>0");
        ShowReportsMenuScreen();
    }

    static short _ReadReportsMenuOption()
    {
        cout << setw(ScreenWidth) << left << "" << "Choose what do you want to view? [1 to 8]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 8, "Enter Number between 1 to 8: ");
        return Choice;
    }

    // === Reports Menu Actions ===

    static void ShowStudentReports()
    {
        clsGenerateReportScreen::showGenerateReportScreen();
    }

    static void ShowEmployeeReports()
    {
        clsEmployeeReportsScreen::ShowEmployeeReportScreen();
    }

    static void ShowRoomReports()
    {
        clsGenerateRoomReportsScreen::GenerateRoomsReportScreen();
    }

    static void ShowFinanceReports()
    {
        clsGenerateFinanceReportsScreen::ShowPaymentsReportScreen();
    }

    static void ShowSecurityReports()
    {
        clsSecurityReportsScreen::ShowSecurityReportsScreen();
    }

    static void ShowMaintenanceReports()
    {
        clsMaintenanceReportsScreen::ShowPaymentsReportScreen();
    }

    static void ShowPatrolReportScreen()
    {
        clsGeneratePatrolReportScreen::ShowGeneratePatrolReportScreen();
    }

    static void _PerformReportsMenuOption(enReportsMenuOptions Option)
    {
        switch (Option)
        {
        case eStudentReports:
            system("cls");
            ShowStudentReports();
            _GoBackToReportsMenu();
            break;

        case eEmployeeReports:
            system("cls");
            ShowEmployeeReports();
            _GoBackToReportsMenu();
            break;

        case eRoomReports:
            system("cls");
            ShowRoomReports();
            _GoBackToReportsMenu();
            break;

        case eFinanceReports:
            system("cls");
            ShowFinanceReports();
            _GoBackToReportsMenu();
            break;

        case eSecurityReports:
            system("cls");
            ShowSecurityReports();
            _GoBackToReportsMenu();
            break;

        case eMaintenanceReports:
            system("cls");
            ShowMaintenanceReports();
            _GoBackToReportsMenu();
            break;

        case ePatrolReport:
            system("cls");
            ShowPatrolReportScreen();
            _GoBackToReportsMenu();
            break;

        case eExit:
        default:
            break;
        }
    }

public:

    static void ShowReportsMenuScreen()
    {

        if (!clsBase::_CheckAccessRights(clsLogin::eFullReports))
        {
            return;
        }

        system("cls");
        clsBase::_DrawScreenHeader("\tDorm System - Reports Management");

        cout << setw(ScreenWidth) << left << "" << Green << "=========================================================\n";
        cout << setw(ScreenWidth) << left << "" << Red << "\tDorm Management Reports Menu\n";
        cout << setw(ScreenWidth) << left << "" << Green << "=========================================================\n" << White;

        cout << setw(ScreenWidth) << left << "" << " [1]  Student Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [2]  Employee Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [3]  Room Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [4]  Finance Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [5]  Security Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [6]  Maintenance Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [7]  Patrol Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [8]  Exit.\n";

        cout << setw(ScreenWidth) << left << "" << Green << "=========================================================\n" << White;

        _PerformReportsMenuOption((enReportsMenuOptions)_ReadReportsMenuOption());
    }



};
