#pragma once

#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsEmployee.h";
#include "clsGlobalPrint.h";

using namespace std;



class clsDeleteEmployeeScreen : protected clsBase
{


private:

    static void _PrintSpecificEmployeeRecordLine(clsEmployee Employee)
    {

        cout << setw(ScreenWidth-10) << left << "" << Green << "| " << White << setw(15) << left << Employee.EmployeeID;
        cout << Green << "| " << White << setw(25) << left << Employee.FullName();
        cout << Green << "| " << White << setw(20) << left << Employee.JobTitle << White;


    }

    static void _PrintSpecificEmployeeHeader()
    {

        cout << "\n" << setw(ScreenWidth-10) << left << "" <<Green<< "----------------------------------------------------------------------\n"<<White;
        cout << setw(ScreenWidth-10) << left << "" << Green << "| " << Yellow << setw(15) << left << "Employee ID";
        cout << Green << "| " << Yellow << setw(25) << left << "Full Name" << White;
        cout << Green << "| " << Yellow << setw(20) << left << "Job Title" << White;
        cout << "\n" << setw(ScreenWidth-10) << left <<"" << Green << "----------------------------------------------------------------------\n" << White;
    }


    static void _PrintSmallEmployeeListInfo()
    {
        vector<clsEmployee>vEmployee = clsEmployee::GetEmployeeList();

        if (vEmployee.size() == 0)
        {
            cout << setw(ScreenWidth) << "" << left << Red << "No Employee Available In the System!\n" << White;
        }
        else
        {
            _PrintSpecificEmployeeHeader();
            for (clsEmployee& student : vEmployee)
            {
                _PrintSpecificEmployeeRecordLine(student);
                cout << endl;
            }
            cout << setw(ScreenWidth-10) << left << ""<<Green<< "----------------------------------------------------------------------"<<White<<endl;
        }
    }

    static string ReadEmployeeDormIdToDelete()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Dorm Student Id that you want to delete: ";
        string DormEmployeeId = clsInputValidate::ReadString();

        if (DormEmployeeId == "exit")
            return "exit";
        while (!clsEmployee::IsEmployeeExist(DormEmployeeId))
        {
            cout << clsUtil::Yellow() << "\n" << setw(ScreenWidth) << "" << left << "Dorm Student is not found, choose another one:  " << White;
            DormEmployeeId = clsInputValidate::ReadString();
            if (DormEmployeeId == "exit")
                return "exit";
        }
        return DormEmployeeId;

    }


public:

    static void ShowDeleteDormEmployee()
    {


        string Title = "\t\tDelete Employee Student Screen\n";
        clsBase::_DrawScreenHeader(Title);
        if (clsInputValidate::IsSureToPerform())
        {
            _PrintSmallEmployeeListInfo();

            string DormEmployeeId = ReadEmployeeDormIdToDelete();

            clsEmployee DormStudentToDelete = clsEmployee::FindEmployee(DormEmployeeId);
            clsGlobalPrint::PrintPersonalInfo(DormStudentToDelete);
            clsGlobalPrint::PrintEmployeeInfo(DormStudentToDelete);
            clsGlobalPrint::PrintResidenceEmployeeInfo(DormStudentToDelete);

            cout << "\n" << setw(ScreenWidth) << "" << left << "Are you sure you want to delete the Dorm Employee From Dorm Definitely answer [Y/N]: ";
            if (clsInputValidate::IsAnswerIsYes())
            {
                if (DormStudentToDelete.DeleteEmployee())
                {
                    cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Employee Deleted Successfully :-)\n"<<White;
                }
                else
                {
                    cout << Red << "\n" << setw(ScreenWidth) << "" << left << "\nError Employee Was not Deleted\n"<< White << endl;
                }
            
            }


        }


    }






};

