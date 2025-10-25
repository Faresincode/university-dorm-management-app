#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsEmployee.h";
#include "clsGlobalPrint.h";
#include "clsGlobalRead.h";
#include "clsMaintenance.h";
#include "clsVisitor.h";
#include "clsUtil.h";

using namespace std;


class clsGlobalRead
{

private:

	


public:

    static string GenerateNewEmployeeID()
    {


        string EmployeeId = clsUtil::GenerateID("EMP");
        while (clsEmployee::IsEmployeeExist(EmployeeId))
        {
            EmployeeId = clsUtil::GenerateID("EMP");

        }
        return EmployeeId;

    }


    static string ReadIncidentID()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Incident ID: ";
        string IncidentID = clsInputValidate::ReadString();

        while (!clsIncidentReport::IsIncidentExist(IncidentID))
        {
            cout << Yellow << "\n" << setw(ScreenWidth) << "" << left << "Incident not found, please enter a valid one:  " << White;
            IncidentID = clsInputValidate::ReadString();

        }

        return IncidentID;
    }

    static string  ReadVisitorId()
    {
        cout << "\n" << setw(ScreenWidth) << left << "" << Green << "Enter Visitor ID: " << White;
        string VisitorId = clsInputValidate::ReadString();

        while (!clsVisitor::IsVisitorExist(VisitorId))
        {
            cout << setw(ScreenWidth) << left << "" << Green << Yellow << "Error! this Is not exist : try other one: " << White;
            VisitorId = clsInputValidate::ReadString();

        }
        return VisitorId;
    }



    static string ReadSecurityID()
    {

        cout << "\n" << setw(ScreenWidth) << left << "" << Green << "Enter Security ID: " << White;
        string SecurityId = clsInputValidate::ReadString();

        while (!clsSecurity::IsSecurityExistBySecurityId(SecurityId))
        {
            cout << setw(ScreenWidth) << left << "" << Green << Yellow << "Error! this Is not exist : try other one: " << White;
            SecurityId = clsInputValidate::ReadString();

        }

        return SecurityId;

    }

    static string  ReadPatrolID()
    {
        cout << "\n" << setw(ScreenWidth) << left << "" << Green << "Enter schedule ID: " << White;
        string ScheduleID = clsInputValidate::ReadString();

        while (!clsPatrolSchedule::IsScheduleExist(ScheduleID))
        {
            cout << setw(ScreenWidth) << left << "" << Green << Yellow << "Error! this Is not exist : try other one: " << White;
            ScheduleID = clsInputValidate::ReadString();

        }

        return ScheduleID;


    }


    static void ReadPatrolScheduleInfo(clsPatrolSchedule& Patrol)
    {


        cout << "\n" << setw(ScreenWidth) << "" << left << "Patrol ID = " << Patrol.PatrolID;

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Patrol Status: [ 1 = Scheduled, 2 = InProgress, 3 = Completed, 4 = Cancelled ]: ";
        Patrol.PatrolStatus = (clsPatrolSchedule::enPatrolStatus)clsInputValidate::ReadNumberBetween<short>(1, 4);

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Patrol Location: ";
        Patrol.PatrolLocation = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left;
        Patrol.StartTime = clsGlobalRead::ReadDate("Read Patrol Start Time: ");

        cout << "\n" << setw(ScreenWidth) << "" << left;
        Patrol.EndTime = clsGlobalRead::ReadDate("Read Patrol End Time : ");

        Patrol.LastUpdateDateTime = clsDate::GetSystemDateTimeString();

    }


    static string ReadSecurityEmployeeID()
    {
        cout << "\n" << setw(ScreenWidth) << left << "" << Green << "Enter Security Employee ID: " << White;
        string S_EmployeeID = clsInputValidate::ReadString();

        while (!clsSecurity::IsSecurityExist(S_EmployeeID))
        {
            cout << setw(ScreenWidth) << left << "" << Green << Yellow << "Error! this Is not exist : try other one: " << White;
            S_EmployeeID = clsInputValidate::ReadString();

        }

        return S_EmployeeID;

    }

    static void ReadNewFullSecurityEmployeeInfo(clsSecurity& SecurityEmployee)
    {
        SecurityEmployee.EmployeeID = clsGlobalRead::GenerateNewSecurityEmployeeId();
        clsGlobalRead::ReadPersonalInfo(SecurityEmployee);
        clsGlobalRead::ReadEmployeeInfo(SecurityEmployee);
        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "Read Dorm Employee Info: \n" << White;
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Residence Name: ";
        SecurityEmployee.ResidenceName = clsInputValidate::ReadString();
        SecurityEmployee.ResidenceDepartment = "Security";
        clsGlobalRead::ReadNewSecurityGuardInfo(SecurityEmployee);

    }


    static void ReadDormEmployeeInfo(clsEmployee& Employee)
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "Read Dorm Employee Info: \n" << White;
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Residence Name: ";
        Employee.ResidenceName = clsInputValidate::ReadString();
        
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Work Residence Department: ";
        Employee.ResidenceDepartment = clsInputValidate::ReadString();

    }

    static string ReadDate(string Title = "Enter Date")
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << Title << "\n\n" << White;
        clsDate Date;
        cout << setw(ScreenWidth) << "" << left << "Enter Day   :";
        Date.Day = clsInputValidate::ReadNumber<short>();
        cout << setw(ScreenWidth) << "" << left << "Enter Month : ";
        Date.Month = clsInputValidate::ReadNumber<short>();
        cout << setw(ScreenWidth) << "" << left << "Enter Year  : ";
        Date.Year = clsInputValidate::ReadNumber<short>();
        while (!clsDate::IsValidDate(Date))
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << Yellow << "Invalid Date try Again  :\n";
            cout << setw(ScreenWidth) << "" << left << "Enter Day   :";
            Date.Day = clsInputValidate::ReadNumber<short>();
            cout << setw(ScreenWidth) << "" << left << "Enter Month : ";
            Date.Month = clsInputValidate::ReadNumber<short>();
            cout << setw(ScreenWidth) << "" << left << "Enter Year  : ";
            Date.Year = clsInputValidate::ReadNumber<short>();
        }
        return (to_string(Date.Year) + "-" + to_string(Date.Month) + "-" + to_string(Date.Day));
    }

    static void ReadDateTime(clsDate& Date)
    {
        cout << setw(ScreenWidth) << "" << left << "Enter Day   :";
        Date.Day = clsInputValidate::ReadNumber<short>();
        cout << setw(ScreenWidth) << "" << left << "Enter Month : ";
        Date.Month = clsInputValidate::ReadNumber<short>();
        cout << setw(ScreenWidth) << "" << left << "Enter Year  : ";
        Date.Year = clsInputValidate::ReadNumber<short>();
        cout << setw(ScreenWidth) << "" << left << "Read Time  :";
        cout << setw(ScreenWidth) << "" << left << "Enter Hour : ";
        Date.Hours = clsInputValidate::ReadNumber<short>();
        cout << setw(ScreenWidth) << "" << left << "Enter Minutes : ";
        Date.Minutes = clsInputValidate::ReadNumber<short>();
        cout << setw(ScreenWidth) << "" << left << "Enter Seconds : ";
        Date.Seconds = clsInputValidate::ReadNumber<short>();
    }

    static string ReadDateTime(string Title = "Enter Date")
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << Title << "\n\n" << White;
        clsDate Date;
        ReadDateTime(Date);

        while (!clsDate::IsValidDateTime(Date))
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << Yellow << "Invalid Date try Again  :\n";
            ReadDateTime(Date);
        
        }

        return (to_string(Date.Year) + "-" + to_string(Date.Month) + "-" + to_string(Date.Day) + " "+to_string(Date.Hours)+ ":" + to_string(Date.Minutes)+":" + to_string(Date.Seconds));
    }



    static clsPerson::enGender ReadGender()
    {

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Gender: as following Menu [ Male= M or Femelle= F ]: ";
        char Gender = toupper(clsInputValidate::ReadCharacter());
        while (Gender != 'M' && Gender != 'F')
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << Yellow << "Error! Enter Gender: as following Menu [ Male = M or  Femelle= F ]: ";
            Gender = toupper(clsInputValidate::ReadCharacter());
        }
        return (clsPerson::enGender)Gender;
    }

    static void ReadPersonalInfo(clsPerson& Person)
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "Read Personal Student Info: \n" << White;
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter FirstName: ";
        Person.FirstName = clsInputValidate::ReadString();
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter LastName: ";
        Person.LastName = clsInputValidate::ReadString();
        Person.Gender = ReadGender();
        Person.DateOfBirth = ReadDate("Read Birth day");
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Nationality: ";
        Person.Nationality = clsInputValidate::ReadString();
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Email: ";
        Person.Email = clsInputValidate::ReadString();
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Phone: ";
        Person.Phone = clsInputValidate::ReadString();

    }

    static void ReadEmployeeInfo(clsEmployeeInfo& Employee)
    {

        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "Read Employee Info: \n" << White;

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Job Title: ";
        Employee.JobTitle = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Salary:";
        Employee.Salary = clsInputValidate::ReadNumber<double>();

        Employee.HireDate = ReadDate("Enter Hired Day");

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter work  Shift as following Menu \n";
        cout << "\n" << setw(ScreenWidth) << "" << left << "[ Morning = 1, Evening = 2, Night = 3, NoShift=0 ] : ";
        Employee.Shift = (clsEmployee::enShift)clsInputValidate::ReadNumberBetween(0, 3);

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter worker status : as following Menu: \n";
        cout << "\n" << setw(ScreenWidth) << "" << left << "[ Active = 1, Suspended = 2, Resigned = 3 , NoStatus=0 ] : ";
        Employee.Status = (clsEmployee::enStatus)clsInputValidate::ReadNumberBetween(0, 3);



    }

    static string GenerateNewSecurityId()
    {
        string SecurityId = clsUtil::GenerateID("SEC");
        while (clsSecurity::IsSecurityExistBySecurityId(SecurityId))
        {
            SecurityId = clsUtil::GenerateID("SEC");
        }

        return SecurityId;
    }

    static string GenerateNewSecurityEmployeeId()
    {
        string SecurityId = clsUtil::GenerateID("EMP");
        while (clsSecurity::IsSecurityExist(SecurityId))
        {
            SecurityId = clsUtil::GenerateID("EMP");
        }

        return SecurityId;
    }

    static void ReadNewSecurityGuardInfo(clsSecurity& SecurityGuard)
    {

        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "Read Security Guard Info: \n" << White;
        SecurityGuard.SecurityID = GenerateNewSecurityId();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Assigned Building: ";
        SecurityGuard.AssignedBuilding = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Security State: as following menu [ eActive = 1, eInactive = 2 ]: ";
        SecurityGuard.SecurityStatus = (clsSecurity::enSecurityStatus)clsInputValidate::ReadNumberBetween<short>(1, 2);

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Supervisor ID: ";
        SecurityGuard.SupervisorID = clsInputValidate::ReadString();


        SecurityGuard.LastUpdateDate = clsDate::GetSystemDateAsFormat("yyyy-mm-dd");
    }


    static clsEmployee ReadFullEmployeeInfo(string EmployeeId)
    {
        clsEmployee Employee = Employee.GetAddNewEmployeeObject(EmployeeId);
        clsGlobalRead::ReadPersonalInfo(Employee);
        clsGlobalRead::ReadEmployeeInfo(Employee);
        clsGlobalRead::ReadDormEmployeeInfo(Employee);
        return Employee;
    }


    static string ReadDormEmployeeId()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Dorm  Employee Id: ";
        string DormEmployeeId = clsInputValidate::ReadString();

        while (!clsEmployee::IsEmployeeExist(DormEmployeeId))
        {
            cout << Yellow << "\n" << setw(ScreenWidth) << "" << left << "Dorm employee is Not Exist , -choose another one:  " << White;
            DormEmployeeId = clsInputValidate::ReadString();
        }
        return DormEmployeeId;

    }

    static string ReadStudentPaymentId()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Student Dorm id : ";
        string DormStudentId = clsInputValidate::ReadString();

        while (!clsFinance::IsPaymentExist(DormStudentId))
        {
            cout << Yellow << "\n" << setw(ScreenWidth) << "" << left << "Dorm Student is not found, choose another one:  " << White;
            DormStudentId = clsInputValidate::ReadString();
     
        }
        return DormStudentId;

    }
    static string ReadMainRequestDormId()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Maintenance Request ID: ";
        string MainRequest = clsInputValidate::ReadString();

        while (!clsMaintenance::IsMaintenanceRequestExist(MainRequest))
        {
            cout << Yellow << "\n" << setw(ScreenWidth) << "" << left << "Request is not found, choose another one:  " << White;
            MainRequest = clsInputValidate::ReadString();
  
        }
        return MainRequest;

    }


    static string ReadStudentDormId()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Student Dorm: ";
        string DormStudentId = clsInputValidate::ReadString();

        while (!clsStudentDorm::IsDormStudentExist(DormStudentId))
        {
            cout << Yellow << "\n" << setw(ScreenWidth) << "" << left << "Dorm Student is not found, choose another one:  " << White;
            DormStudentId = clsInputValidate::ReadString();
        }
        return DormStudentId;

    }

    static string ReadPaymentDormStudentId()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Student Dorm: ";
        string DormStudentId = clsInputValidate::ReadString();

        while (!clsFinance::IsStudentExist(DormStudentId))
        {
            cout << Yellow << "\n" << setw(ScreenWidth) << "" << left << "Dorm Student is not found, choose another one:  " << White;
            DormStudentId = clsInputValidate::ReadString();

        }
        return DormStudentId;

    }


    static string ReadPaymentId()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Payment Id: ";
        string PaymentId = clsInputValidate::ReadString();

        while (!clsFinance::IsPaymentExist(PaymentId))
        {
            cout << Yellow << "\n" << setw(ScreenWidth) << "" << left << "Payment is not found, choose another Id:  " << White;
            PaymentId = clsInputValidate::ReadString();

        }
        return PaymentId;

    }



};

