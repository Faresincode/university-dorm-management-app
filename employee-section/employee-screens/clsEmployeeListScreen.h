#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsEmployee.h";
#include "clsGlobalPrint.h";
using namespace std;


class clsEmployeeListScreen : protected clsBase
{


private:

    static void PrintEmployeeTable(vector <clsEmployee> vEmployees)
    {
        clsGlobalPrint::PrintEmployeeHeader();
        for (clsEmployee& Employee : vEmployees)
        {
            clsGlobalPrint::PrintEmployeeRecordLine(Employee);
            cout << endl;
        }

        cout << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________" << White << endl;


    }


public:

	static void ShowEmployeeListScreen()
	{

        system("cls");


        clsBase::_DrawScreenHeader("\t  Employee Requests List");

        if (clsInputValidate::IsSureToPerform())
        {     
            system("cls");

            vector <clsEmployee> vEmployees = clsEmployee::GetEmployeeList();
            string Subtitle = "\t\t(" + to_string(vEmployees.size()) + ") Employees";
            clsBase::_DrawScreenHeader("\t  Employee Requests List", Subtitle);


            PrintEmployeeTable(vEmployees);

        }


	}










};

