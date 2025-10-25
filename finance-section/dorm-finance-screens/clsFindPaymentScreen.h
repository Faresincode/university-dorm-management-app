#pragma once

#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "Global.h";
#include "clsGlobalRead.h";
#include "clsGlobalPrint.h";


using namespace std;

class clsFindPaymentScreen : protected clsBase
{


private:




public:

	static void ShowFindPaymentScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\t   Find Room Screen");
		if (clsInputValidate::IsSureToPerform())
		{
			string PaymentID = clsGlobalRead::ReadPaymentId ();
			clsFinance Payment = clsFinance::FindPayment(PaymentID);

			clsGlobalPrint::PrintPayment(Payment);
		
		}





	}



};

