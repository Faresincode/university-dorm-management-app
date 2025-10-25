#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsEmployeeInfo.h";
#include "clsEmployee.h";

class clsSecurity : public clsEmployee
{


private:

    enum enSecurityMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };
    enum enSecurityStatus;
    enSecurityMode _SecurityMode;    
    string _SecurityID;            
    string _AssignedBuilding;      
    enSecurityStatus _SecurityStatus;
    string _SupervisorID;
    string _LastUpdateDate;
    string _ResidenceDepartment = "Security";
    bool _MarkForDelete = false;

    static clsSecurity _ConvertSecurityLineToRecord(string Line)
    {
        vector<string> vSecurityData = clsString::Split(Line, "#//#");
        clsSecurity Security = GetUpdateSecurityObject();
        Security.SecurityID = vSecurityData[0];
        Security.EmployeeID= vSecurityData[1];
        Security.AssignedBuilding = vSecurityData[2];
        Security.SecurityStatus = (enSecurityStatus)stoi(vSecurityData[3]);
        Security.SupervisorID = vSecurityData[4];
        Security.LastUpdateDate = vSecurityData[5];
        return Security;
    }

    static string _ConvertSecurityRecordToLine(clsSecurity Security)
    {
        string Line = "";
        Line += Security.SecurityID + "#//#";
        Line += Security.EmployeeID + "#//#";
        Line += Security.AssignedBuilding + "#//#";
        Line += to_string(Security.SecurityStatus) + "#//#";
        Line += Security.SupervisorID+ "#//#" ;
        Line += Security.LastUpdateDate ;
        return Line;
    }

    static clsSecurity _GetEmptySecurityObject()
    {
        return clsSecurity(
            enSecurityMode::eEmptyMode, "", "", (enSecurityStatus)0, "",
            "", clsEmployee::enEmployeeMode::eUpdateMode, "", "", "",
            "", 0, "", (clsEmployee::enShift)0, (clsEmployee::enStatus)0, "",
            "", (clsEmployee::clsPerson::enGender)0,
            "", "", "", "");
    }

    static  vector<clsSecurity> _LoadSecuritiesDataFromFile()
    {
        vector<clsSecurity> vsSecurityEmployees;
        fstream MyFile;
        MyFile.open(SecuritiesDataFileName, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsSecurity S_Employee = _ConvertSecurityLineToRecord(Line);
                vsSecurityEmployees.push_back(S_Employee);
            }
            MyFile.close();
        }
        return vsSecurityEmployees;

 
    }


    static void _SaveSecuritiesDataToFile(vector<clsSecurity> vSecurities)
    {
        fstream MyFile;
        MyFile.open(SecuritiesDataFileName, ios::out);

        if (MyFile.is_open())
        {
            for (clsSecurity& S : vSecurities)
            {
                if (S._MarkForDelete==false)
                {

                    MyFile << _ConvertSecurityRecordToLine(S)<< endl;
                }
            }
            MyFile.close();
        }
    }

    static void _AddSecurityLineToFile(string Line)
    {
        fstream MyFile;
        MyFile.open(SecuritiesDataFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << Line << endl;
            MyFile.close();
        }
    }

    void _AddNewSecurity()
    {
        clsEmployee::_AddEmployeeLineToFile(clsEmployee::_ConvertEmployeeObjectToLine(*this));
        _AddSecurityLineToFile(_ConvertSecurityRecordToLine(*this));

    }

    bool _UpdateSecurity()
    {
        vector<clsSecurity> vSecurities = _LoadSecuritiesDataFromFile();
        vector<clsEmployee>vEmployee = clsEmployee::_LoadEmployeesDataFromFile();

        for (clsEmployee& Employee : vEmployee)
        {
            if (Employee.ResidenceDepartment == "Security")
            {
                for (clsSecurity& Security : vSecurities)
                {
                    if (Security.EmployeeID == Employee.EmployeeID)
                    {
                        Security = *this;
                        Employee = Security;
                        _SaveSecuritiesDataToFile(vSecurities);
                        clsEmployee::_SaveEmployeesDataToFile(vEmployee);
                        return true;
                    }
                }
            }
        }
        return false;

    }



