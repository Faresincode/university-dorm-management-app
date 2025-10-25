#pragma once
#include <iostream>
#include <vector> 
#include "clsPerson.h";
#include "clsStudentInfo.h";
#include "clsEmployeeInfo.h";
#include "Global.h";
#include "clsRoom.h";
#include "clsStudentDorm.h";
#include "clsEmployee.h";
#include "clsSchedule.h";
#include "clsFinance.h";
#include "clsMaintenance.h";
#include "clsSecurity.h";
#include "clsPatrolSchedule.h";
#include "clsIncidentReport.h";
#include "clsVisitor.h";

using namespace std;


class clsGlobalPrint
{




public:



	static void PrintLoginInfo(clsLogin Login)
	{
		cout << "\n" << setw(ScreenWidth) << left << "" << Green << "===========================================================\n" << White;
		cout << setw(ScreenWidth) << left << "" << Red << "                Login Account Information\n";
		cout << setw(ScreenWidth) << left << "" << Green << "===========================================================\n" << White;
		cout << "\n" << setw(ScreenWidth) << left << "" << "Username       : " << Login.UserName;
		cout << "\n" << setw(ScreenWidth) << left << "" << "Password       : " << Login.Password;
		cout << "\n" << setw(ScreenWidth) << left << "" << "Permissions    : " << Login.Permissions;
		cout << "\n" << setw(ScreenWidth) << left << "" << Green << "===========================================================\n" << White;
	}

	static void PrintFullVisitorInfo(clsVisitor Visitor)
	{
		cout << "\n\n"<<setw(ScreenWidth) << left << ""<<Green << "-----------------------------------------------------" << White;
		cout << "\n"<<setw(ScreenWidth) << left << "" << Yellow << "               Visitor Information" << White;
		cout << "\n"<<setw(ScreenWidth) << left << ""<< Green << "-----------------------------------------------------" << White;
		cout << "\n"<<setw(ScreenWidth) << left << "" << Green << "Visitor ID             : " << White << Visitor.VisitorID ;
		cout << "\n"<<setw(ScreenWidth) << left << "" << Green << "First Name             : " << White << Visitor.FirstName ;
		cout << "\n"<<setw(ScreenWidth) << left << "" << Green << "Last Name              : " << White << Visitor.LastName ;
		cout << "\n"<<setw(ScreenWidth) << left << "" << Green << "Visit Date/Time        : " << White << Visitor.VisitDateTime ;
		cout << "\n"<<setw(ScreenWidth) << left << "" << Green << "Building To Visit      : " << White << Visitor.VisitedDepartment ;
		cout << "\n"<<setw(ScreenWidth) << left << "" << Green << "Room To Visit          : " << White << Visitor.VisitedRoom   ;
		cout << "\n"<<setw(ScreenWidth) << left << "" << Green << "Purpose                : " << White << Visitor.VisitPurpose ;
		cout << "\n"<<setw(ScreenWidth) << left << "" <<Green <<  "Logged By Security ID  : " <<White << Visitor.SecurityID ;
		cout << "\n"<<setw(ScreenWidth) << left << "" << Green << "Visitor Status         : " << White << clsVisitor::VisitorStatusString( Visitor.VisitorStatus) ;
		if (Visitor.ExitDateTime != "0")
		{
			cout << "\n" << setw(ScreenWidth) << left << "" <<Green<< "Exit Date/Time         : " << White << Visitor.ExitDateTime << endl;

		}


		cout << "\n" << setw(ScreenWidth) << left << "" << Green << "-----------------------------------------------------" << White<<endl;
	}

