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



class clsUpdatePaymentInfoScreen : protected clsBase
{



private:



    static void ReadStudentPaymentInfo(clsFinance& StudentPayment)
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "To skip Anything enter -> skip\n" << White;
        string StringInput = "";
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Payment Amount: ";

        if ((StringInput = clsInputValidate::ReadString()) != "skip")
        {
            StudentPayment.Amount = stod(StringInput);
        }
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Description: ";
        if ((StringInput = clsInputValidate::ReadString()) != "skip")
        {
            StudentPayment.Description = StringInput;
        }
        
        cout << "\n" << setw(ScreenWidth) << "" << left << "You want to update payment method answer with Y/N?: ";
        if (clsInputValidate::IsAnswerIsYes())
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Payment Method as following menu: ";
            cout << "\n" << setw(ScreenWidth) << "" << left << "[ eCash = 1, eCard = 2, eBankTransfer = 3 ,NoMethod=0 ] : ";

            StudentPayment.PaymentMethod = (clsFinance::enPaymentMethod) clsInputValidate::ReadNumberBetween<short>(0,3);

        }

        cout << "\n" << setw(ScreenWidth) << "" << left << "You want to update payment Status answer with Y/N?: ";
        if (clsInputValidate::IsAnswerIsYes())
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Status: as following menu \n ";
            cout << "\n" << setw(ScreenWidth) << "" << left << "[ ePending = 1, eCompleted = 2,eFailed = 3,eRefunded = 4,eCancelled = 5, eNoStatus = 0 ] : ";

            StudentPayment.PaymentStatus = (clsFinance::enPaymentStatus) clsInputValidate::ReadNumberBetween<short>(0,5);
      
        }
        StudentPayment.PaymentDateTime = clsDate::GetSystemDateTimeString();

    }

    enum enWhatToUpdate { eAmount = 1, eDescription = 2, ePaymentMethod = 3, ePaymentStatus = 4 , eAll = 5 };

    static void _PerformUpdateMenuScreen(enWhatToUpdate WhatToUpdate, clsFinance& StudentPayment)
    {

        switch (WhatToUpdate)
        {

        case enWhatToUpdate::eAmount:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Payment Amount: ";
            StudentPayment.Amount = clsInputValidate::ReadNumber<double>();
           
            break;
        }

        case enWhatToUpdate::eDescription:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Description: ";

            StudentPayment.Description = clsInputValidate::ReadString();
            
            break;
        }
        case enWhatToUpdate::ePaymentMethod:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Payment Method as following menu: ";
            cout << "\n" << setw(ScreenWidth) << "" << left << "[ eCash = 1, eCard = 2, eBankTransfer = 3 ,NoMethod=0 ] : ";

            StudentPayment.PaymentMethod = (clsFinance::enPaymentMethod)clsInputValidate::ReadNumberBetween<short>(0, 3);
            break;
        }
        case enWhatToUpdate::ePaymentStatus:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Status: as following menu \n ";
            cout << "\n" << setw(ScreenWidth) << "" << left << "[ ePending = 1, eCompleted = 2,eFailed = 3,eRefunded = 4,eCancelled = 5, eNoStatus = 0 ] : ";
            StudentPayment.PaymentStatus = (clsFinance::enPaymentStatus)clsInputValidate::ReadNumberBetween<short>(0, 5);
            break;
        }

        case enWhatToUpdate::eAll:
        {
            ReadStudentPaymentInfo(StudentPayment);

            break;
        }
        default:
        {
            ReadStudentPaymentInfo(StudentPayment);
            break;
        }


        }

    }

    static void _ShowUpdateMenuScreen(clsFinance& Student)
    {
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n";
        cout << setw(ScreenWidth) << "" << left << Red << "     Update Student Payment Menu Screen \n";
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n" << White;
        cout << setw(ScreenWidth) << "" << left << " [1] Payment Amount       \n";
        cout << setw(ScreenWidth) << "" << left << " [2] Payment Description           \n";
        cout << setw(ScreenWidth) << "" << left << " [3] Payment Method       \n";
        cout << setw(ScreenWidth) << "" << left << " [4] Payment Status           \n";
        cout << setw(ScreenWidth) << "" << left << " [5] All Info \n";
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n\n";

        cout << setw(ScreenWidth) << "" << left << Yellow << "What do you want to update (answer as following menu from  1 to 6 ) : " << White;
        _PerformUpdateMenuScreen((enWhatToUpdate)clsInputValidate::ReadNumberBetween<short>(1, 5), Student);
    }


public:

    static void ShowUpdatePaymentScreen()
    {
        system("cls");

        clsBase::_DrawScreenHeader("\t\tUpdate Dorm Student Screen\n");

        if (clsInputValidate::IsSureToPerform())
        {

            string PaymentId = clsGlobalRead::ReadPaymentId();
            clsFinance Payment = clsFinance::FindPayment(PaymentId);
            clsGlobalPrint::PrintPayment(Payment);
            _ShowUpdateMenuScreen(Payment);

            clsFinance::enSaveResults SaveResult = Payment.Save();
            clsGlobalPrint::PrintResult(SaveResult, Payment);     
        
        }





    }


};

