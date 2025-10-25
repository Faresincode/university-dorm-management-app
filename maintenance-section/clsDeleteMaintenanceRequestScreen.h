#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsMaintenance.h";
#include "clsGlobalRead.h";
#include "clsGlobalPrint.h";


using namespace std;


class clsDeleteMaintenanceRequestScreen : protected clsBase
{



private:


    static void _PrintSpecificMaintRequestRecordLine(clsMaintenance MaintRequest)
    {

        cout << setw(ScreenWidth - 10) << left << "" << Green << "| " << White << setw(15) << left << MaintRequest.RequestID;
        cout << Green << "| " << White << setw(25) << left << MaintRequest.IssueType;
        cout << Green << "| " << White << setw(20) << left <<clsMaintenance::GetStatusString( MaintRequest.Status) << White;


    }

    static void _PrintSpecificMaintRequestHeader()
    {

        cout << "\n" << setw(ScreenWidth - 10) << left << "" << Green << "----------------------------------------------------------------------\n" << White;
        cout << setw(ScreenWidth - 10) << left << "" << Green << "| " << Yellow << setw(15) << left << "Request ID";
        cout << Green << "| " << Yellow << setw(25) << left << "Issue Type" << White;
        cout << Green << "| " << Yellow << setw(20) << left << "Status" << White;
        cout << "\n" << setw(ScreenWidth - 10) << left << "" << Green << "----------------------------------------------------------------------\n" << White;
    }


    static void _PrintSmallEmployeeListInfo()
    {
        vector<clsMaintenance>vMaintRequests = clsMaintenance::GetMaintenanceRequestsList();

        if (vMaintRequests.size() == 0)
        {
            cout << setw(ScreenWidth) << "" << left << Red << "No Maint Request Available In the System!\n" << White;
        }
        else
        {
            _PrintSpecificMaintRequestHeader();
            for (clsMaintenance& student : vMaintRequests)
            {
                _PrintSpecificMaintRequestRecordLine(student);
                cout << endl;
            }
            cout << setw(ScreenWidth - 10) << left << "" << Green << "----------------------------------------------------------------------" << White << endl;
        }
    }




public:

    static void ShowDeleteMaintRequestScreen()
    {

        system("cls");
        clsBase::_DrawScreenHeader("\tDelete Maintenance Request Screen\n");
        if (clsInputValidate::IsSureToPerform())
        {
            _PrintSmallEmployeeListInfo();

            string MaintRequestId = clsGlobalRead::ReadMainRequestDormId();

            clsMaintenance MaintRequestToDelete = clsMaintenance::FindMaintenanceRequest(MaintRequestId);
            clsGlobalPrint::PrintMaintRequest(MaintRequestToDelete);

            cout << "\n" << setw(ScreenWidth) << "" << left << "Are you sure you want to delete this Maintenance Request Definitely answer [Y/N]: ";
            if (clsInputValidate::IsAnswerIsYes())
            {
                if (MaintRequestToDelete.DeleteMaintRequest())
                {
                    cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Request Deleted Successfully :-)\n" << White;
                }
                else
                {
                    cout << Red << "\n" << setw(ScreenWidth) << "" << left << "\nError Request Was not Deleted\n" << White << endl;
                }

            }

        }


    }



};

