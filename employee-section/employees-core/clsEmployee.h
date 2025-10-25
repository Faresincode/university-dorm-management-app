#pragma once
#include <iostream>
#include <Vector>
#include <iomanip>
#include <string>
#include "clsInputValidate.h";
#include "clsDate.h";
#include "clsUtil.h"; 
#include "Global.h";
#include "clsEmployeeInfo.h";

using namespace std;


class clsEmployee : public clsEmployeeInfo
{

private:
    friend class clsSecurity;
    enum enEmployeeMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };
    enEmployeeMode _Mode;
	string _EmployeeID;
	string _ResidenceName;
    string _ResidenceDepartment;
    bool _MarkForDelete = false;
    static clsEmployee _ConvertLineToEmployeeObject(string Line, string Separator = "#//#")
    {
        vector<string> vEmployeeData = clsString::Split(Line, Separator);

        // Expected order of data in file:
        // EmployeeID, ResidenceName, ResidenceDepartment, JobTitle, Salary, HireDate, Shift, Status, 
        // FirstName, LastName, Gender, DateOfBirth, Nationality, Email, Phone

        return clsEmployee
        (
            enEmployeeMode::eUpdateMode,                // Default mode when loading
            vEmployeeData[0],                      // EmployeeId
            vEmployeeData[1],                      // ResidenceName
            vEmployeeData[2],                      // ResidenceDepartment
            vEmployeeData[3],                      // JobTitle
            stod(vEmployeeData[4]),                // Salary
            vEmployeeData[5],                      // HireDate
            (enShift)stoi(vEmployeeData[6]),       // Shift
            (enStatus)stoi(vEmployeeData[7]),      // Status
            vEmployeeData[8],                      // FirstName
            vEmployeeData[9],                      // LastName
            (enGender)stoi(vEmployeeData[10]),     // Gender
            vEmployeeData[11],                     // DateOfBirth
            vEmployeeData[12],                     // Nationality
            vEmployeeData[13],                     // Email
            vEmployeeData[14]                      // Phone
        );
    }

    static string _ConvertEmployeeObjectToLine(clsEmployee Employee, string Separator = "#//#")
    {
        string Line = "";
        Line += Employee.EmployeeID + Separator;
        Line += Employee.ResidenceName + Separator;
        Line += Employee.ResidenceDepartment + Separator;
        Line += Employee.JobTitle + Separator;
        Line += to_string(Employee.Salary) + Separator;
        Line += Employee.HireDate + Separator;
        Line += to_string((int)Employee.Shift) + Separator;
        Line += to_string((int)Employee.Status) + Separator;
        Line += Employee.FirstName + Separator;
        Line += Employee.LastName + Separator;
        Line += to_string((int)Employee.Gender) + Separator;
        Line += Employee.DateOfBirth + Separator;
        Line += Employee.Nationality + Separator;
        Line += Employee.Email + Separator;
        Line += Employee.Phone;

        return Line;
    }


    static vector<clsEmployee> _LoadEmployeesDataFromFile()
    {
        vector<clsEmployee> vEmployees;
        fstream MyFile;
        MyFile.open(EmployeeDataFileName, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsEmployee Employee = _ConvertLineToEmployeeObject(Line);
                vEmployees.push_back(Employee);
            }
            MyFile.close();
        }
        return vEmployees;
    }

    static void _SaveEmployeesDataToFile(vector<clsEmployee> vEmployees)
    {
        fstream MyFile;
        MyFile.open(EmployeeDataFileName, ios::out);
        if (MyFile.is_open())
        {
            for (clsEmployee& Employee : vEmployees)
            {
                if (Employee._MarkForDelete == false)
                {
                    MyFile << _ConvertEmployeeObjectToLine(Employee) << endl;

                }
            }
            MyFile.close();
        }
    }


    static void _AddEmployeeLineToFile(string Line)
    {
        fstream MyFile;
        MyFile.open(EmployeeDataFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << Line << endl;
            MyFile.close();
        }
    }

    void _AddNewEmployee()
    {

        _AddEmployeeLineToFile(_ConvertEmployeeObjectToLine(*this));

    }

    static clsEmployee _GetEmptyEmployeeObject()
    {
        return clsEmployee
        (
            enEmployeeMode::eEmptyMode,
            "",
            "",
            "",
            "",
            0.0,
            "",
            enShift::eNoShift,
            enStatus::eNoStatus,
            "",
            "",
            enGender::eNoGender,
            "",
            "",
            "",
            ""
        );
    }

    bool _UpdateEmployee()
    {

        vector<clsEmployee> vEmployees = _LoadEmployeesDataFromFile();
        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.EmployeeID == EmployeeID)
            {
                Employee = *this;
                _SaveEmployeesDataToFile(vEmployees);
                return true;
            }
        }
        return false;


    }

