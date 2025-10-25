#pragma once
#include <iostream>
#include <vector>
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsSecurity.h";
#include "clsGlobalRead.h";
#include "clsGlobalPrint.h";

using namespace std;


class clsDeleteSecurityScreen : protected clsBase
{


private:



public:

	static void ShowDeleteSecurityScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\tFind Security Employee Screen");
		if (clsInputValidate::IsSureToPerform())
		{

			string EmployeeId = clsGlobalRead::ReadSecurityEmployeeID();


			clsSecurity SecurityEmployee = clsSecurity::FindSecurityGuard(EmployeeId);

			clsGlobalPrint::PrintFullSecurityEmployeeInfo(SecurityEmployee);

			cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Are you sure you want to delete this security employee Y/N? " << White;
			if (clsInputValidate::IsAnswerIsYes())
			{

				if (SecurityEmployee.DeleteSecurity())
				{
					cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Security Employee Deleted Successfully"<<White;

				}
				else
				{
					cout << "\n" << setw(ScreenWidth) << "" << left << Red<< " ! Error! Security Employee Was Not Deleted" << White;

				}
			}

		}





	}




};

