#pragma once
#include <iostream>
#include "Global.h";
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsDormStudentsListScreen.h";
#include "clsFindDormStudentScreen.h";
#include "clsUpdateDormStudentScreen.h";
#include "clsDeleteDormStudentScreen.h";
#include "clsAddNewDormStudentScreen.h";
#include "clsTransferDormStudentScreen.h";
#include "clsRecordComplainScreen.h";
#include "clsComplainsStudentsListScreen.h";
#include "clsGenerateReportScreen.h";

using namespace std;



class clsManageDormStudentsScreen :protected clsBase
{



private:

    enum enManageDormMenuOptions
    {
        eShowDormStudentsList=1,eFindDormStudent=2,eUpdateDormStudent=3,eDeleteDormStudents=4,eAddNewDormStudent=5, eTransferStudentInternal=6,
        eRecordComplaint=7,eListComplaints=8, eGenerateReports=9,Exit=10

    };

    static  void _GoBackToMainMenu()
    {
        cout << "Press any key to go back to Main Menu...";
        system("pause>0");
        ShowManageStudentsDormMenu();
    }

    static short _ReadMainMenuOption()
    {
        cout << setw(ScreenWidth) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 10, "Enter Number between 1 to 10? ");
        return  Choice;

    }

    static void DormStudentsList()
    {
       clsDormStudentsListScreen::ShowDormStudentsList();

    }

    static void FindDormStudent()
    {
        clsFindDormStudentScreen::FindDormStudentScreen();
    }

    static void UpdateDormStudent()
    {
        clsUpdateDormStudentScreen::ShowUpdateDormStudent();
    }

    static void DeleteDormStudents()
    {
        clsDeleteDormStudentScreen::ShowDeleteDormStudent();
    }

    static void AddNewDormStudent()
    {
        clsAddNewDormStudentScreen::ShowAddNewUserScreen();
    }

    static void TransferStudentInternal()
    {
        clsTransferDormStudentScreen::ShowInternalTransferDormStudentScreen();
    }

    static void RecordComplaint()
    {
         clsRecordComplainScreen::RecordDormStudentComplaint();
    }

    static void ListComplaints()
    {
        clsComplainsStudentsListScreen::ShowDormStudentComplainsList();
    }

    static void GenerateReports()
    {
        clsGenerateReportScreen::showGenerateReportScreen();
    }

    static void _PerformMainMenuOption(enManageDormMenuOptions ManageDormMenuOptions)
    {
        switch (ManageDormMenuOptions)
        {
        case clsManageDormStudentsScreen::eShowDormStudentsList:
            system("cls");
            DormStudentsList();
            _GoBackToMainMenu();

            break;
        case clsManageDormStudentsScreen::eFindDormStudent:
            system("cls");
            FindDormStudent();
            _GoBackToMainMenu();
            break;
        case clsManageDormStudentsScreen::eUpdateDormStudent:
            system("cls");
            UpdateDormStudent();
            _GoBackToMainMenu();
            break;
        case clsManageDormStudentsScreen::eDeleteDormStudents:
            system("cls");
            DeleteDormStudents();
            _GoBackToMainMenu();
            break;
        case clsManageDormStudentsScreen::eAddNewDormStudent:
            system("cls");
            AddNewDormStudent();
            _GoBackToMainMenu();
            break;
        case clsManageDormStudentsScreen::eTransferStudentInternal:
            system("cls");
            TransferStudentInternal();
            _GoBackToMainMenu();
            break;
        case clsManageDormStudentsScreen::eRecordComplaint:
            system("cls");
            RecordComplaint();
            _GoBackToMainMenu();
            break;
        case clsManageDormStudentsScreen::eListComplaints:
            system("cls");
            ListComplaints();
            _GoBackToMainMenu();
            break;
        case clsManageDormStudentsScreen::eGenerateReports:
            system("cls");
            GenerateReports();
            _GoBackToMainMenu();
            break;
        case clsManageDormStudentsScreen::Exit:
       
        default:
            break;
        }

    }


public:


	static void ShowManageStudentsDormMenu()
	{
        if (!clsBase::_CheckAccessRights(clsLogin::enPermissions::eManageStudent))
        {
            return;
        }

        system("cls");
        clsBase::_DrawScreenHeader("\t Manage Students Dorm Screen");

        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n";
        cout << setw(ScreenWidth) << left << "" << Red << "\tManage Dorm Students Menu\n";
        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;
        cout << setw(ScreenWidth) << left << "" << " [1]   Show Dorm StudentsList.\n";
        cout << setw(ScreenWidth) << left << "" << " [2]   Find Dorm Student.\n";
        cout << setw(ScreenWidth) << left << "" << " [3]   Update Dorm Student.\n";
        cout << setw(ScreenWidth) << left << "" << " [4]   Delete Dorm Students.\n";
        cout << setw(ScreenWidth) << left << "" << " [5]   Add New Dorm Student.\n";
        cout << setw(ScreenWidth) << left << "" << " [6]   Transfer Student Internal.\n";
        cout << setw(ScreenWidth) << left << "" << " [7]   Record Complaint.\n";
        cout << setw(ScreenWidth) << left << "" << " [8]   List Complaints.\n";
        cout << setw(ScreenWidth) << left << "" << " [9]   GenerateReports.\n";
        cout << setw(ScreenWidth) << left << "" << " [10]  Exit.\n";
        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;

        _PerformMainMenuOption((enManageDormMenuOptions)_ReadMainMenuOption());




	}




};

