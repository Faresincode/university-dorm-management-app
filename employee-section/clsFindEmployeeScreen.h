#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsEmployee.h";
#include "clsGlobalPrint.h";

using namespace std;

class clsFindEmployeeScreen : protected clsBase
{


private:




public:

	static void ShowFindEmployeeScreen()
	{

		clsBase::_DrawScreenHeader("\t   Find Room Screen");

		if (clsInputValidate::IsSureToPerform())
		{
			string EmployeeId = clsGlobalRead::ReadDormEmployeeId();
   
			clsEmployee Employee = clsEmployee::FindEmployee(EmployeeId);

			if (!Employee.IsEmpty())
			{
				cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Object Found :-)\n" << White;

				clsGlobalPrint::PrintFullDormEmployeeInfo(Employee);

			}
			else
			{
				cout << setw(ScreenWidth) << "" << left << Red << "!Error! Object Is Empty" << White << endl;
			}

		}



	}


};

