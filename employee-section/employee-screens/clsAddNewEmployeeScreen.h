
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

class clsAddNewEmployeeScreen : protected clsBase
{

private:


    static string ReadNewDormEmployeeId()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Employee Id: ";
        string DormEmployeeId = clsInputValidate::ReadString();
        while (clsEmployee::IsEmployeeExist(DormEmployeeId) && DormEmployeeId.length() > 6)
        {
            cout << Yellow << "\n" << setw(ScreenWidth) << "" << left << "Dorm Student is is already exist , choose another one:  " << White;
            DormEmployeeId = clsInputValidate::ReadString();
        }
        return DormEmployeeId;

    }



public:



    static void ShowAddNewEmployeeScreen()
    {


        clsBase::_DrawScreenHeader("\t\tAdd New Dorm Employee Screen");
        if (clsInputValidate::IsSureToPerform())
        {

            string DormStudentId = ReadNewDormEmployeeId();


            clsEmployee NewDormEmployee = clsGlobalRead::ReadFullEmployeeInfo(DormStudentId);

            clsEmployee::enSaveResults SaveResult = NewDormEmployee.Save();
            clsGlobalPrint::PrintResult(SaveResult, NewDormEmployee);

        }


    }



};

