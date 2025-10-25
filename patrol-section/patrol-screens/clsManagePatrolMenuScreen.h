#pragma once
#include <iostream>
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsAddNewPatrolScheduleScreen.h"
#include "clsDeletePatrolScheduleScreen.h";
#include "clsFindPatrolScheduleScreen.h"
#include "clsGeneratePatrolReportScreen.h"
#include "clsViewAllPatrolSchedulesScreen.h"
#include "clsUpdatePatrolScheduleScreen.h"
#include "clsViewPatrolLogsScreen.h"

using namespace std;

class clsManagePatrolMenuScreen : protected clsBase
{

private:

    enum enPatrolScheduleMenuOptions {
        eAddNewSchedule = 1,
        eViewAllSchedules = 2,
        eFindSchedule = 3,
        eUpdateSchedule = 4,
        eDeleteSchedule = 5,
        eViewPatrolLogs = 6,
        eGeneratePatrolReport = 7,
        eExit = 8
    };

    static short _ReadPatrolScheduleMenuOption()
    {
        cout << setw(ScreenWidth) << "" << left << Yellow << "Choose an option [1 to 8]: " << White;
        return clsInputValidate::ReadNumberBetween<short>(1, 8);
    }

    static void _GoBackToPatrolSchedulesMenu()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Press any key to return to Patrol Schedules Menu...";
        system("pause>0");
        ShowPatrolSchedulesMenuScreen();
    }


    static void _ShowAddNewPatrolScheduleScreen()
    {
        clsAddNewPatrolScheduleScreen::ShowAddNewPatrolScheduleScreen();
    }

    static void _ShowAllPatrolSchedulesScreen()
    {

        clsViewAllPatrolSchedulesScreen::ShowAllPatrolSchedulesScreen();

    }
   
    static void _ShowFindPatrolScheduleScreen()
    {
        clsViewAllPatrolSchedulesScreen::ShowAllPatrolSchedulesScreen();

    }
   
    static void _ShowUpdatePatrolScheduleScreen()
    {
        clsUpdatePatrolScheduleScreen::ShowUpdatePatrolScheduleScreen();


    }
    
    static void _ShowDeleteScheduleScreen()
    {
        clsDeletePatrolScheduleScreen::ShowDeletePatrolScheduleScreen();


    }

    
    static void _ShowViewPatrolLogsScreen()
    {

        clsViewPatrolLogsScreen::ShowViewPatrolLogsScreen();

    }

    static void _ShowGeneratePatrolReportScreen()
    {
        clsGeneratePatrolReportScreen::ShowGeneratePatrolReportScreen();

    }

    static void _PerformPatrolScheduleMenuOption(enPatrolScheduleMenuOptions Option)
    {

        switch (Option)
        {
        case eAddNewSchedule:
            system("cls");

            _ShowAddNewPatrolScheduleScreen();
            _GoBackToPatrolSchedulesMenu();
            break;

        case eViewAllSchedules:
            system("cls");

            _ShowAllPatrolSchedulesScreen();
            _GoBackToPatrolSchedulesMenu();

            break;

        case eFindSchedule:
            system("cls");

            _ShowFindPatrolScheduleScreen();
            _GoBackToPatrolSchedulesMenu();

             break;

        case eUpdateSchedule:
            _ShowUpdatePatrolScheduleScreen();
            _GoBackToPatrolSchedulesMenu();

            break;

        case eDeleteSchedule:
            system("cls");

            _ShowDeleteScheduleScreen();
            _GoBackToPatrolSchedulesMenu();

            break;

        case eViewPatrolLogs:
            system("cls");

            _ShowViewPatrolLogsScreen();
            _GoBackToPatrolSchedulesMenu();

            break;

        case eGeneratePatrolReport:
            system("cls");

            _ShowGeneratePatrolReportScreen();
            _GoBackToPatrolSchedulesMenu();

            break;

        case eExit:
            return;
        }

    }

    static void _PrintPatrolSchedulesMenuHeader()
    {
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n";
        cout << setw(ScreenWidth) << "" << left << Red << "         Patrol Schedules Management Menu\n";
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n" << White;

        cout << setw(ScreenWidth) << "" << left << "[1] Add New Patrol Schedule\n";
        cout << setw(ScreenWidth) << "" << left << "[2] View All Patrol Schedules\n";
        cout << setw(ScreenWidth) << "" << left << "[3] Find Patrol Schedule\n";
        cout << setw(ScreenWidth) << "" << left << "[4] Update Patrol Schedule\n";
        cout << setw(ScreenWidth) << "" << left << "[5] Delete Patrol Schedule\n";
        cout << setw(ScreenWidth) << "" << left << "[6] View Patrol Logs\n";
        cout << setw(ScreenWidth) << "" << left << "[7] Generate Patrol Report\n";
        cout << setw(ScreenWidth) << "" << left << "[8] Exit\n";

        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n\n";

        _PerformPatrolScheduleMenuOption((enPatrolScheduleMenuOptions)_ReadPatrolScheduleMenuOption());
    }

public:

    static void ShowPatrolSchedulesMenuScreen()
    {
        system("cls");
        _DrawScreenHeader("\tPatrol Schedules Menu");

        _PrintPatrolSchedulesMenuHeader();



    }



};
