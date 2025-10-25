#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"


class clsUpdateRequestStatusScreen : protected clsBase
{

private:


	static void ReadFullRequestInfoToUpdate(clsMaintenance& MainRequest)
	{

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Status: [ ePending = 1, eInProgress = 2, eCompleted = 3, eCancelled = 4 ]:  ";
        MainRequest.Status = (clsMaintenance::enMaintenanceStatus)clsInputValidate::ReadNumberBetween<short>(1, 4);


        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Priority: [ eLow = 1, eMedium = 2, eHigh = 3 ]: ";
        MainRequest.Priority = (clsMaintenance::enPriorityLevel)clsInputValidate::ReadNumberBetween(1, 3); 

        cout<<"\n"<<setw(ScreenWidth) << "" << left << "Enter Assigned Staff ID: ";
        MainRequest.AssignedStaffID = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Issue Description: ";
        MainRequest.IssueDescription = clsInputValidate::ReadString();

        MainRequest.LastUpdateDate = clsDate::GetSystemDateTimeString();


	}


    enum enWhatToUpdate { eStatus = 1, ePriority = 2, eAssignedStaffID = 3, eDescription = 4, eAll = 5 , exit=6 };

    static void _PerformUpdateMenuScreen(enWhatToUpdate WhatToUpdate, clsMaintenance& MaintRequest)
    {

        switch (WhatToUpdate)
        {

        case enWhatToUpdate::eStatus:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Status:as following menu\n"; 
            cout << "\n" << setw(ScreenWidth) << "" << left  << "[ePending = 1, eInProgress = 2, eCompleted = 3, eCancelled = 4 ]: ";
            MaintRequest.Status = (clsMaintenance::enMaintenanceStatus)clsInputValidate::ReadNumberBetween<short>(1, 4);
            break;
        }

        case enWhatToUpdate::ePriority:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Priority as following menu [ eLow = 1, eMedium = 2, eHigh = 3 ] : ";
            MaintRequest.Priority = (clsMaintenance::enPriorityLevel)clsInputValidate::ReadNumberBetween(1, 3);

            break;
        }
        case enWhatToUpdate::eAssignedStaffID:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Assigned Staff ID: ";
            MaintRequest.AssignedStaffID = clsInputValidate::ReadString();
            break;
        }
        case enWhatToUpdate::eDescription:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Issue Description: ";
            MaintRequest.IssueDescription = clsInputValidate::ReadString();
            break;
        }

        case enWhatToUpdate::eAll:
        {
            ReadFullRequestInfoToUpdate(MaintRequest);

            break;
        }
        case enWhatToUpdate::exit:
            return;

        default:
        {
            ReadFullRequestInfoToUpdate(MaintRequest);
            break;
        }


        }
        MaintRequest.LastUpdateDate = clsDate::GetSystemDateTimeString();


    }

    static void _ShowUpdateMenuScreen(clsMaintenance& Request)
    {
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n";
        cout << setw(ScreenWidth) << "" << left << Red <<   "  Update Maintenance Request Menu Screen \n";
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n" << White;
        cout << setw(ScreenWidth) << "" << left << " [1] Status\n";
        cout << setw(ScreenWidth) << "" << left << " [3] Priority\n";
        cout << setw(ScreenWidth) << "" << left << " [4] Assigned Staff ID\n";
        cout << setw(ScreenWidth) << "" << left << " [2] Description\n";
        cout << setw(ScreenWidth) << "" << left << " [5] Update All\n";
        cout << setw(ScreenWidth) << "" << left << " [6] Exit\n";

        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n\n";

        cout << setw(ScreenWidth) << "" << left << Yellow << "What do you want to update (answer as following menu from  1 to 6 ) : " << White;
        _PerformUpdateMenuScreen((enWhatToUpdate)clsInputValidate::ReadNumberBetween<short>(1, 6), Request);
    }


public:

	static void ShowUpdateMainReportScreen()
	{
        system("cls");
		clsBase::_DrawScreenHeader("\tUpdate Maintenance Request Screen");
        if (clsInputValidate::IsSureToPerform())
        {
		    string RequestId = clsGlobalRead::ReadMainRequestDormId();


		    clsMaintenance MainRequest = clsMaintenance::FindMaintenanceRequest(RequestId);

		    clsGlobalPrint::PrintMaintRequest(MainRequest);

            _ShowUpdateMenuScreen(MainRequest);

            clsMaintenance::enSaveResults SaveResult = MainRequest.SaveMaintRequest();

            clsGlobalPrint::PrintResult(SaveResult,MainRequest);


        }



	}


};

