#pragma once

#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "Global.h";
#include "clsRecordStudentPaymentScreen.h";
#include "clsUpdatePaymentInfoScreen.h";
#include "clsDeletePaymentRecordScreen.h";
#include "clsShowAllPaymentsScreen.h";
#include "clsFindPaymentScreen.h";
#include "clsGetPaymentsByStudentScreen.h";
#include "clsGenerateFinanceReportsScreen.h";

using namespace std;



class clsManageFinanceMenuScreen :protected clsBase
{



private:

    enum enManageFinanceMenuOptions
    {
        eRecordStudentPayment = 1,
        eUpdatePaymentInfo = 2,
        eDeletePaymentRecord = 3,
        eShowAllPayments = 4,
        eFindPaymentByID = 5,
        eGetPaymentsByStudent = 6,
        eGenerateFinanceReports = 7,
        eExit = 8
    };

    static short _ReadManageFinanceMenuOption()
    {
        cout << setw(ScreenWidth) << left << "" << "Choose an option [1 to 8]: ";
        short Option= clsInputValidate::ReadNumber<short>();
        return Option;
    }


    static  void _GoBackToEmployeeMenu()
    {
        cout << "Press any key to go back to Main Menu...";
        system("pause>0");
        ShowManageFinanceMenu();
    }

    static void RecordStudentPayment()
    {
        clsRecordStudentPaymentScreen::ShowRecordStudentPaymentScreen();
    }
    static void UpdatePaymentInfo()
    {
        clsUpdatePaymentInfoScreen::ShowUpdatePaymentScreen();
    }
    static void DeletePaymentRecord()
    {
        clsDeletePaymentRecordScreen::ShowDeletePaymentScreen();
    }

    static void ShowAllPayments()
    {
        clsShowAllPaymentsScreen::ShowPaymentsListScreen();
    }

    static void FindPaymentByID()
    {
        clsFindPaymentScreen::ShowFindPaymentScreen();
    }

    static void GetPaymentsByStudent()
    {
        clsGetPaymentsByStudentScreen::ShowStudentPaymentsScreen();
    }

    static void GenerateFinanceReports()
    {
        clsGenerateFinanceReportsScreen::ShowPaymentsReportScreen();
    }


    static void _PerformManageFinanceMenuOption(enManageFinanceMenuOptions ManageFinanceMenuOption)
    {
        switch (ManageFinanceMenuOption)
        {
        case enManageFinanceMenuOptions::eRecordStudentPayment:
            system("cls");
            RecordStudentPayment();
            _GoBackToEmployeeMenu();
            break;

        case enManageFinanceMenuOptions::eUpdatePaymentInfo:
            system("cls");
            UpdatePaymentInfo();
            _GoBackToEmployeeMenu();
            break;

        case enManageFinanceMenuOptions::eDeletePaymentRecord:
            system("cls");
            DeletePaymentRecord();
            _GoBackToEmployeeMenu();
            break;

        case enManageFinanceMenuOptions::eShowAllPayments:
            system("cls");
            ShowAllPayments();
            _GoBackToEmployeeMenu();
            break;

        case enManageFinanceMenuOptions::eFindPaymentByID:
            system("cls");
            FindPaymentByID();
            _GoBackToEmployeeMenu();
            break;

        case enManageFinanceMenuOptions::eGetPaymentsByStudent:
            system("cls");
            GetPaymentsByStudent();
            _GoBackToEmployeeMenu();
            break;

        case enManageFinanceMenuOptions::eGenerateFinanceReports:
            system("cls");
            GenerateFinanceReports();
            _GoBackToEmployeeMenu();
            break;

        case enManageFinanceMenuOptions::eExit:
        default:
            break;
        }


    }



public:




    static void ShowManageFinanceMenu()
    {

        if (!clsBase::_CheckAccessRights(clsLogin::eManageFinance))
        {
            return;
        }

        system("cls");
        clsBase::_DrawScreenHeader("\tManage Finance Screen");


        
        cout << setw(ScreenWidth) << left << "" <<Green<< "===========================================\n"<<White;
        cout << setw(ScreenWidth) << left << "" << "\tDorm Finance Management Menu\n";
        cout << setw(ScreenWidth) << left << "" <<Green<< "===========================================\n"<<White;
        cout << setw(ScreenWidth) << left << "" << " [1] Record Student Payment.\n";
        cout << setw(ScreenWidth) << left << "" << " [2] Update Payment Info.\n";
        cout << setw(ScreenWidth) << left << "" << " [3] Delete Payment Record.\n";
        cout << setw(ScreenWidth) << left << "" << " [4] Show All Payments.\n";
        cout << setw(ScreenWidth) << left << "" << " [5] Find Payment by ID.\n";
        cout << setw(ScreenWidth) << left << "" << " [6] Get Payments by Student.\n";
        cout << setw(ScreenWidth) << left << "" << " [7] Generate Finance Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [8] Exit.\n";
        cout << setw(ScreenWidth) << left << "" <<Green<< "===========================================\n"<<White;
        
        _PerformManageFinanceMenuOption((enManageFinanceMenuOptions)_ReadManageFinanceMenuOption());
    }







};

