#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsEmployee.h";


using namespace std;



class clsEmployeeReportsScreen : protected clsBase
{


private:

	static void PrintReport(vector<clsEmployee>vEmployees)
	{

		short ScreenToMove = 2;
		double CountActiveEmployee = clsEmployee::CountEmployeeAsStatus(clsEmployee::eActive);
		double CountSuspendedEmployee = clsEmployee::CountEmployeeAsStatus(clsEmployee::eSuspended);
		int TotalEmployee= vEmployees.size();


		cout << "\n\n" << setw(ScreenWidth) << "" << left <<Green<< "----------------------------------------------"<<White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue<<   "          Employee Summary Report"<<Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left <<Green<<   "----------------------------------------------"<<White;

		cout << "\n" << setw(ScreenWidth +ScreenToMove) << "" << left << "Total Employee             : " << TotalEmployee;
		cout << "\n" << setw(ScreenWidth +ScreenToMove) << "" << left << "Active Employees           : " << CountActiveEmployee;
		cout << "\n" << setw(ScreenWidth +ScreenToMove) << "" << left << "Suspended Employees        : " << CountSuspendedEmployee;
		cout << "\n" << setw(ScreenWidth +ScreenToMove) << "" << left << "Resigned Employees         : " << TotalEmployee - (CountActiveEmployee+ CountSuspendedEmployee);
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;



		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "          Employees by Job Title" << Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;

		vector<string>vJobList = clsEmployee::JobTitleList();

		for (string& Job : vJobList)
		{
			cout << "\n" << setw(ScreenWidth+ ScreenToMove) << "" << left << setw(25) << Job << left << " : " << clsEmployee::CountEmployeesByJob(Job);
		}

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;







		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "         Employees by Residence" << Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;

		vector<string>vResidenceList = clsEmployee::ResidencesNameList();

		for (string& Residence : vResidenceList)
		{
			cout << "\n" << setw(ScreenWidth+ ScreenToMove) << "" << left << setw(25)<<Residence<<left << " : "<< clsEmployee::CountEmployeesByResidence(Residence);
		}

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;




		cout << "\n\n" << setw(ScreenWidth) << "" << left <<Green <<"----------------------------------------------"<<White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue<<   "             Salary Statistics"<<Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left <<Green<<    "----------------------------------------------"<<White;

		double TotalMonthlyPayroll = clsEmployee::TotalMonthlyPayroll();
		clsEmployee HighestEmployeeSalary = clsEmployee::HighestSalaryEmployee();
		clsEmployee LowestEmployeeSalary = clsEmployee::LowestSalaryEmployee();
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Total Monthly Payroll      : " << TotalMonthlyPayroll;
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Average salary             : " << TotalMonthlyPayroll/ TotalEmployee;
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Highest Employee Salary    : " << HighestEmployeeSalary.Salary<<" ("<< HighestEmployeeSalary .JobTitle<<")";
		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Lowest Employee Salary     : " << LowestEmployeeSalary.Salary << " (" << LowestEmployeeSalary.JobTitle << ")";;
		cout << "\n" << setw(ScreenWidth) << "" << left <<Green<< "----------------------------------------------\n\n"<<White;

		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue <<    "             Shift Distribution" << Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green <<   "----------------------------------------------" << White;

		cout << "\n" << setw(ScreenWidth+ ScreenToMove) << "" << left << "Morning Shift               : "<<clsEmployee::CountEmployeeByShift(clsEmployee::enShift::eMorning);
		cout << "\n" << setw(ScreenWidth+ ScreenToMove) << "" << left << "Afternoon Shift             : "<<clsEmployee::CountEmployeeByShift(clsEmployee::enShift::eMorning);
		cout << "\n" << setw(ScreenWidth+ ScreenToMove) << "" << left << "Night Shift                 : "<<clsEmployee::CountEmployeeByShift(clsEmployee::enShift::eNight);

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;



		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue <<    "         Top 3 Highest Paid Employees" << Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green <<   "----------------------------------------------" << White;

		clsEmployee FirstEmployee = clsEmployee::HighestSalaryEmployee();
		clsEmployee SecondEmployee = clsEmployee::SecondsSalaryEmployeePayment() ;
		clsEmployee ThirdEmployee  =   clsEmployee::ThirdSalaryEmployeePayment();
										
		cout << "\n" << setw(ScreenWidth+2) << "" << left << FirstEmployee.FullName()<<  " - "<<FirstEmployee.JobTitle<<" - "<< FirstEmployee.Salary;
		cout << "\n" << setw(ScreenWidth+2) << "" << left << SecondEmployee.FullName()<< " - " << SecondEmployee.JobTitle << " - " << SecondEmployee.Salary;
		cout << "\n" << setw(ScreenWidth+2) << "" << left  << ThirdEmployee.FullName()<< " - " << ThirdEmployee.JobTitle << " - " << ThirdEmployee.Salary;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;




		cout << "\n\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "         Top 3 Highest Paid Employees" << Blue;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------" << White;

		cout << "\n" << setw(ScreenWidth+2) << "" << left << "Total Employee Hired In This Month   : "<< clsEmployee::CountHiredEmployeeInCurrentMonth()<< White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "----------------------------------------------\n\n" << White;



	}


public:

	static void ShowEmployeeReportScreen()
	{

		system("cls");

		clsBase::_DrawScreenHeader("\t\tEmployee Report Screen");
		if (clsInputValidate::IsSureToPerform())
		{
			vector<clsEmployee>vEmployees = clsEmployee::GetEmployeeList();

			PrintReport(vEmployees);

		}





	}




};

