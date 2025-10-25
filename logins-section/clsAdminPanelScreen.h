
#pragma once
#include <iostream>
#include <iomanip>
#include "clsBase.h";
#include "clsInputValidate.h";

#include "clsManageDormStudentsScreen.h";
#include "clsManageEmployeeScreen.h";
#include "clsManageFinanceMenuScreen.h";
#include "clsManageRoomsScreens.h";
#include "clsManageSecurityMenuScreen.h";
#include "clsManageMaintenanceScreen.h";
#include "clsManageFullReportMenu.h";
#include "clsRegisterLoginScreen.h";
#include "clsAddNewResponsibleScreen.h";

using namespace std;

class clsAdminPanelScreen : protected clsBase
{
private:

    enum enManageDormMenuOptions
    {
        eManageStudents = 1,
        eManageEmployees = 2,
        eManageFinance = 3,
        eManageRooms = 4,
        eManageSecurity = 5,
        eManageMaintenance = 6,
        eFullDormReport = 7,
        eLoginRegister = 8,
        eAddNewResponsible=9,
        eLogout = 10
    };

    static void _GoBackToManageDormMenu()
    {
        cout << "\nPress any key to go back to the Manage Dorm Menu...";
        system("pause>0");
        ShowManageDormMenuScreen();
    }

    static short _ReadManageDormMenuOption()
    {
        cout << setw(ScreenWidth) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 10, "Enter Number between 1 to 10: ");
        return Choice;
    }

    static void ManageStudents()
    {
        clsManageDormStudentsScreen::ShowManageStudentsDormMenu();
    }

    static void ManageEmployees()
    {
        clsManageEmployeeScreen::ShowEmployeeMenuScreen();
    }

    static void ManageFinance()
    {
        clsManageFinanceMenuScreen::ShowManageFinanceMenu();
    }

    static void ManageRooms()
    {
        clsManageRoomsScreens::ShowManageDormRoomsMenu();
    }

    static void ManageSecurity()
    {
        clsManageSecurityMenuScreen::ShowSecurityMenuScreen();
    }

    static void ManageMaintenance()
    {
        clsManageMaintenanceScreen::ShowMaintenanceMenuScreen();
    }

    static void ManageReportsScreens()
    {
        clsManageFullReportMenu::ShowReportsMenuScreen();

    }
    static void LoginRegister()
    {
        clsRegisterLoginScreen::RegisterLoginScreen();

    }

    static void AddNewResponsible()
    {
        clsAddNewResponsibleScreen::ShowAddNewResponsibleScreen();
    }
    static void _PerformManageDormMenuOption(enManageDormMenuOptions Option)
    {
        switch (Option)
        {
        case enManageDormMenuOptions::eManageStudents:
            system("cls");
            ManageStudents();
            _GoBackToManageDormMenu();
            break;

        case enManageDormMenuOptions::eManageEmployees:
            system("cls");
            ManageEmployees();
            _GoBackToManageDormMenu();
            break;

        case enManageDormMenuOptions::eManageFinance:
            system("cls");
            ManageFinance();
            _GoBackToManageDormMenu();
            break;

        case enManageDormMenuOptions::eManageRooms:
            system("cls");
            ManageRooms();
            _GoBackToManageDormMenu();
            break;

        case enManageDormMenuOptions::eManageSecurity:
            system("cls");
            ManageSecurity();
            _GoBackToManageDormMenu();
            break;

        case enManageDormMenuOptions:: eManageMaintenance:
            system("cls");
            ManageMaintenance();
            _GoBackToManageDormMenu();
            break;
        case enManageDormMenuOptions::eFullDormReport:
            system("cls");
            ManageReportsScreens();
            _GoBackToManageDormMenu();
        case enManageDormMenuOptions::eLoginRegister:
            system("cls");
            LoginRegister();
            _GoBackToManageDormMenu();
        case enManageDormMenuOptions::eAddNewResponsible:
            system("cls");
            AddNewResponsible();
            _GoBackToManageDormMenu();
        case eLogout:
        {

            vector<clsLogin::stLoginRegister>vLoginRegister = clsLogin::GetRegisterLoginsList();
            vLoginRegister[vLoginRegister.size()-1].LogoutDateTime= clsDate::GetSystemDateTimeString();
            clsLogin::SaveLogRegistersDataToFile(vLoginRegister);
        }

        default:
            break;
        }
    }

public:

    static void ShowManageDormMenuScreen()
    {       
        system("cls");

        clsBase::_DrawScreenHeader("\t    Admin Panel Main Menu");
        cout << "\n\n";

        cout << setw(ScreenWidth) << left << "" << Green << "==================================================\n";
        cout << setw(ScreenWidth) << left << "" << Red <<   "             Admin Panel Main Menu\n";
        cout << setw(ScreenWidth) << left << "" << Green << "==================================================\n" << White;

        cout << setw(ScreenWidth) << left << "" << " [1]  Manage Students.\n";
        cout << setw(ScreenWidth) << left << "" << " [2]  Manage Employees.\n";
        cout << setw(ScreenWidth) << left << "" << " [3]  Manage Finance.\n";
        cout << setw(ScreenWidth) << left << "" << " [4]  Manage Rooms.\n";
        cout << setw(ScreenWidth) << left << "" << " [5]  Manage Security.\n";
        cout << setw(ScreenWidth) << left << "" << " [6]  Manage Maintenance.\n";
        cout << setw(ScreenWidth) << left << "" << " [7]  Full Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [8]  Login Register.\n";
        cout << setw(ScreenWidth) << left << "" << " [9]  Add New Responsible.\n";
        cout << setw(ScreenWidth) << left << "" << " [10] Logout.\n";

        cout << setw(ScreenWidth) << left << "" << Green << "==================================================\n" << White;

        _PerformManageDormMenuOption((enManageDormMenuOptions)_ReadManageDormMenuOption());


    }
};
