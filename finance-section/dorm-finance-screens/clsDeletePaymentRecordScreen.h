#pragma once

#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "Global.h";
#include "clsFinance.h";
#include "clsGlobalRead.h";
#include "clsGlobalPrint.h";


using namespace std;


class clsDeletePaymentRecordScreen : protected clsBase
{



private:

    static void _PrintSpecificEmployeeRecordLine(clsFinance Payment)
    {

        cout << setw(ScreenWidth - 30) << left << "" << Green << "| " << White << setw(20) << left << Payment.PaymentID;
        cout << Green << "| " << White << setw(20) << left << Payment.StudentDormID;
        cout << Green << "| " << White << setw(20) << left << Payment.Amount;
        cout << Green << "| " << White << setw(20) << left << clsFinance::PaymentMethodString (Payment.PaymentMethod) ;
        cout << Green << "| " << White << setw(20) << left << clsFinance::PaymentStatusString(Payment.PaymentStatus) ;




    }

    static void _PrintSpecificEmployeeHeader()
    {

        cout << "\n" << setw(ScreenWidth - 31) << left << "" << Green << "----------------------------------------------------------------------------------------------------------\n" << White;
        cout << setw(ScreenWidth - 30) << left << "" << Green << "| " << White << setw(20) << left << "Payment ID";
        cout << Green << "| " << White << setw(20) << left << "Student Dorm ID";
        cout << Green << "| " << White << setw(20) << left << "Amount";
        cout << Green << "| " << White << setw(20) << left << "Payment Method";
        cout << Green << "| " << White << setw(20) << left << "Payment Status";
        cout << "\n" << setw(ScreenWidth - 31) << left << "" << Green << "----------------------------------------------------------------------------------------------------------\n" << White;
    }


    static void _PrintSmallPaymentListInfo()
    {
        vector<clsFinance>vPayments = clsFinance::GetPaymentsList();

        if (vPayments.size() == 0)
        {
            cout << setw(ScreenWidth) << "" << left << Red << "No Payment Available In the System!\n" << White;
        }
        else
        {
            _PrintSpecificEmployeeHeader();
            for (clsFinance& payment : vPayments)
            {
                _PrintSpecificEmployeeRecordLine(payment);
                cout << endl;
            }
            cout << setw(ScreenWidth - 31) << left << "" << Green << "----------------------------------------------------------------------------------------------------------" << White << endl;
        }
    }







public:

    static void ShowDeletePaymentScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t\tDelete Payment Screen\n");
        if (clsInputValidate::IsSureToPerform())
        {
      
            _PrintSmallPaymentListInfo();

            string PaymentId = clsGlobalRead::ReadPaymentId();

            clsFinance PaymentToDelete = clsFinance::FindPayment(PaymentId);
            clsGlobalPrint::PrintPayment(PaymentToDelete);

            cout << "\n" << setw(ScreenWidth) << "" << left << "Are you sure you want to delete this payment Definitely answer [Y/N]: ";
            if (clsInputValidate::IsAnswerIsYes())
            {
                if (PaymentToDelete.DeletePayment())
                {
                    cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Payment Deleted Successfully :-)\n" << White;
                }
                else
                {
                    cout << Red << "\n" << setw(ScreenWidth) << "" << left << "\nError Payment Was not Deleted\n" << White << endl;
                }

            }  
        
        }


    }



};

