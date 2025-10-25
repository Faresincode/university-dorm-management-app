#pragma once
#include <iostream>
#include <iomanip>
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsIncidentReport.h"
#include "clsFindIncidentScreen.h"
#include "clsIncidentListScreen.h"
#include "clsUpdateIncidentScreen.h"
#include "clsDeleteIncidentScreen.h"
#include "clsFilterIncidentScreen.h"
#include "clsAddNewIncidentScreen.h";

using namespace std;

class clsManageIncidentMenuScreen : protected clsBase
{
private:

    enum enIncidentReportMenuOptions
    {
        eAddNewIncident = 1,
        eShowAllIncidents = 2,
        eSearchIncident = 3,
        eUpdateIncident = 4,
        eDeleteIncident = 5,
        eFilterIncidents = 6,
        eExit = 7,
    };

    static void _GoBackToIncidentMenu()
    {
        cout << "\n" << setw(ScreenWidth) << left << "" << "Press any key to go back to Incident Reports Menu...";
        system("pause>0");
        ShowIncidentReportMenuScreen();
    }

    static short _ReadIncidentMenuOption()
    {
        cout << setw(ScreenWidth) << left << "" << "Choose what do you want to do? [1 to 7]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 7, "Enter a number between 1 and 7: ");
        return Choice;
    }

    static void AddNewIncident()
    {
        clsAddNewIncidentScreen::ShowAddIncidentScreen();
    }

    static void ShowAllIncidents()
    {
        clsIncidentListScreen::ShowIncidentListScreen();
    }

    static void SearchIncident()
    {
        clsFindIncidentScreen::ShowFindIncidentScreen();
    }

    static void UpdateIncident()
    {
        clsUpdateIncidentScreen::ShowUpdateIncidentInfoScreen();
    }

    static void DeleteIncident()
    {
        clsDeleteIncidentScreen::ShowDeleteIncidentScreen();
    }

    static void FilterIncidents()
    {
        clsFilterIncidentScreen::ShowFilterIncidentScreen();
    }

    static void _PerformIncidentMenuOption(enIncidentReportMenuOptions IncidentMenuOption)
    {
        switch (IncidentMenuOption)
        {
        case enIncidentReportMenuOptions::eAddNewIncident:
            system("cls");
            AddNewIncident();
            _GoBackToIncidentMenu();
            break;

        case enIncidentReportMenuOptions::eShowAllIncidents:
            system("cls");
            ShowAllIncidents();
            _GoBackToIncidentMenu();
            break;

        case enIncidentReportMenuOptions::eSearchIncident:
            system("cls");
            SearchIncident();
            _GoBackToIncidentMenu();
            break;

        case enIncidentReportMenuOptions::eUpdateIncident:
            system("cls");
            UpdateIncident();
            _GoBackToIncidentMenu();
            break;

        case enIncidentReportMenuOptions::eDeleteIncident:
            system("cls");
            DeleteIncident();
            _GoBackToIncidentMenu();
            break;

        case enIncidentReportMenuOptions::eFilterIncidents:
            system("cls");
            FilterIncidents();
            _GoBackToIncidentMenu();
            break;

        case enIncidentReportMenuOptions::eExit:
            return;
        default:
            // Just return to main menu
            break;
        }
    }

public:

    static void ShowIncidentReportMenuScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\tIncident Report Management Screen");

        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n";
        cout << setw(ScreenWidth) << left << "" << Red << "\tIncident Reports Menu\n";
        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;

        cout << setw(ScreenWidth) << left << "" << " [1]   Add New Incident Report.\n";
        cout << setw(ScreenWidth) << left << "" << " [2]   Show All Incident Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [3]   Search for an Incident.\n";
        cout << setw(ScreenWidth) << left << "" << " [4]   Update Incident Information.\n";
        cout << setw(ScreenWidth) << left << "" << " [5]   Delete an Incident.\n";
        cout << setw(ScreenWidth) << left << "" << " [6]   Filter Incidents.\n";
        cout << setw(ScreenWidth) << left << "" << " [7]   Exit\n";

        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;

        _PerformIncidentMenuOption((enIncidentReportMenuOptions)_ReadIncidentMenuOption());
    }

};