	static void PrintIncidentInfo( clsIncidentReport& Incident)
	{
		cout <<"\n" << setw(ScreenWidth) << "" << left <<Green<< "---------------------------------------------"<<White;
		cout <<"\n" <<setw(ScreenWidth) << "" << left <<Red<<"         Incident Report Details"<<White;
		cout <<"\n" <<setw(ScreenWidth) << "" << left <<Green<< "---------------------------------------------"<<White;

		cout <<"\n"<< setw(ScreenWidth) << ""<<Blue << left << "Incident ID        : " <<White<< Incident.IncidentID ;
		cout <<"\n"<< setw(ScreenWidth) << ""<<Blue << left << "Security ID        : " <<White<< Incident.SecurityID ;
		cout <<"\n"<< setw(ScreenWidth) << ""<<Blue << left << "Incident Date/Time : " <<White<< Incident.IncidentDateTime ;
		cout <<"\n"<< setw(ScreenWidth) << ""<<Blue << left << "Incident Type      : " <<White<< Incident.IncidentType ;
		cout <<"\n"<< setw(ScreenWidth) << ""<<Blue << left << "Description        : " <<White<< Incident.Description ;
		cout <<"\n"<< setw(ScreenWidth) << ""<<Blue << left << "Severity Level     : " <<White<< clsIncidentReport::GetSeverityString(Incident.Severity) ;
		cout <<"\n"<< setw(ScreenWidth) << ""<<Blue << left << "Status             : " <<White<< clsIncidentReport::GetIncidentStatusString(Incident.Status) ;
		cout <<"\n"<< setw(ScreenWidth) << ""<<Blue << left << "Last Update        : " <<White<< Incident.LastUpdateDateTime ;

		cout << "\n" << setw(ScreenWidth) << "" << left << Green<< "---------------------------------------------\n"<<White;
	}



	static void PrintPatrolSchedule(clsPatrolSchedule Patrol)
	{
		cout << "\n"<<setw(ScreenWidth) << left << "" << Green << "------------------------------------------------------" << White;
		cout << "\n"<<setw(ScreenWidth) << left << "" << Yellow <<"\tPatrol Schedule Details" << White;
		cout << "\n"<<setw(ScreenWidth) << left << "" << Green << "----------------------------------------------------" << White;

		cout << "\n"<<setw(ScreenWidth) << left << "" << "Patrol ID                : " << Patrol.PatrolID ;
		cout << "\n"<<setw(ScreenWidth) << left << "" << "Security ID              : " << Patrol.SecurityID ;
		cout << "\n"<<setw(ScreenWidth) << left << "" << "Patrol Location          : " << Patrol.PatrolLocation ;
		cout << "\n"<<setw(ScreenWidth) << left << "" << "Start Time               : " << Patrol.StartTime ;
		cout << "\n"<<setw(ScreenWidth) << left << "" << "EndTime                  : " << Patrol.EndTime;
		cout << "\n"<<setw(ScreenWidth) << left << "" << "Status                   : " << clsPatrolSchedule::GetPatrolStatusString(Patrol.PatrolStatus) ;
		cout << "\n"<<setw(ScreenWidth) << left << "" << "Last Update Date         : " << Patrol.LastUpdateDateTime << endl;

		cout << "\n"<<setw(ScreenWidth) << left << "" << Green << "------------------------------------------------------" << White<<endl;
	}


	static void PrintFullSecurityEmployeeInfo(clsSecurity SecurityEmployee)
	{
		clsGlobalPrint::PrintFullDormEmployeeInfo(SecurityEmployee);
		clsGlobalPrint::PrintSecurityEmployeeInfo(SecurityEmployee);

	}


	static void PrintPaymentRecordLine(clsFinance Payment)
	{

		cout << setw(2) << left << "" << Green << "| " << White << setw(16) << left << Payment.PaymentID;
		cout << Green << "| " << White << setw(16) << left << Payment.StudentDormID;
		cout << Green << "| " << White << setw(35) << left << Payment.PaymentDateTime;
		cout << Green << "| " << White << setw(20) << left << Payment.Amount;
		cout << Green << "| " << White << setw(20) << left << clsFinance::PaymentMethodString(Payment.PaymentMethod);
		cout << Green << "| " << White << setw(20) << left << clsFinance::PaymentStatusString(Payment.PaymentStatus);


	}

	static void PrintPaymentsTableHeader()
	{

		cout << "\n" << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________\n\n" << White;


		cout << setw(2) << left << "" << Green << "| " << White << setw(16) << left << "Payment ID";
		cout << Green << "| " << White << setw(16) << left << "Student Dorm ID";
		cout << Green << "| " << White << setw(35) << left << "Payment Date time";
		cout << Green << "| " << White << setw(20) << left << "Amount";
		cout << Green << "| " << White << setw(20) << left << "Payment Method";
		cout << Green << "| " << White << setw(20) << left << "Payment Status";
		cout << "\n" << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________\n\n" << White;

	}

	static void PrintPaymentsTable(vector <clsFinance> vPayments)
	{

		PrintPaymentsTableHeader();
		for (clsFinance& Pay : vPayments)
		{
			PrintPaymentRecordLine(Pay);
			cout << endl;
		}

		cout << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________" << White << endl;


	}

