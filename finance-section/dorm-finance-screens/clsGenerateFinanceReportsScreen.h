#pragma once

#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "Global.h";
#include "clsFinance.h";


using namespace std;


class clsGenerateFinanceReportsScreen : protected clsBase
{


private:


	static void PrintPaymentReportRecordLine(clsFinance Payment)
	{

		cout << setw(21) << left << "" << Green << "| " << White << setw(20) << left << Payment.StudentDormID;
		cout << Green << "| " << White << setw(20) << left << clsFinance::CountPaymentsMade (Payment.StudentDormID);
		cout << Green << "| " << White << setw(25) << left << clsFinance::CountTotalAmountPaid(Payment.StudentDormID);
		cout << Green << "| " << White << setw(35) << left << clsFinance::LastPaymentDateTime (Payment.StudentDormID);



	}

	static void PrintPaymentsReportTableHeader()
	{

		cout << "\n" << setw(20) << left << "" << Green << "____________________________________________________________________________________________________\n\n" << White;


		cout << setw(21) << left << "" << Green << "| " << White << setw(20) << left << "Student Dorm ID";
		cout << Green << "| " << White << setw(20) << left << "Total Payments made";
		cout << Green << "| " << White << setw(25) << left << "Total amount paid";
		cout << Green << "| " << White << setw(35) << left << "Last Payment Date Time";

		cout << "\n" << setw(20) << left << "" << Green << "____________________________________________________________________________________________________\n\n" << White;

	}

	static void PrintPaymentsReportTable(vector <clsFinance> vPayments)
	{

		PrintPaymentsReportTableHeader();
		for (clsFinance& Pay : vPayments)
		{
			PrintPaymentReportRecordLine(Pay);
			cout << endl;
		}

		cout << setw(20) << left << "" << Green << "____________________________________________________________________________________________________" << White << endl;


	}


	static void PrintReport(vector<clsFinance>VPayments)
	{

		short ScreenToMove = 2;	
		double TotalPayment = VPayments.size();
		double* PaymentsCounter = new double;

		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "          Payments Status Summary Report" << Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;

		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Total Payment                : " << TotalPayment;

		*PaymentsCounter = clsFinance::CountPaymentsSByStatus(clsFinance::enPaymentStatus::eCompleted);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Completed Payment            : ";
		cout<< *PaymentsCounter<<" - "<<(*PaymentsCounter/TotalPayment)*100<<" % ";

		*PaymentsCounter = clsFinance::CountPaymentsSByStatus(clsFinance::enPaymentStatus::eCancelled);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Cancelled Payment            : "; 
		cout<< *PaymentsCounter << " - " << (*PaymentsCounter / TotalPayment)*100<<" % ";

		*PaymentsCounter = clsFinance::CountPaymentsSByStatus(clsFinance::enPaymentStatus::ePending);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Pending Payment              : ";
		cout << *PaymentsCounter << " - " << (*PaymentsCounter / TotalPayment)*100 << " % ";

		*PaymentsCounter = clsFinance::CountPaymentsSByStatus(clsFinance::enPaymentStatus::eRefunded);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Refunded Payment             : ";
		cout << *PaymentsCounter << " - " << (*PaymentsCounter / TotalPayment)*100 << " % ";

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;

		//-----------------------------------------------------------------------------------------------------------------------

		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "          Payments by Method Report" << Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;


		*PaymentsCounter = clsFinance::CountPaymentsByMethod(clsFinance::enPaymentMethod::eCash);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Payment By Cash              : " ;
		cout << *PaymentsCounter << " - " << (*PaymentsCounter / TotalPayment)*100 << " % ";

		*PaymentsCounter = clsFinance::CountPaymentsByMethod(clsFinance::enPaymentMethod::eCard);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Payment By Card              : ";
		cout << *PaymentsCounter << " - " << (*PaymentsCounter / TotalPayment) *100<< " % ";

		*PaymentsCounter = clsFinance::CountPaymentsByMethod(clsFinance::enPaymentMethod::eBankTransfer);
		cout << "\n" << setw(ScreenWidth + ScreenToMove) << "" << left << "Payment By BankTransfer      : ";
		cout << *PaymentsCounter << " - " << (*PaymentsCounter / TotalPayment)*100 << " % ";

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;

		//-----------------------------------------------------------------------------------------------------------------------
		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "       Payments Report Table" << Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" <<endl<< White;

		PrintPaymentsReportTable(VPayments);

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;



		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue <<    "       Payments Monthly Report Table" << Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green <<   "----------------------------------------------" << endl << White;

		vector<clsFinance::stPaymentDate> vDuplicatedDatetime= clsFinance::GetFiltredPaymentsDateTimeList();
		for (clsFinance::stPaymentDate &DT : vDuplicatedDatetime)
		{
			clsFinance::stPaymentDateCount vDateCounter= clsFinance::CountPaymentsByMonthAndYear(DT.Month, DT.Year);
			cout << "\n" << setw(ScreenWidth+5) << "" << left << clsDate::GetMonthString(vDateCounter.Month)<<" " << vDateCounter.Year << " -> $" << vDateCounter.TotalPaymentAmount<<" ("<< vDateCounter.PaymentCounter<<" Payments)\n";
			

		}
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;

		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "            Payments Report info" << Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << endl << White;

		clsFinance::stPaymentDateCount ValidPayments = clsFinance::TotalValidPaymentsInfo();
		cout << "\n" << setw(ScreenWidth) << "" << left << "Total Valid Payments          : "<< ValidPayments.PaymentCounter;
		cout << "\n" << setw(ScreenWidth) << "" << left << "Total Amount Collected        : "<< ValidPayments.TotalPaymentAmount;
		cout << "\n" << setw(ScreenWidth) << "" << left << "Average Payment Amount        : " <<( ValidPayments.TotalPaymentAmount/ValidPayments.PaymentCounter );



		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;
		delete PaymentsCounter;
	}


public:

	static void ShowPaymentsReportScreen()
	{
		system("cls");

		clsBase::_DrawScreenHeader("\t\tPayments Report Screen");
		if (clsInputValidate::IsSureToPerform())
		{

	
			vector<clsFinance>vPayments = clsFinance::GetPaymentsList();

			PrintReport(vPayments);	
		}




	}


};