public:
    enum enSecurityStatus { eActive = 1, eInactive = 2 };

    clsSecurity(enSecurityMode SecurityMode,string SecurityID,string AssignedBuilding,enSecurityStatus SecurityStatus,string LastUpdateDate,
        string SupervisorID,clsEmployee::enEmployeeMode EmployeeMode, string EmployeeId, string ResidenceName, string ResidenceDepartment,
        string JobTitle, double Salary, string HireDate, clsEmployee::enShift Shift, clsEmployee::enStatus Status, string FirstName, 
        string LastName, clsEmployee::clsPerson::enGender Gender,
        string DateOfBirth, string Nationality, string Email, string Phone)
        : clsEmployee(EmployeeMode,  EmployeeId,  ResidenceName,  ResidenceDepartment,  JobTitle,  Salary,  HireDate,  Shift,  Status,  FirstName,  LastName,  Gender,  DateOfBirth,  Nationality,  Email,  Phone)
    {
        _SecurityMode = SecurityMode;
        _SecurityID = SecurityID;
        _AssignedBuilding = AssignedBuilding;
        _SecurityStatus = SecurityStatus;
        _SupervisorID = SupervisorID;
        _LastUpdateDate = LastUpdateDate;
    }


    void SetSecurityID(string SecurityID) { _SecurityID = SecurityID; }
    string GetSecurityID() { return _SecurityID; }

    void SetAssignedBuilding(string AssignedBuilding) { _AssignedBuilding = AssignedBuilding; }
    string GetAssignedBuilding() { return _AssignedBuilding; }

    void SetSecurityStatus(enSecurityStatus SecurityStatus) { _SecurityStatus = SecurityStatus; }
    enSecurityStatus GetSecurityStatus() { return _SecurityStatus; }

    void SetSupervisorID(string SupervisorID) { _SupervisorID = SupervisorID; }
    string GetSupervisorID() { return _SupervisorID; }

    void SetLastUpdateDate(string LastUpdateDate) { _LastUpdateDate = LastUpdateDate; }
    string GetLastUpdateDate() { return _LastUpdateDate; }

    string GetResidenceDepartment()
    {
        return _ResidenceDepartment;
    }

    __declspec(property(get = GetSecurityID, put = SetSecurityID)) string SecurityID;
    __declspec(property(get = GetAssignedBuilding, put = SetAssignedBuilding)) string AssignedBuilding;
    __declspec(property(get = GetSecurityStatus, put = SetSecurityStatus)) enSecurityStatus SecurityStatus;
    __declspec(property(get = GetSupervisorID, put = SetSupervisorID)) string SupervisorID;
    __declspec(property(get = GetLastUpdateDate, put = SetLastUpdateDate)) string LastUpdateDate;


    static vector<clsSecurity> GetSecurityList()
    {
        return _LoadSecuritiesDataFromFile();
    }

    static clsSecurity GetAddNewSecurityObject(string NewEmployeeID)
    {
        return clsSecurity(
            enSecurityMode::eAddNewMode, "", "", (enSecurityStatus)0, "",
            "", clsEmployee::enEmployeeMode::eAddNewMode, "", "","",
            "", 0, "", (clsEmployee::enShift)0, (clsEmployee::enStatus )0, "",
            "", (clsEmployee::clsPerson::enGender) 0,
            "", "", "", "");

    }

    static clsSecurity GetUpdateSecurityObject()
    {
        return clsSecurity(enSecurityMode::eUpdateMode, "", "", (enSecurityStatus)0, "","", clsEmployee::enEmployeeMode::eUpdateMode, "", "", "",
            "", 0, "", (clsEmployee::enShift)0, (clsEmployee::enStatus)0, "","", (clsEmployee::clsPerson::enGender)0,"", "", "", "");
    }

    bool DeleteSecurity()
    {
        clsEmployee* EmployeeToDelete = &*this;
        EmployeeToDelete->DeleteEmployee();
        vector<clsSecurity>vSecurities = _LoadSecuritiesDataFromFile();
        for (clsSecurity& SecurityEmployee : vSecurities)
        {
            if (SecurityEmployee.EmployeeID == EmployeeID)
            {
                SecurityEmployee._MarkForDelete = true;
                _SaveSecuritiesDataToFile(vSecurities);
                return true;
            }
        }
        return false;
    }

    static void SaveEmployeeInSecurity(clsEmployee &Employee,clsSecurity &Security)
    {

        Security.HireDate = Employee.HireDate;
        Security.JobTitle = Employee.JobTitle;
        Security.Shift = Employee.Shift;
        Security.Status = Employee.Status;
        Security.Salary = Employee.Salary;
        Security.ResidenceName = Employee.ResidenceName;
        Security.ResidenceDepartment = Employee.ResidenceDepartment;
        Security.FirstName = Employee.FirstName;
        Security.LastName = Employee.LastName;
        Security.Phone = Employee.Phone;
        Security.Email = Employee.Email;
        Security.Gender = Employee.Gender;
        Security.Nationality = Employee.Nationality;
        Security.DateOfBirth = Employee.DateOfBirth;


    }

    static clsSecurity FindSecurityGuard(string EmployeeID)
    {
        vector<clsSecurity> vSecurities = _LoadSecuritiesDataFromFile();
        vector<clsEmployee>vEmployee = clsEmployee::_LoadEmployeesDataFromFile();
        
        for (clsEmployee& Employee : vEmployee)
        {
            if (Employee.ResidenceDepartment == "Security")
            {
                for (clsSecurity& Security : vSecurities)
                {
                    if (Security.EmployeeID == Employee.EmployeeID)
                    {
                        SaveEmployeeInSecurity(Employee,Security);
                        return Security;
                    }
                }
            }
        }
        return _GetEmptySecurityObject();
    }

    static bool IsSecurityExist(string EmployeeID)
    {
        clsSecurity SecurityEmployee = FindSecurityGuard(EmployeeID);
        return !(SecurityEmployee.IsEmpty());
    }

    static clsSecurity FindBySecurityId(string SecurityId)
    {
        vector<clsSecurity> vSecurities = _LoadSecuritiesDataFromFile();
        for (clsSecurity& Security : vSecurities)
        {
            if (Security.SecurityID == SecurityId)
                return Security;
        }

        return _GetEmptySecurityObject();
    }

    static bool IsSecurityExistBySecurityId(string SecurityId)
    {
        clsSecurity SecurityEmployee = FindBySecurityId(SecurityId);
        return !(SecurityEmployee.IsEmpty());
    }

    bool IsEmpty()
    {
        return _SecurityMode == enSecurityMode::eEmptyMode;
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildSecurityExist = 2 };

    enSaveResults SaveSecurityGuard()
    {
        switch (_Mode)
        {

        case enSecurityMode::eEmptyMode:
            return enSaveResults::svFaildEmptyObject;

        case enSecurityMode::eUpdateMode:
            _UpdateSecurity();
            return enSaveResults::svSucceeded;

        case enSecurityMode::eAddNewMode:

            if (clsSecurity::IsSecurityExist(EmployeeID))
            {
                return enSaveResults::svFaildSecurityExist;
            }
            else
            {
                _AddNewSecurity();
                _SecurityMode = enSecurityMode::eUpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
    }

    static int CountSecuritiesAsStatus(enSecurityStatus SecurityStatus)
    {
        vector<clsSecurity>vSecurityEmployees = _LoadSecuritiesDataFromFile();
        int Counter = 0;
        for (clsSecurity& SecurityEmployee : vSecurityEmployees)
        {
            if (SecurityEmployee.SecurityStatus == SecurityStatus)
            {
                Counter++;
            }
        }
        return Counter;
    }

    static string SecurityStatusString(enSecurityStatus SecurityStatus)
    {
        switch (SecurityStatus)
        {
        case clsSecurity::eActive:
            return "Active";
        case clsSecurity::eInactive:
            return "Inactive";
        default:
            return "No S.Status";
        }


    }







};