	static void PrintScheduleEmployeeRecordLine(clsSchedule Employee)
	{

		cout << setw(2) << left << "" << Green << "| " << White << setw(15) << left << Employee.EmployeeID;
		cout << Green << "| " << White << setw(30) << left << Employee.ResidenceName;
		cout << Green << "| " << White << setw(13) << left << clsSchedule::GetShiftString(Employee.ShiftStart);
		cout << Green << "| " << White << setw(13) << left << clsSchedule::GetShiftString(Employee.ShiftEnd);
		cout << Green << "| " << White << setw(35) << left << clsSchedule::WorkDaysString(Employee);
		cout << Green << "| " << White << setw(25) << left << Employee.LastUpdated;


	}

	static void PrintScheduleEmployeeTableHeader()
	{

		cout << "\n" << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________\n\n" << White;


		cout << setw(2) << left << "" << Green << "| " << White << setw(15) << left << "Employee ID";
		cout << Green << "| " << White << setw(30) << left << "Residence Name";
		cout << Green << "| " << White << setw(13) << left << "Shift Start";
		cout << Green << "| " << White << setw(13) << left << "Shift End";
		cout << Green << "| " << White << setw(35) << left << "Work Days";
		cout << Green << "| " << White << setw(25) << left << "Last Updated";
		cout << "\n" << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________\n\n" << White;

	}

	static void PrintEmployeeRecordLine(clsEmployee Payment)
	{

		cout << setw(2) << left << "" << Green << "| " << White << setw(12) << left << Payment.EmployeeID;
		cout << Green << "| " << White << setw(25) << left << Payment.FullName();
		cout << Green << "| " << White << setw(25) << left << Payment.ResidenceName;
		cout << Green << "| " << White << setw(25) << left << Payment.ResidenceDepartment;
		cout << Green << "| " << White << setw(25) << left << Payment.JobTitle;
		cout << Green << "| " << White << setw(11) << left << Payment.StatusToString(Payment.Status);
		cout << Green << "| " << White << setw(10) << left << Payment.ShiftToString(Payment.Shift);


	}

	static void PrintEmployeeHeader()
	{

		cout << "\n" << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________\n\n" << White;


		cout << setw(2) << left << "" << Green << "| " << White << setw(12) << left << "Employee ID";
		cout << Green << "| " << White << setw(25) << left << "Full Name";
		cout << Green << "| " << White << setw(25) << left << "Residence Name";
		cout << Green << "| " << White << setw(25) << left << "R.Department";
		cout << Green << "| " << White << setw(25) << left << "Job Title";
		cout << Green << "| " << White << setw(10) << left << "Status";
		cout << Green << "| " << White << setw(10) << left << "Shift";
		cout << "\n" << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________\n\n" << White;

	}

	static void PrintPersonalInfo(clsPerson Person)
	{
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "---------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Red <<   "                Personal Info";
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "---------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left<<Blue<< "FirstName              : " << White << Person.FirstName;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left<<Blue<< "LastName               : " << White << Person.LastName;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left<<Blue<< "Gender                 : " << White << clsPerson::GetGenderString(Person.Gender);
		cout << "\n" << setw(ScreenWidth + 1) << "" << left<<Blue<< "Date Of Birth          : " << White << Person.DateOfBirth;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left<<Blue<< "Nationality            : " << White << Person.Nationality;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left<<Blue<< "Email                  : " << White << Person.Email;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left<<Blue<< "Phone                  : " << White << Person.Phone;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "---------------------------------------------" << White << endl;

	}

	static void PrintEmployeeInfo(clsEmployeeInfo Employee)
	{
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Green << "-------------------------------------------";
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Red <<   "         Employee Information Info";
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Green << "-------------------------------------------";
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue <<  "Job Title              : " << White << Employee.JobTitle;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue <<  "Salary                 : " << White << Employee.Salary;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue <<  "Hire Date              : " << White << Employee.HireDate;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue <<  "Shift                  : " << White << clsEmployeeInfo::ShiftToString(Employee.Shift);
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue <<  "Status                 : " << White << clsEmployeeInfo::StatusToString(Employee.Status);
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Green << "-------------------------------------------" << White<<endl;
	}

	static void PrintDormRoomInfo(clsRoom Room)
	{
		cout << "\n";
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================";
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "                Room Info : ";
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Residence Name           : " << Room.ResidenceName;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Dorm Building            : " << Room.DormBuilding;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Room Number              : " << Room.RoomNumber;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Room Capacity            : " << Room.RoomCapacity;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Occupied Beds            : " << Room.OccupiedBeds;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Available Beds           : " << Room.GetAvailableBeds();
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================" << White<< endl;

	}

