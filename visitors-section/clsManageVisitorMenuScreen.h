#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsVisitor.h"
#include "clsAddVisitorScreen.h"
#include "clsFindVisitorScreen.h"
#include "clsMarkVisitorExitScreen.h"
#include "clsDeleteVisitorScreen.h"
#include "clsVisitorLogListScreen.h"
#include "clsFilterVisitorLogsScreen.h";

using namespace std;

class clsManageVisitorMenuScreen : protected clsBase
{
private:

    enum enVisitorMenuOptions
    {
        eShowVisitorLogs = 1,
        eFindVisitor = 2,
        eAddNewVisitor = 3,
        eMarkVisitorExit = 4,
        eDeleteVisitorLog = 5,
        eFilterVisitorLogs = 6,
        eExit = 7
    };


    static void _GoBackToVisitorMenu()
    {
        cout << "\n" << setw(ScreenWidth) << left << "" << Yellow << "Press any key to go back to Visitor Menu..." << White;
        system("pause>0");
        ShowVisitorMenuScreen();
    }

    static short _ReadVisitorMenuOption()
    {
        cout << "\n" << setw(ScreenWidth) << left << "" << "Choose what do you want to do? [1 to 7]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 7, "Enter Number between 1 to 7: ");
        return Choice;
    }


    static void ShowVisitorLogs()
    {
        clsVisitorLogListScreen::ShowVisitorLogScreen();
    }

    static void FindVisitor()
    {
        clsFindVisitorScreen::ShowFindVisitorScreen();
    }

    static void AddNewVisitor()
    {
        clsAddVisitorScreen::ShowAddVisitorScreen();
    }

    static void MarkVisitorExit()
    {
        clsMarkVisitorExitScreen::MarkVisitorExitScreen();
    }

    static void DeleteVisitorLog()
    {
        clsDeleteVisitorScreen::ShowDeleteVisitorScreen();
    }

    static void FilterVisitorLogs()
    {
        clsFilterVisitorLogsScreen::ShowFilterVisitorLogsScreen();

    }


    static void _PerformVisitorMenuOption(enVisitorMenuOptions VisitorMenuOption)
    {
        switch (VisitorMenuOption)
        {
        case enVisitorMenuOptions::eShowVisitorLogs:
            system("cls");
            ShowVisitorLogs();
            _GoBackToVisitorMenu();
            break;

        case enVisitorMenuOptions::eFindVisitor:
            system("cls");
            FindVisitor();
            _GoBackToVisitorMenu();
            break;

        case enVisitorMenuOptions::eAddNewVisitor:
            system("cls");
            AddNewVisitor();
            _GoBackToVisitorMenu();
            break;

        case enVisitorMenuOptions::eMarkVisitorExit:
            system("cls");
            MarkVisitorExit();
            _GoBackToVisitorMenu();
            break;

        case enVisitorMenuOptions::eDeleteVisitorLog:
            system("cls");
            DeleteVisitorLog();
            _GoBackToVisitorMenu();
            break;

        case enVisitorMenuOptions::eFilterVisitorLogs:
            system("cls");
            FilterVisitorLogs();
            _GoBackToVisitorMenu();
            break;

        case enVisitorMenuOptions::eExit:
        default:
            break;
        }
    }


public:

    static void ShowVisitorMenuScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\tManage Visitor Logs Screen");

        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n";
        cout << setw(ScreenWidth) << left << "" << Red << "\tManage Visitor Menu\n";
        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;

        cout << setw(ScreenWidth) << left << "" << " [1]  Show All Visitor Logs.\n";
        cout << setw(ScreenWidth) << left << "" << " [2]  Find Visitor Log.\n";
        cout << setw(ScreenWidth) << left << "" << " [3]  Add New Visitor Entry.\n";
        cout << setw(ScreenWidth) << left << "" << " [4]  Mark Visitor Exit.\n";
        cout << setw(ScreenWidth) << left << "" << " [5]  Delete Visitor Log.\n";
        cout << setw(ScreenWidth) << left << "" << " [6]  Filter Visitor Logs.\n";
        cout << setw(ScreenWidth) << left << "" << " [7]  Exit.\n";

        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;

        _PerformVisitorMenuOption((enVisitorMenuOptions)_ReadVisitorMenuOption());
    }

};
