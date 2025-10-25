#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsEmployee.h";
#include "clsUpdateEmployeeInfoScreen.h";
#include "clsDeleteEmployeeScreen.h";
#include "clsEmployeeListScreen.h";
#include "clsFindEmployeeScreen.h";
#include "clsAddNewEmployeeScreen.h";
#include "clsAssignEmployeeScreen.h";
#include "clsEmployeesByJobTitleScreen.h";
#include "clsSetWorkSchedulesScreen.h";
#include "clsScheduleEmployeeScreen.h";
#include "clsEmployeeReportsScreen.h".

using namespace std;



class clsManageEmployeeScreen :protected clsBase
{
private:
    enum enEmployeeMenuOptions
    {
        eShowEmployeeList = 1,
        eFindEmployee = 2,
        eUpdateEmployeeInfo = 3,
        eDeleteEmployee = 4,
        eSetWorkSchedules = 5,
        eShowScheduleList=6,
        eAddNewEmployee = 7,
        eShowEmployeesByJobTitle = 8,
        eAssignEmployee=9,
        eGenerateEmployeeReports = 10,
        eExit = 11
    };

    static  void _GoBackToEmployeeMenu()
    {
        cout << "Press any key to go back to Main Menu...";
        system("pause>0");
        ShowEmployeeMenuScreen();
    }

    static short _ReadManageEmployeeMenuOption()
    {
        cout << setw(ScreenWidth) << left << "" << "Choose what do you want to do? [1 to 11]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 11, "Enter Number between 1 to 11? ");
        return  Choice;

    }

    static void ShowEmployeeList()
    {
        clsEmployeeListScreen::ShowEmployeeListScreen();
    }

    static void FindEmployee()
    {
        clsFindEmployeeScreen::ShowFindEmployeeScreen();
    }

    static void UpdateEmployeeInfo()
    {
        clsUpdateEmployeeInfoScreen::ShowUpdateDormEmployeeScreen();
    }

    static void DeleteEmployee()
    {
        clsDeleteEmployeeScreen::ShowDeleteDormEmployee();
    }

    static void SetWorkSchedules()
    {
        clsSetWorkSchedulesScreen::ShowSetWorkSchedulesScreen();
    }

    static void ShowEmployeeScheduleList()
    {

        clsScheduleEmployeeScreen::ShowScheduleEmployeeTableScreen();

    }

    static void AddNewEmployee()
    {
        clsAddNewEmployeeScreen::ShowAddNewEmployeeScreen();
    }

    static void ShowEmployeesByJobTitle()
    {
        clsEmployeesByJobTitleScreen::ShowEmployeesListByJobTitleScreen();
    }

    static void AssignEmployee()
    {
        clsAssignEmployeeScreen::ShowAssignDormEmployeeScreen();
    }

    static void GenerateEmployeeReports()
    {
        clsEmployeeReportsScreen::ShowEmployeeReportScreen();
    }


    static void _PerformEmployeeMenuOption(enEmployeeMenuOptions EmployeeMenuOption)
    {
        switch (EmployeeMenuOption)
        {
        case enEmployeeMenuOptions::eShowEmployeeList:
            system("cls");
            ShowEmployeeList();
            _GoBackToEmployeeMenu();
            break;

        case enEmployeeMenuOptions::eFindEmployee:
            system("cls");
            FindEmployee();
            _GoBackToEmployeeMenu();
            break;

        case enEmployeeMenuOptions:: eUpdateEmployeeInfo:
            system("cls");
            UpdateEmployeeInfo();
            _GoBackToEmployeeMenu();
            break;

        case enEmployeeMenuOptions::eDeleteEmployee:
            system("cls");
            DeleteEmployee();
            _GoBackToEmployeeMenu();
            break;

        case enEmployeeMenuOptions::eSetWorkSchedules:
            system("cls");
            SetWorkSchedules();
            _GoBackToEmployeeMenu();
            break;
        case enEmployeeMenuOptions::eShowScheduleList:
            system("cls");
            ShowEmployeeScheduleList();
            _GoBackToEmployeeMenu();
            break;


        case enEmployeeMenuOptions::eAddNewEmployee:
            system("cls");
            AddNewEmployee();
            _GoBackToEmployeeMenu();
            break;

        case enEmployeeMenuOptions::eShowEmployeesByJobTitle:
            system("cls");
            ShowEmployeesByJobTitle();
            _GoBackToEmployeeMenu();
            break;

        case enEmployeeMenuOptions::eAssignEmployee:
            system("cls");
            AssignEmployee();
            _GoBackToEmployeeMenu();
            break;

        case enEmployeeMenuOptions::eGenerateEmployeeReports:
            system("cls");
            GenerateEmployeeReports();
            _GoBackToEmployeeMenu();
            break;

        case enEmployeeMenuOptions::eExit:

        default:
            // No action, just exit
            break;
        }
    }


public:

    static void ShowEmployeeMenuScreen()
    {

        if (!clsBase::_CheckAccessRights(clsLogin::eManageEmployee))
        {
            return;
        }
            
        system("cls");
        clsBase::_DrawScreenHeader("\tManage Dorm Employees Screen");

        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n";
        cout << setw(ScreenWidth) << left << "" << Red << "\tManage Dorm Employees Menu\n";
        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;

        cout << setw(ScreenWidth) << left << "" << " [1]   Show Employee List.\n";
        cout << setw(ScreenWidth) << left << "" << " [2]   Find Employee.\n";
        cout << setw(ScreenWidth) << left << "" << " [3]   Update Employee Info.\n";
        cout << setw(ScreenWidth) << left << "" << " [4]   Delete Employee.\n";
        cout << setw(ScreenWidth) << left << "" << " [5]   Set Work Schedules.\n";
        cout << setw(ScreenWidth) << left << "" << " [6]   Employee Schedules List.\n";
        cout << setw(ScreenWidth) << left << "" << " [7]   Add New Employee.\n";
        cout << setw(ScreenWidth) << left << "" << " [8]   Show Employees by Job Title.\n";
        cout << setw(ScreenWidth) << left << "" << " [9]   Assign Employee.\n";
        cout << setw(ScreenWidth) << left << "" << " [10]  Generate Employee Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [11]  Exit.\n";

        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;
        _PerformEmployeeMenuOption((enEmployeeMenuOptions) _ReadManageEmployeeMenuOption());


    }








};