	static void PrintStudentInfo(clsStudentInfo Student)
	{
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "___________________________________________\n" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Red << "         Student University Info:";
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "___________________________________________" << White;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Student ID        : " << White << Student.StudentID;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "University Name   : " << White << Student.UniversityName;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Faculty           : " << White << Student.Faculty;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Department        : " << White << Student.Department;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Nationality       : " << White << Student.Nationality;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "YearLevel         : " << White << clsStudentInfo::GetYearLevelString(Student.YearLevel);
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Speciality        : " << White << Student.Speciality;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "___________________________________________" << White << endl;

	}

	static void PrintDormStudent(clsStudentDorm DormStudent)
	{

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "___________________________________________\n" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Red << "             Dorm Student Info";
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "___________________________________________\n" << White;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Student Dorm Id   : " << White << DormStudent.StudentDormId;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Residence Name    : " << White << DormStudent.ResidenceName;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Dorm Building     : " << White << DormStudent.DormBuilding;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Room Number       : " << White << DormStudent.RoomNumber;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Bed Number        : " << White << DormStudent.BedNumber;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Admission Date    : " << White << DormStudent.AdmissionDate;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Admission Date    : " << White << DormStudent.CheckoutDate;
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Status            : " << White << clsStudentDorm::GetStatusString(DormStudent.Status);
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Meal Plan         : " << White << clsStudentDorm::GetMealPlanString(DormStudent.MealPlan);
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "___________________________________________\n" << White;
		cout << endl;


	}

	static void PrintResidenceEmployeeInfo(clsEmployee Employee)
	{


		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "---------------------------------------------";
		cout << "\n" << setw(ScreenWidth) << "" << left << Red << "           Residence Employee Info";
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "---------------------------------------------" << White;

		cout << "\n" << setw(ScreenWidth) << "" << left << Blue <<  "Employee ID             : " << White << Employee.EmployeeID;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue <<  "ResidenceName           : " << White << Employee.ResidenceName;
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue <<  "R.Department            : " << White << Employee.ResidenceDepartment;

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "---------------------------------------------" << White;
		cout << endl;

	}

	static void PrintFullDormEmployeeInfo(clsEmployee Employee)
	{

		PrintPersonalInfo(Employee);
		PrintEmployeeInfo(Employee);
		PrintResidenceEmployeeInfo(Employee);

	}

	static void PrintPayment(clsFinance StudentPayment)
	{
		cout << "\n";
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================";
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "          Student Payment Card : ";
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Payment ID           : " << StudentPayment.PaymentID;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Student DormID       : " << StudentPayment.StudentDormID;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Payment Method       : " << clsFinance::PaymentMethodString( StudentPayment.PaymentMethod);
		cout << "\n" << setw(ScreenWidth) << "" << left << " Payment Status       : " << clsFinance::PaymentStatusString(StudentPayment.PaymentStatus);
		cout << "\n" << setw(ScreenWidth) << "" << left << " Amount               : " << StudentPayment.Amount;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Description          : " << StudentPayment.Description;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Payment Date Time    : " << StudentPayment.PaymentDateTime;
		cout <<"\n" << setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
		cout << endl;

	}

	static void PrintScheduleEmployeeTable()
	{
		cout << "\n" << setw(ScreenWidth) << left << "" << Green << Red << "\t\tEmployee Schedule Table " << White;

		vector<clsSchedule>vSchedules = clsSchedule::GetSchedulesList();
		PrintScheduleEmployeeTableHeader();
		for (clsSchedule& Schedule : vSchedules)
		{
			PrintScheduleEmployeeRecordLine(Schedule);
			cout << endl;
		}
		cout << "\n" << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________\n\n" << White;


	}



	static void PrintMaintRequest(clsMaintenance MainRequest)
	{
		cout << "\n";
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================";
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "          Maintenance Request Card : ";
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Request ID                : " << MainRequest.RequestID;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Dorm Building             : " << MainRequest.DormBuilding;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Room Number               : " << MainRequest.RoomNumber;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Issue Type                : " << MainRequest.IssueType;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Issue Description         : " << MainRequest.IssueDescription;
		cout << "\n" << setw(ScreenWidth) << "" << left << " RequestDate               : " << MainRequest.RequestDate;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Status                    : " << clsMaintenance::GetStatusString (MainRequest.Status);
		cout << "\n" << setw(ScreenWidth) << "" << left << " Priority                  : " << clsMaintenance::GetPriorityLevelString( MainRequest.Priority);
		cout << "\n" << setw(ScreenWidth) << "" << left << " Assigned Staff ID         : " << MainRequest.AssignedStaffID;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Last Update Date          : " << MainRequest.LastUpdateDate;


		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
		cout << endl;

	}

