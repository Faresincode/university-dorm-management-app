#pragma once
#include <iostream>
#include <vector>
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";

using namespace std;



class clsAssignStaffScreen: protected clsBase
{


private:

	static void PrintMainRequestRecordLine(clsMaintenance Request)
	{

		cout << setw(2) << left << "" << Green << "| " << White << setw(12) << left << Request.RequestID;
		cout << Green << "| " << White << setw(15) << left << Request.DormBuilding;
		cout << Green << "| " << White << setw(15) << left << Request.RoomNumber;
		cout << Green << "| " << White << setw(20) << left << Request.IssueType;
		cout << Green << "| " << White << setw(15) << left << clsMaintenance::GetStatusString(Request.Status);
		cout << Green << "| " << White << setw(20) << left << Request.AssignedStaffID;



	}

	static void PrintMainRequestHeader()
	{

		cout << "\n" << setw(1) << left << "" << Green << "________________________________________________________________________________________________________________________________________________\n\n" << White;



		cout << setw(2) << left << "" << Green << "| " << White << setw(12) << left << "Request ID";
		cout << Green << "| " << White << setw(15) << left << "Dorm Building";
		cout << Green << "| " << White << setw(15) << left << "Room Number";
		cout << Green << "| " << White << setw(20) << left << "Issue Type";
		cout << Green << "| " << White << setw(15) << left << "Status";
		cout << Green << "| " << White << setw(20) << left << "Assigned Staff ID";
		cout << "\n" << setw(1) << left << "" << Green << "________________________________________________________________________________________________________________________________________________\n\n" << White;

	}

	static void PrintSmallMaintRequestsTable(vector <clsMaintenance> vMainRequests)
	{

		PrintMainRequestHeader();
		for (clsMaintenance& Request : vMainRequests)
		{
			PrintMainRequestRecordLine(Request);
			cout << endl;
		}

		cout << setw(1) << left << "" << Green << "________________________________________________________________________________________________________________________________________________" << White << endl;


		
	}

	static string ReadMainRequestIDByStatus(clsMaintenance::enMaintenanceStatus MaintRequestStatus)
	{

		cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Maintenance Request ID: ";
		string MainRequest = clsInputValidate::ReadString();

		while (!clsMaintenance::IsMaintRequestExistByStatus(MainRequest, MaintRequestStatus))
		{
			cout << Yellow << "\n" << setw(ScreenWidth) << "" << left << "Request is not found, choose another one:  " << White;
			MainRequest = clsInputValidate::ReadString();
		}
		return MainRequest;

	}

	static string ReadStuffId()
	{

		cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Stuff Id : ";
		string StuffId = clsInputValidate::ReadString();
		while (!clsMaintenance::IsRequestExistByStuffId(StuffId))
		{
			cout << Yellow << "\n" << setw(ScreenWidth) << "" << left << "Request is not found, choose another one:  " << White;
			StuffId = clsInputValidate::ReadString();
		}
		return StuffId;


	}

public:


	static void ShowAssignStaffScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\t\tAssign Maintenance Staff");

		if (clsInputValidate::IsSureToPerform())
		{

			vector <clsMaintenance> vMainRequests = clsMaintenance::GetMaintRequestsListByStatus(clsMaintenance::enMaintenanceStatus::ePending);
			cout <<"\n" << setw(ScreenWidth) << left << "" << Green << clsMaintenance::GetStatusString(clsMaintenance::enMaintenanceStatus::ePending)<<"Maintenance requests\n";


			PrintSmallMaintRequestsTable(vMainRequests);

			string RequestId = ReadMainRequestIDByStatus(clsMaintenance::enMaintenanceStatus::ePending);

			clsMaintenance MaintenanceRequest = clsMaintenance::FindMaintenanceRequest(RequestId);

			clsGlobalPrint::PrintMaintRequest(MaintenanceRequest);

	
			MaintenanceRequest.AssignedStaffID = ReadStuffId();

			MaintenanceRequest.Status = clsMaintenance::enMaintenanceStatus::eInProgress;

			MaintenanceRequest.LastUpdateDate = clsDate::GetSystemDateTimeString();

			clsMaintenance::enSaveResults SaveResult = MaintenanceRequest.SaveMaintRequest();

			clsGlobalPrint::PrintResult(SaveResult,MaintenanceRequest);

		}



	}



};