public:

    //constructor
    clsEmployee(enEmployeeMode Mode,string EmployeeId, string ResidenceName, string ResidenceDepartment, string JobTitle, double Salary, string HireDate, enShift Shift, enStatus Status, string FirstName, string LastName, enGender Gender, string DateOfBirth, string Nationality, string Email, string Phone)
        :clsEmployeeInfo( JobTitle,  Salary,  HireDate,  Shift,  Status,  FirstName,  LastName,  Gender,  DateOfBirth,  Nationality,  Email,  Phone)
    {
        _Mode = Mode;
        _EmployeeID = EmployeeId;
        _ResidenceName = ResidenceName;
        _ResidenceDepartment = ResidenceDepartment;
    }



	void SetEmployeeID(string EmployeeID)
	{
		_EmployeeID = EmployeeID;
	}
	string GetEmployeeID() 
	{
		return _EmployeeID;
	}
	__declspec(property(get = GetEmployeeID, put = SetEmployeeID)) string EmployeeID;

	void SetResidenceName(string ResidenceName)
	{
		_ResidenceName = ResidenceName;
	}
	string GetResidenceName()
	{
		return _ResidenceName;
	}
	__declspec(property(get = GetResidenceName, put = SetResidenceName)) string ResidenceName;

    void SetResidenceDepartment(string ResidenceDepartment)
    {
        _ResidenceDepartment = ResidenceDepartment;
    }
    string GetResidenceDepartment()
    {
        return _ResidenceDepartment;
    }
    __declspec(property(get = GetResidenceDepartment, put = SetResidenceDepartment)) string ResidenceDepartment;


    static clsEmployee GetAddNewEmployeeObject(string EmployeeID)
    {
        return clsEmployee
        (
            enEmployeeMode::eAddNewMode,
            EmployeeID,
            "",
            "",
            "",
            0.0,
            "",
            enShift::eNoShift,
            enStatus::eNoStatus,
            "",
            "",
            enGender::eNoGender,
            "",
            "",
            "",
            ""
        );
    }

    static clsEmployee GetUpdateEmployeeObject()
    {
        return clsEmployee
        (
            enEmployeeMode::eUpdateMode,
            "",
            "",
            "",
            "",
            0.0,
            "",
            enShift::eNoShift,
            enStatus::eNoStatus,
            "",
            "",
            enGender::eNoGender,
            "",
            "",
            "",
            ""
        );
    }

    bool DeleteEmployee()
    {

        vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();
        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.EmployeeID == EmployeeID)
            {
                Employee._MarkForDelete = true;
                _SaveEmployeesDataToFile(vEmployees);
                return true;
            }
        }
        return false;
    }

    static clsEmployee FindEmployee(string EmployeeID)
    {
        vector<clsEmployee> vEmployees = _LoadEmployeesDataFromFile();

        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.EmployeeID == EmployeeID)
                return Employee;
        }

        return _GetEmptyEmployeeObject(); // returns empty if not found
    }


    static vector < clsEmployee> GetEmployeeListByJob(string JobTitle)
    {
        vector<clsEmployee> vEmployees = _LoadEmployeesDataFromFile();
        vector<clsEmployee>vNewEmployees ;

        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.JobTitle == JobTitle)
            {
                vNewEmployees.push_back(Employee);
            }
        }
        return vNewEmployees;
    }

    static bool IsEmployeeExist(string EmployeeID)
    {
        clsEmployee Employee = FindEmployee(EmployeeID);
        return !(Employee.IsEmpty());
    }

    bool IsEmpty()
    {
        return _Mode == enEmployeeMode::eEmptyMode;
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildEmployeeExist = 2 };

    enSaveResults Save()
    {
        switch (_Mode)
        {

        case enEmployeeMode::eEmptyMode:
            return enSaveResults::svFaildEmptyObject;

        case enEmployeeMode::eUpdateMode:
            _UpdateEmployee();
            return enSaveResults::svSucceeded;

        case enEmployeeMode::eAddNewMode:

            if (clsEmployee::IsEmployeeExist(EmployeeID))
            {
                return enSaveResults::svFaildEmployeeExist;
            }
            else
            {
                _AddNewEmployee();
                _Mode = enEmployeeMode::eUpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
    }


    static vector<clsEmployee>GetEmployeeList()
    {
        return _LoadEmployeesDataFromFile();
    }


    static void PrepareShiftScheduleRecord(clsEmployee Employee,enShift UpdatedShift,string Separator="#//#")
    {

        //EmployeeID#//#ResidenceName#//#JobTitle#//#CurrentShift#//#LastUpdateDate
        string SchedualeRecord = "";
        SchedualeRecord += Employee.EmployeeID + Separator;

        SchedualeRecord += Employee.ResidenceName+ Separator;
        SchedualeRecord += Employee.JobTitle + Separator;
        SchedualeRecord += to_string(Employee.Shift) + Separator;
        SchedualeRecord += Employee.JobTitle + Separator;




    }


    static int CountEmployeeAsStatus(enStatus Status)
    {
        vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();
        int Counter = 0;
        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.Status == Status)
            {
                Counter++;
            }
        }
        return Counter;
    }

    static double TotalMonthlyPayroll()
    {

        vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();
        double Counter = 0;
        for (clsEmployee& Employee : vEmployees)
        {
            Counter += Employee.Salary;
        }
        return Counter;

    }

    static clsEmployee HighestSalaryEmployee()
    {

        vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();
        clsEmployee HighestSalaryEmployee = vEmployees[0];

        for (clsEmployee& Employee : vEmployees)
        {

            if (Employee.Salary > HighestSalaryEmployee.Salary)
            {
                HighestSalaryEmployee = Employee;
            }
        }
        return HighestSalaryEmployee;


    }

    static clsEmployee LowestSalaryEmployee()
    {
        vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();

        clsEmployee LowestSalaryEmployee=vEmployees[0];
        for (clsEmployee& Employee : vEmployees)
        {

            if (Employee.Salary < LowestSalaryEmployee.Salary)
            {
                LowestSalaryEmployee = Employee;

            }
        }
        return LowestSalaryEmployee;
    }


    static int  CountEmployeeByShift(enShift shift)
    {

        vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();
        int Counter=0;
        for (clsEmployee& Employee : vEmployees)
        {

            if (Employee.Shift == shift)
            {
                Counter++;

            }
        }
        return Counter;
    }


    static clsEmployee SecondsSalaryEmployeePayment()
    {

        vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();
        clsEmployee FirstEmployeePayment = HighestSalaryEmployee();
        clsEmployee SecondsSalaryEmployee = vEmployees[0];
        for (clsEmployee &Employee: vEmployees)
        {   
            if (Employee.EmployeeID == FirstEmployeePayment.EmployeeID)
            {
                continue;
            }
            if (Employee.Salary > SecondsSalaryEmployee.Salary)
            {
                SecondsSalaryEmployee = Employee;
            }


        }
        return SecondsSalaryEmployee;
    }


    static clsEmployee ThirdSalaryEmployeePayment()
    {

        clsEmployee HighestPaymentEmployee = HighestSalaryEmployee();

        clsEmployee SecondsPaymentEmployee = SecondsSalaryEmployeePayment();

        vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();

        clsEmployee ThirdEmployee = vEmployees[0];
        for (clsEmployee& Employee : vEmployees)
        {
            if (Employee.EmployeeID == HighestPaymentEmployee.EmployeeID || Employee.EmployeeID == SecondsPaymentEmployee.EmployeeID)
            {
                continue;
            }
            if (Employee.Salary > ThirdEmployee.Salary)
            {

                ThirdEmployee=Employee;
            }

        }
        return ThirdEmployee;

    }


     static int  CountHiredEmployeeInCurrentMonth()
    {
        clsDate Date;
        vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();
        string Month="", Year = "";
        int Counter = 0;
        for (clsEmployee& Employee : vEmployees)
        {
            Year += Employee.HireDate[0];
            Year += Employee.HireDate[1];
            Year += Employee.HireDate[2];
            Year += Employee.HireDate[3];
            Month += Employee.HireDate[5];
            Month += Employee.HireDate[6];

            if (to_string(Date.Year) == Year && to_string(Date.Month) == Month)
            {
                Counter++;
            }
            Year = "";
            Month = "";
        }
        return  Counter;


    }


     static vector<string>ResidencesNameList()
     {

         vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();
         vector <string>vResidenceNamesList;
         for (clsEmployee& Employee : vEmployees)
         {

             if (!clsUtil::IsElementInVector<string>(Employee.ResidenceName, vResidenceNamesList)==true)
             {

                 vResidenceNamesList.push_back(Employee.ResidenceName);

             }

         }
        return vResidenceNamesList;

     }

     static int CountEmployeesByResidence(string ResidenceName)
     {

         vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();
         int Counter = 0;
         for (clsEmployee& Employee : vEmployees)
         {
             if (Employee.ResidenceName == ResidenceName)
             {
                 Counter ++;
             }
         }
         return Counter;
     }




     static vector<string>JobTitleList()
     {

         vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();
         vector <string>vList;
         for (clsEmployee& Employee : vEmployees)
         {

             if (!clsUtil::IsElementInVector<string>(Employee.JobTitle, vList) == true)
             {
                 vList.push_back(Employee.JobTitle);
             }

         }
         return vList;

     }

     static int CountEmployeesByJob(string JobTitle)
     {

         vector<clsEmployee>vEmployees = _LoadEmployeesDataFromFile();
         int Counter = 0;
         for (clsEmployee& Employee : vEmployees)
         {
             if (Employee.JobTitle == JobTitle)
             {
                 Counter++;
             }
         }
         return Counter;
     }



};

