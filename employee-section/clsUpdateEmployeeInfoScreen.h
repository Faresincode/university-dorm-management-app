#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsEmployee.h";
#include "clsGlobalPrint.h";
#include "clsGlobalRead.h";

using namespace std;

class clsUpdateEmployeeInfoScreen : protected clsBase
{

private:
    friend class clsUpdateSecurityInfoScreen;

    static string ReadDormEmployeeId()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Dorm  Employee Id: ";
        string DormEmployeeId = clsInputValidate::ReadString();
        if (DormEmployeeId == "exit")
            return "exit";
        while (!clsEmployee::IsEmployeeExist(DormEmployeeId) && DormEmployeeId.length() > 6)
        {
            cout << Yellow << "\n" << setw(ScreenWidth) << "" << left << "Dorm employee is Not Exist , choose another one:  " << White;
            DormEmployeeId = clsInputValidate::ReadString();
            if (DormEmployeeId == "exit")
                return "exit";
        }
        return DormEmployeeId;

    }

    enum enWhatToUpdate { eResidanceName = 1, eResidenceDepartment = 2, eJobTitle = 3, eSalary = 4, eShift = 5, eStatus = 6 ,eAll=7};

    static void _PerformUpdateMenuScreen(enWhatToUpdate WhatToUpdate, clsEmployee& Employee)
    {

        switch (WhatToUpdate)
        {

        case enWhatToUpdate::eResidanceName:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Residence Name: ";
            Employee.ResidenceName = clsInputValidate::ReadString();
            break;
        }

        case enWhatToUpdate::eResidenceDepartment:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Residence Department: ";
            Employee.ResidenceDepartment = clsInputValidate::ReadString();
            break;
        }
        case enWhatToUpdate::eJobTitle:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Job Title: ";
            Employee.JobTitle = clsInputValidate::ReadString();

            break;
        }
        case enWhatToUpdate::eSalary:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Salary: ";
            Employee.Salary = clsInputValidate::ReadNumber<double>();

            break;
        }
        case enWhatToUpdate::eShift:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Status: as following menu:";
            cout << "\n" << setw(ScreenWidth) << "" << left << "[Checked_out = 1, Active = 2, Suspended = 3, Transferred = 4, Pending = 5, NoStatus = 6] : ";
            Employee.Salary = (clsEmployee::enStatus)clsInputValidate::ReadNumber<short>();

            break;
        }
        case enWhatToUpdate::eStatus:
        {

            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter worker status : as following Menu:";
            cout << "\n" << setw(ScreenWidth) << "" << left << "[ Active = 1, Suspended = 2, Resigned = 3 , NoStatus=0 ] : ";
            Employee.Status = (clsEmployee::enStatus)clsInputValidate::ReadNumberBetween(0, 3);
            break;
        }
        case enWhatToUpdate::eAll:
            clsGlobalRead::ReadDormEmployeeInfo(Employee);
            break;
        default:
        {
            clsGlobalRead::ReadDormEmployeeInfo(Employee);
            break;
        }


        }

    }

    static void _ShowUpdateMenuScreen(clsEmployee& Employee)
    {
        cout <<"\n"<< setw(ScreenWidth) << "" << left << Green << "==========================================";
        cout <<"\n"<< setw(ScreenWidth) << "" << left << Red <<   "    Update Dorm Employee Menu Screen";
        cout <<"\n"<< setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
        cout <<"\n"<< setw(ScreenWidth) << "" << left << " [1] Residance Name";
        cout <<"\n"<< setw(ScreenWidth) << "" << left << " [2] Residence Department";
        cout <<"\n"<< setw(ScreenWidth) << "" << left << " [3] Job Title";
        cout <<"\n"<< setw(ScreenWidth) << "" << left << " [4] Salary";
        cout <<"\n"<< setw(ScreenWidth) << "" << left << " [5] Shift";
        cout <<"\n"<< setw(ScreenWidth) << "" << left << " [6] Status";
        cout <<"\n"<< setw(ScreenWidth) << "" << left << " [7] Update All";
        cout <<"\n"<< setw(ScreenWidth) << "" << left << Green << "==========================================\n\n";

        cout << setw(ScreenWidth) << "" << left << Yellow << "What do you want to update (answer as following menu from  1 to 7 ) : " << White;
        _PerformUpdateMenuScreen((enWhatToUpdate)clsInputValidate::ReadNumberBetween<short>(1, 7), Employee);
    }





public:

    static void ShowUpdateDormEmployeeScreen()
    {

        system("cls");
        clsBase::_DrawScreenHeader("\t\tUpdate Dorm Student Screen\n");

        if (clsInputValidate::IsSureToPerform())
        {

            string EmployeeId = ReadDormEmployeeId();
      
            clsEmployee DormEmployee = clsEmployee::FindEmployee(EmployeeId);

            clsGlobalPrint::PrintFullDormEmployeeInfo(DormEmployee);
            _ShowUpdateMenuScreen(DormEmployee);

            clsEmployee::enSaveResults SaveResult = DormEmployee.Save();
            clsGlobalPrint::PrintResult(SaveResult, DormEmployee);
        }




    }



};