	static void PrintSecurityEmployeeInfo(clsSecurity SecurityEmployee)
	{

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "------------------------------------------";
		cout << "\n" << setw(ScreenWidth) << "" << left << Red <<   "         Security Employee Info "<<White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left <<Blue<< " Security ID            : " <<White<< SecurityEmployee.SecurityID;
		cout << "\n" << setw(ScreenWidth) << "" << left <<Blue<< " Employee ID            : " <<White<< SecurityEmployee.EmployeeID;
		cout << "\n" << setw(ScreenWidth) << "" << left <<Blue<< " Security Status        : " <<White<< clsSecurity::SecurityStatusString(SecurityEmployee.SecurityStatus);
		cout << "\n" << setw(ScreenWidth) << "" << left <<Blue<< " Supervisor ID          : " <<White<< SecurityEmployee.SupervisorID;
		cout << "\n" << setw(ScreenWidth) << "" << left <<Blue<< " Assigned Building      : " <<White<< SecurityEmployee.AssignedBuilding;
		cout << "\n" << setw(ScreenWidth) << "" << left <<Blue<< " Last Update Date       : " <<White<< SecurityEmployee.LastUpdateDate;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "------------------------------------------" << White<<endl;
	}




	static void PrintResult(clsEmployee::enSaveResults SaveResult, clsEmployee Employee)
	{

		switch (SaveResult)
		{
		case clsEmployee::enSaveResults::svSucceeded:
		{
			cout << Green << "\n" << setw(ScreenWidth) << "" << left << "Employee Info Updated Successfully :-)\n" << White;
			clsGlobalPrint::PrintFullDormEmployeeInfo(Employee);

			break;
		}
		case clsEmployee::enSaveResults::svFaildEmptyObject:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Employee was not saved because Object it's Empty\n" << White;
			break;
		}
		case clsEmployee::enSaveResults::svFaildEmployeeExist:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Employee was not saved because Is already exist\n" << White;
			break;

		}

		}


	}

	static void PrintResult(clsStudentDorm::enSaveResults SaveResult, clsStudentDorm Student)
	{

		switch (SaveResult)
		{
		case clsStudentDorm::enSaveResults::svSucceeded:
		{
			cout << Green << "\n" << setw(ScreenWidth) << "" << left << "Student Info Updated Successfully :-)\n" << White;
			clsGlobalPrint::PrintDormStudent(Student);
			break;
		}
		case clsStudentDorm::enSaveResults::svFaildEmptyObject:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error account was not saved because it's Empty\n" << White;
			break;
		}

		}


	}

	static void PrintResult(clsSchedule::enSaveResults SaveResult, clsSchedule EmployeeSchedule)
	{

		switch (SaveResult)
		{
		case clsEmployee::enSaveResults::svSucceeded:
		{
			cout << Green << "\n" << setw(ScreenWidth) << "" << left << "Employee Info Updated Successfully :-)\n" << White;
			PrintScheduleEmployeeTable();
			break;
		}
		case clsEmployee::enSaveResults::svFaildEmptyObject:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Employee was not saved because Object it's Empty\n" << White;
			break;
		}
		case clsEmployee::enSaveResults::svFaildEmployeeExist:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Employee was not saved because Is already exist\n" << White;
			break;

		}

		}


	}

	static void PrintResult(clsFinance::enSaveResults SaveResult, clsFinance Payment)
	{

		switch (SaveResult)
		{
		case clsFinance::enSaveResults::svSucceeded:
		{
			cout << Green << "\n" << setw(ScreenWidth) << "" << left << "Payment Info Updated Successfully :-)\n" << White;
			clsGlobalPrint::PrintPayment(Payment);

			break;
		}
		case clsFinance::enSaveResults::svFaildEmptyObject:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Payment Info was not saved because Object it's Empty\n" << White;
			break;
		}
		case clsFinance::enSaveResults::svFaildPaymentExist:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Payment was not saved because Is already exist\n" << White;
			break;

		}

		}


	}

	static void PrintResult(clsMaintenance::enSaveResults SaveResult, clsMaintenance MaintenanceRequest)
	{

		switch (SaveResult)
		{
		case clsFinance::enSaveResults::svSucceeded:
		{
			cout << Green << "\n" << setw(ScreenWidth) << "" << left << "Problem Fixed Successfully :-)\n" << White;
			PrintMaintRequest(MaintenanceRequest);
			break;
		}
		case clsFinance::enSaveResults::svFaildEmptyObject:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Problem is not Fixed Info was not saved because Object it's Empty\n" << White;
			break;
		}
		case clsFinance::enSaveResults::svFaildPaymentExist:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Request was not saved because Is already exist\n" << White;
			break;

		}

		}


	}

	static void PrintResult(clsSecurity::enSaveResults SaveResult, clsSecurity SecurityEmployee)
	{

		switch (SaveResult)
		{
		case clsSecurity::enSaveResults::svSucceeded:
		{
			cout << Green << "\n" << setw(ScreenWidth) << "" << left << "Security Employee Info Updated Successfully :-)\n" << White;
			PrintSecurityEmployeeInfo(SecurityEmployee);
		    break;
		}
		case clsSecurity::enSaveResults::svFaildEmptyObject:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Security Employee Info was not saved because Object it's Empty\n" << White;
			break;
		}
		case clsSecurity::enSaveResults::svFaildSecurityExist:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Security Employee was not saved because Is already exist\n" << White;
			break;

		}

		}


	}

	static void PrintResult(clsPatrolSchedule::enSaveResults SaveResult, clsPatrolSchedule PatrolSchedule)
	{

		switch (SaveResult)
		{
		case clsSecurity::enSaveResults::svSucceeded:
		{
			cout << Green << "\n" << setw(ScreenWidth) << "" << left << "Patrol Schedule Info Updated Successfully :-)\n" << White;
			PrintPatrolSchedule(PatrolSchedule);
			break;
		}
		case clsSecurity::enSaveResults::svFaildEmptyObject:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Patrol Schedule Info was not saved because Object it's Empty\n" << White;
			break;
		}
		case clsSecurity::enSaveResults::svFaildSecurityExist:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Patrol Schedule was not saved because Is already exist\n" << White;
			break;

		}

		}


	}

	static void PrintResult(clsIncidentReport::enSaveResults SaveResult, clsIncidentReport Incident)
	{

		switch (SaveResult)
		{
		case clsIncidentReport::enSaveResults::svSucceeded:
		{
			cout << Green << "\n" << setw(ScreenWidth) << "" << left << "Incident Info Updated Successfully :-)\n" << White;
			PrintIncidentInfo(Incident);
			break;
		}
		case clsIncidentReport::enSaveResults::svFaildEmptyObject:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Incident Info was not saved because Object it's Empty\n" << White;
			break;
		}
		case clsIncidentReport::enSaveResults::svFaildObjectExist:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Incident was not saved because Is already exist\n" << White;
			break;

		}

		}


	}

	static void PrintResult(clsVisitor::enSaveResults SaveResult, clsVisitor Visitor)
	{

		switch (SaveResult)
		{
		case clsVisitor::enSaveResults::svSucceeded:
		{
			cout << Green << "\n" << setw(ScreenWidth) << "" << left << "Visitor Info Updated Successfully :-)\n" << White;
			PrintFullVisitorInfo(Visitor);
			break;
		}
		case clsVisitor::enSaveResults::svFaildEmptyObject:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Visitor Info was not saved because Object it's Empty\n" << White;
			break;
		}
		case clsVisitor::enSaveResults::svFaildVisitorExist:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error Visitor was not saved because Is already exist\n" << White;
			break;

		}

		}


	}

	static void PrintResult(clsLogin::enSaveResults SaveResult, clsLogin User)
	{

		switch (SaveResult)
		{
		case clsLogin::enSaveResults::svSuccess:
		{
			cout << Green << "\n" << setw(ScreenWidth) << "" << left << "User Info Updated Successfully :-)\n" << White;
			PrintLoginInfo(User);
			break;
		}
		case clsLogin::enSaveResults::svFailEmpty:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error User Info was not saved because Object it's Empty\n" << White;
			break;
		}
		case clsLogin::enSaveResults::svFailUsernameExists:
		{
			cout << Red << "\n" << setw(ScreenWidth) << "" << left << "Error User was not saved because Is already exist\n" << White;
			break;

		}

		}


	}



};

