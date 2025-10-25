#pragma once

#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "Global.h";
#include "clsFinance.h";
#include "clsGlobalRead.h";


using namespace std;


class clsGetPaymentsByStudentScreen : protected clsBase
{


private:



public:

	static void ShowStudentPaymentsScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\t    Student Payments Screen");

		if (clsInputValidate::IsSureToPerform())
		{

			string StudentDormId =clsGlobalRead::ReadStudentDormId();

			vector<clsFinance> vPayments = clsFinance::GetPaymentsByStudent(StudentDormId);
			if (vPayments.size() == 0)
			{
				cout << "\n" << setw(ScreenWidth) << "" << left <<Red<< "! This student has no history payment" << White << endl;

			}
			else
			{
				system("cls");
				string Subtitle = "\t\t(" + to_string(vPayments.size()) + ") Payments";
				clsBase::_DrawScreenHeader("\t\tStudent Payments Screen", Subtitle);
				clsGlobalPrint::PrintPaymentsTable(vPayments);
			}
		}









	}


};

