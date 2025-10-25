#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsStudentDorm.h";


using namespace std;

class clsDormStudentsListScreen : protected clsBase
{

private:


    static void _PrintClientRecordLine(clsStudentDorm Student)
    {

        cout << setw(2) << left << "" << Green << "| " << White << setw(12) << left << Student.StudentDormId;
        cout<<  Green << "| " << White << setw(12) << left << Student.StudentID;
        cout << Green << "| " << White << setw(25) << left << Student.FullName();
        cout << Green << "| " << White << setw(8)  << left << char(Student.Gender);
        cout << Green << "| " << White << setw(40) << left << Student.ResidenceName;
        cout << Green << "| " << White << setw(12)  << left << Student.DormBuilding;
        cout << Green << "| " << White << setw(9)  << left << Student.RoomNumber;
        cout << Green << "| " << White << setw(12) << left << clsStudentDorm::GetStatusString(Student.Status);


    }

    static void _PrintClientHeader()
    {

        cout << "\n" << setw(1) << left<<"" << Green << "___________________________________________________________________________________________________________________________________________________\n\n" << White;

        cout << setw(2) << left << "" << Green << "| " << White << left << setw(12) << "Dorm St Id";
        cout << Green << "| " << White << left << setw(12) << "Student ID";
        cout << Green << "| " << White << left << setw(25) << "Full Name";
        cout << Green << "| " << White << left << setw(8) << "Gender";
        cout << Green << "| " << White << left << setw(40) << "Residence Name";
        cout << Green << "| " << White << left << setw(12) << "Dorm Bld";
        cout << Green << "| " << White << left << setw(9) << "Room Num";
        cout << Green << "| " << White << left << setw(12) << "Status";
        cout << "\n" << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________\n\n" << White;

    }
	



public:


	static void ShowDormStudentsList()
	{
        system("cls");

		string Title = "\tDorm Students List Screen";
        clsBase::_DrawScreenHeader(Title);

        if (clsInputValidate::IsSureToPerform())
        {
            system("cls");

		    vector<clsStudentDorm>vStudents = clsStudentDorm::GetStudentsDormList();

		    string SubTitle = "\t\t (" + to_string(vStudents.size()) + ") Dorm Students";
		    clsBase::_DrawScreenHeader(Title, SubTitle);

            _PrintClientHeader();
		    for (clsStudentDorm &student:vStudents)
		    {
                _PrintClientRecordLine(student);
                cout << endl;
		    }


            cout  << setw(1) << left << "" << Green << "___________________________________________________________________________________________________________________________________________________" <<White<< endl;



        }

	}




};

