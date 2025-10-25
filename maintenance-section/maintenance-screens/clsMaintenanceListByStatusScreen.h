#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsEmployee.h";
#include "clsGlobalPrint.h";
#include "clsGlobalRead.h";
#include "clsMaintenance.h";
#include "clsViewAllRequestsScreen.h";

using namespace std;

class clsMaintenanceListByStatusScreen : protected clsBase
{



private:

    static void PrintMaintRequestsTable(vector <clsMaintenance> vMainRequests)
    {

        clsViewAllRequestsScreen::PrintMainRequestHeader();
        for (clsMaintenance& Request : vMainRequests)
        {
            clsViewAllRequestsScreen::PrintMainRequestRecordLine(Request);
            cout << endl;
        }

        cout << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________" << White << endl;


    }


public:


    static void ShowAllMaintRequestsByStatusScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\tMaintenance Requests List By Status");

        if (clsInputValidate::IsSureToPerform())

        {

            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Status: as following menu : \n";
            cout << "\n" << setw(ScreenWidth) << "" << left << "[ ePending = 1, eInProgress = 2, eCompleted = 3, eCancelled = 4 ]:  ";
            clsMaintenance::enMaintenanceStatus Status = (clsMaintenance::enMaintenanceStatus) clsInputValidate::ReadNumberBetween<short>(1,4);
            system("cls");

            vector <clsMaintenance> vMainRequests = clsMaintenance::GetMaintRequestsListByStatus(Status);
            string Subtitle = "\t\t(" + to_string(vMainRequests.size()) + ") Employees";
            string Title = "\t" + clsMaintenance::GetStatusString(Status) + "Maintenance Requests List";
            clsBase::_DrawScreenHeader(Title, Subtitle);

            PrintMaintRequestsTable(vMainRequests);
        }






    }


};

