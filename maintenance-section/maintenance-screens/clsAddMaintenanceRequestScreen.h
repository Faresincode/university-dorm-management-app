#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsMaintenance.h";
#include "clsGlobalRead.h";
#include "clsGlobalPrint.h";


class clsAddMaintenanceRequestScreen : protected clsBase
{



private:


	static clsMaintenance ReadMaintenanceRequestInfo()
	{

        clsMaintenance Request= clsMaintenance::GetAddNewMaintenanceObject();

        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "Read Maintenance Request Info: \n\n" << White;

        Request.RequestID = clsUtil::GenerateID("DMR");
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Dorm Building: ";
        Request.DormBuilding = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Room Number: ";
        Request.RoomNumber = clsInputValidate::ReadNumber<short>();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Reported By: ";
        Request.ReportedBy = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Issue Type: ";
        Request.IssueType = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Issue Description: ";
        Request.IssueDescription = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Priority as following menu [ eLow = 1, eMedium = 2, eHigh = 3 ] : ";
        Request.Priority =  (clsMaintenance::enPriorityLevel) clsInputValidate::ReadNumberBetween(1,3);


        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Status:as following menu\n";
        cout << "\n" << setw(ScreenWidth) << "" << left << "[ ePending = 1, eInProgress = 2, eCompleted = 3, eCancelled = 4 ]: ";
        Request.Status = (clsMaintenance::enMaintenanceStatus) clsInputValidate::ReadNumberBetween<short>(1,4);

        Request.LastUpdateDate = clsDate::GetSystemDateTimeString();
        Request.RequestDate = Request.LastUpdateDate;
         

        return Request;
	}



public:


    static void ShowAddMaintenanceRequestScreen()
    {

        system("cls");
        clsBase::_DrawScreenHeader("\t\tAdd New Dorm Employee Screen");

        if (clsInputValidate::IsSureToPerform())
        {

            clsMaintenance NewMaintenanceRequest = ReadMaintenanceRequestInfo();

            clsMaintenance::enSaveResults SaveResult = NewMaintenanceRequest.SaveMaintRequest();

            clsGlobalPrint::PrintResult(SaveResult, NewMaintenanceRequest);
        }


    }





};

