#pragma once
#include <iostream>
#include <vector>
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsMaintenance.h";

using namespace std;


class clsFindMaintenanceRequestScreen : protected clsBase
{

private:



public:


	static void ShowFindEmployeeScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\t   Find Main Request Screen");

		if (clsInputValidate::IsSureToPerform())
		{
			string RequestId = clsGlobalRead::ReadMainRequestDormId();

			clsMaintenance MainRequest = clsMaintenance::FindMaintenanceRequest(RequestId);

			if (!MainRequest.IsEmpty())
			{
				cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Object Found :-)\n" << White;
				clsGlobalPrint::PrintMaintRequest(MainRequest);
			}
			else
			{
				cout << setw(ScreenWidth) << "" << left << Red << "!Error! Object Is Empty" << White << endl;
			}

		}



	}


};

