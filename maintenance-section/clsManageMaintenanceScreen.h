#pragma once
#include <iostream>
#include <vector>
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsAddMaintenanceRequestScreen.h";
#include "clsViewAllRequestsScreen.h";
#include "clsUpdateRequestStatusScreen.h"
#include "clsAssignStaffScreen.h"
#include "clsMaintenanceReportsScreen.h"
#include "clsFindMaintenanceRequestScreen.h";
#include "clsDeleteMaintenanceRequestScreen.h";
#include "clsMaintenanceListByStatusScreen.h";

using namespace std;

class clsManageMaintenanceScreen : protected clsBase
{
private:

    enum enMaintenanceMenuOptions
    {
        eAddMaintenanceRequest = 1,
        eViewAllRequests = 2,
        eViewAllRequestsListByStatus=3,
        eFindMaintenanceRequest =4,
        eUpdateRequestStatus = 5,
        eDeleteMaintenanceRequest=6,
        eAssignMaintenanceStaff = 7,
        eGenerateMaintenanceReports = 8,
        eExit = 9
    };

    
    static void _GoBackToMaintenanceMenu()
    {
        cout << "Press any key to go back to Maintenance Menu...";
        system("pause>0");
        ShowMaintenanceMenuScreen();
    }

    static short _ReadManageMaintenanceMenuOption()
    {
        cout << setw(ScreenWidth) << left << "" << "Choose what do you want to do? [1 to 9]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 9, "Enter Number between 1 to 9: ");
        return Choice;
    }

    static void AddMaintenanceRequest()
    {
        clsAddMaintenanceRequestScreen::ShowAddMaintenanceRequestScreen();
    }


    static void ViewAllRequests()
    {
        clsViewAllRequestsScreen::ShowAllMaintenanceRequestsScreen();
    }

    static void MaintenanceListByStatus()
    {

        clsMaintenanceListByStatusScreen::ShowAllMaintRequestsByStatusScreen();
    }

    static void FindMaintenanceRequest()
    {

        clsFindMaintenanceRequestScreen::ShowFindEmployeeScreen();
    }

    static void UpdateRequestStatus()
    {
        clsUpdateRequestStatusScreen::ShowUpdateMainReportScreen();
    }

    static void DeleteMaintenanceRequest()
    {
        clsDeleteMaintenanceRequestScreen::ShowDeleteMaintRequestScreen();
    }

    static void AssignMaintenanceStaff()
    {
        clsAssignStaffScreen::ShowAssignStaffScreen();
    }

    static void GenerateMaintenanceReports()
    {
        clsMaintenanceReportsScreen::ShowPaymentsReportScreen();
    }

    static void _PerformMaintenanceMenuOption(enMaintenanceMenuOptions MaintenanceMenuOption)
    {
        switch (MaintenanceMenuOption)
        {
        case enMaintenanceMenuOptions::eAddMaintenanceRequest:
            system("cls");
            AddMaintenanceRequest();
            _GoBackToMaintenanceMenu();
            break;

        case enMaintenanceMenuOptions::eViewAllRequests:
            system("cls");
            ViewAllRequests();
            _GoBackToMaintenanceMenu();
            break;
        case enMaintenanceMenuOptions::eViewAllRequestsListByStatus:
            system("cls");
            MaintenanceListByStatus();
            _GoBackToMaintenanceMenu();
            break;



        case enMaintenanceMenuOptions::eFindMaintenanceRequest:
            system("cls");
            FindMaintenanceRequest();
            _GoBackToMaintenanceMenu();
            break;

        case enMaintenanceMenuOptions::eUpdateRequestStatus:
            system("cls");
            UpdateRequestStatus();
            _GoBackToMaintenanceMenu();
            break;

        case enMaintenanceMenuOptions::eDeleteMaintenanceRequest:
            system("cls");
            DeleteMaintenanceRequest();
            _GoBackToMaintenanceMenu();
            break;


        case enMaintenanceMenuOptions::eAssignMaintenanceStaff:
            system("cls");
            AssignMaintenanceStaff();
            _GoBackToMaintenanceMenu();
            break;

        case enMaintenanceMenuOptions::eGenerateMaintenanceReports:
            system("cls");
            GenerateMaintenanceReports();
            _GoBackToMaintenanceMenu();
            break;

        case enMaintenanceMenuOptions::eExit:
        default:
            // Just exit
            break;
        }
    }
    

public:

    static void ShowMaintenanceMenuScreen()
    {


        if (!clsBase::_CheckAccessRights(clsLogin::eManageMaintenance))
        {
            return;
        }

        system("cls");
        clsBase::_DrawScreenHeader("\tManage Dorm Maintenance Screen");

        
        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n";
        cout << setw(ScreenWidth) << left << "" << Red << "\tManage Maintenance Menu\n";
        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;

        cout << setw(ScreenWidth) << left << "" << " [1]   Add Maintenance Request.\n";
        cout << setw(ScreenWidth) << left << "" << " [2]   View All Requests.\n";
        cout << setw(ScreenWidth) << left << "" << " [3]   View All Requests By Status.\n";
        cout << setw(ScreenWidth) << left << "" << " [4]   Find Maintenance Request .\n";
        cout << setw(ScreenWidth) << left << "" << " [5]   Update Request Status.\n";
        cout << setw(ScreenWidth) << left << "" << " [6]   Delete Maintenance Staff.\n";
        cout << setw(ScreenWidth) << left << "" << " [7]   Assign Maintenance Staff.\n";
        cout << setw(ScreenWidth) << left << "" << " [8]   Generate Maintenance Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [9]   Exit.\n";

        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;

        _PerformMaintenanceMenuOption((enMaintenanceMenuOptions)_ReadManageMaintenanceMenuOption());
    }
    

};
