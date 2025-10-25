#pragma once

#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "Global.h";
#include "clsGlobalPrint.h".
#include "clsFinance.h";

using namespace std; 

class clsShowAllPaymentsScreen : protected clsBase
{


private:







public:

    static void ShowPaymentsListScreen()
    {

        system("cls");
        clsBase::_DrawScreenHeader("\t   Full Payments List Screen");



        if (clsInputValidate::IsSureToPerform())
        {
            system("cls");

            vector <clsFinance> vPayments = clsFinance::GetPaymentsList();

            string Subtitle = "\t\t(" + to_string(vPayments.size()) + ") Employees";
            clsBase::_DrawScreenHeader("\t   Full Payments List Screen", Subtitle);
            clsGlobalPrint::PrintPaymentsTable(vPayments);
        }


    }




};

