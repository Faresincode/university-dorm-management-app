
#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsSecurity.h"
#include "clsGlobalPrint.h";
#include "clsGlobalRead.h";


class clsFindSecurityScreen : protected clsBase
{

private:





public:

	static void ShowFindSecurityScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\tFind Security Employee Screen");

		if (clsInputValidate::IsSureToPerform())
		{

		string EmployeeId = clsGlobalRead::ReadSecurityEmployeeID();

		clsSecurity SecurityEmployee = clsSecurity::FindSecurityGuard(EmployeeId);

		if (!SecurityEmployee.IsEmpty())
		{
			cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Object Found :-)\n" << White;

			clsGlobalPrint::PrintFullSecurityEmployeeInfo(SecurityEmployee);


		}
		else
		{
			cout << setw(ScreenWidth) << "" << left <<Red<< "!Error! Object Is Empty" << White<<endl;
		}

		}


	}


};

