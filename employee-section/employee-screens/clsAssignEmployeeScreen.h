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

class clsAssignEmployeeScreen : protected clsBase
{


private:

    static void AssignEmployee(clsEmployee& Employee)
    {
        clsGlobalRead::ReadDormEmployeeInfo(Employee);
        
        clsGlobalRead::ReadEmployeeInfo(Employee);


    }

    static string _ReadDormEmployeeId()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Dorm  Employee Id: ";
        string DormEmployeeId = clsInputValidate::ReadString();
        if (DormEmployeeId == "exit")
            return "exit";
        while (!clsEmployee::IsEmployeeExist(DormEmployeeId) && DormEmployeeId.length() > 6)
        {
            cout << clsUtil::Yellow() << "\n" << setw(ScreenWidth) << "" << left << "Dorm employee is Not Exist , choose another one:  " << White;
            DormEmployeeId = clsInputValidate::ReadString();
            if (DormEmployeeId == "exit")
                return "exit";
        }
        return DormEmployeeId;

    }


public:

    static void ShowAssignDormEmployeeScreen()
    {


        clsBase::_DrawScreenHeader("\t\tUpdate Dorm Student Screen\n");
        if (clsInputValidate::IsSureToPerform())
        {
            string EmployeeId = _ReadDormEmployeeId();

            clsEmployee DormEmployee = clsEmployee::FindEmployee(EmployeeId);
            clsGlobalPrint::PrintFullDormEmployeeInfo(DormEmployee);
  
            AssignEmployee(DormEmployee);


            clsEmployee::enSaveResults SaveResult = DormEmployee.Save();
            clsGlobalPrint::PrintResult(SaveResult, DormEmployee);


        }


         


    }




};

