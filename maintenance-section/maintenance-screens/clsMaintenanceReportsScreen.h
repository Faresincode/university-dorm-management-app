#pragma once
#include <iostream>
#include <vector>
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";

using namespace std;



class clsMaintenanceReportsScreen : protected clsBase
{

private:







	static void PrintReport(vector<clsMaintenance>VPayments)
	{

		short ScreenToMove = 2;
		double TotalPayment = VPayments.size();
		double* MyCounter = new double;

		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "    Maintenance Requests Status Summary Report" << Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;

		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Total Requests     : " << TotalPayment;

		*MyCounter = clsMaintenance::CountRequestsByStatus(clsMaintenance::enMaintenanceStatus::eCompleted);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Completed          : ";
		cout << *MyCounter << " - " << (*MyCounter / TotalPayment) * 100 << " % ";

		*MyCounter = clsMaintenance::CountRequestsByStatus(clsMaintenance::enMaintenanceStatus::ePending);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Pending            : ";
		cout << *MyCounter << " - " << (*MyCounter / TotalPayment) * 100 << " % ";

		*MyCounter = clsMaintenance::CountRequestsByStatus(clsMaintenance::enMaintenanceStatus::eInProgress);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "InProgress         : ";
		cout << *MyCounter << " - " << (*MyCounter / TotalPayment) * 100 << " % ";

		*MyCounter = clsMaintenance::CountRequestsByStatus(clsMaintenance::enMaintenanceStatus::eCancelled);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Cancelled          : ";
		cout << *MyCounter << " - " << (*MyCounter / TotalPayment) * 100 << " % ";

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;

		//-----------------------------------------------------------------------------------------------------------------------

		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "          Priority Report" << Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;


		*MyCounter = clsMaintenance::CountRequestsByPriority(clsMaintenance::enPriorityLevel::eHigh);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "High Priority    : ";
		cout << *MyCounter << " - " << (*MyCounter / TotalPayment) * 100 << " % ";

		*MyCounter = clsMaintenance::CountRequestsByPriority(clsMaintenance::enPriorityLevel::eMedium);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Medium Priority  : ";
		cout << *MyCounter << " - " << (*MyCounter / TotalPayment) * 100 << " % ";

		*MyCounter = clsMaintenance::CountRequestsByPriority(clsMaintenance::enPriorityLevel::eLow);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Low Priority     : ";
		cout << *MyCounter << " - " << (*MyCounter / TotalPayment) * 100 << " % ";

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;

		//-----------------------------------------------------------------------------------------------------------------------
		delete MyCounter;



	}


public:

	static void ShowPaymentsReportScreen()
	{
		system("cls");

		clsBase::_DrawScreenHeader("\t\tEmployee Report Screen");

		if (clsInputValidate::IsSureToPerform())
		{
			vector<clsMaintenance>vRequests = clsMaintenance::GetMaintenanceRequestsList();

			PrintReport(vRequests);

		}





	}





};

