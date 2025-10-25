#pragma once

#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "Global.h";
#include "clsFinance.h";
#include "clsGlobalPrint.h";
#include "clsGlobalRead.h";


using namespace std;


class clsRecordStudentPaymentScreen : protected clsBase
{
private:





    static double _ReadPaymentAmount()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left  << "Enter Payment Amount : ";
        return clsInputValidate::ReadNumber<double>();
    }

    static clsFinance::enPaymentMethod _ReadPaymentMethod()
    {
      
        cout << "\n" << setw(ScreenWidth) << "" << left  << " Enter Payment Method as Following Menu [ eCash = 1, eCard = 2, eBankTransfer = 3 ]: ";
        return (clsFinance::enPaymentMethod)clsInputValidate::ReadNumberBetween<double>(1,3);
    }




public:

    static void ShowRecordStudentPaymentScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\tRecord Student Payment Screen");

        if (clsInputValidate::IsSureToPerform())
        {

            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Student Dorm Id: ";
            string StudentDormId =  clsGlobalRead::ReadStudentPaymentId();


            clsFinance StudentPayment = clsFinance::FindPayment(StudentDormId);


            StudentPayment.Amount = _ReadPaymentAmount();
            StudentPayment.PaymentMethod = _ReadPaymentMethod();

       
            cout << "\n" << setw(ScreenWidth) << "" << left  << "Are you sure You want to perform this operation  : ";
            if (clsInputValidate::IsAnswerIsYes())
            {
                StudentPayment.PaymentStatus = clsFinance::enPaymentStatus::eCompleted;
            }
            else
            {
                StudentPayment.PaymentStatus = clsFinance::enPaymentStatus::eCancelled;
            }
        
            clsFinance::enSaveResults saveResult = StudentPayment.Save();
            clsGlobalPrint::PrintResult(saveResult, StudentPayment);
  
        
        }


        





    }








};

