#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsStudentDorm.h";


using namespace std;

class clsFindDormStudentScreen :protected clsBase
{

private:
    static void _PrintDormStudent(clsStudentDorm Student)
    {
        cout << "\n";
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n";
        cout << setw(ScreenWidth) << "" << left << Blue <<  "              Client Card : \n";
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n" << White;
        cout << setw(ScreenWidth) << "" << left << " Student Dorm Id   : " << Student.StudentDormId << "\n";
        cout << setw(ScreenWidth) << "" << left << " Student ID        : " << Student.StudentID << "\n";
        cout << setw(ScreenWidth) << "" << left << " Full Name         : " << Student.FullName() << "\n";
        cout << setw(ScreenWidth) << "" << left << " Gender            : " << char(Student.Gender) << "\n";
        cout << setw(ScreenWidth) << "" << left << " Residence Name    : " << Student.ResidenceName << "\n";
        cout << setw(ScreenWidth) << "" << left << " Dorm Building     : " << Student.DormBuilding << "\n";
        cout << setw(ScreenWidth) << "" << left << " RoomNumber        : " << Student.RoomNumber<< "\n";
        cout << setw(ScreenWidth) << "" << left << " AdmissionDate     : " << Student.AdmissionDate << "\n";
        cout << setw(ScreenWidth) << "" << left << " Status            : " << clsStudentDorm::GetStatusString(Student.Status) << "\n";

        cout << setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
        cout << endl;

    }

    static string ReadStudentDormId()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Student Dorm id : ";
        string DormStudentId = clsInputValidate::ReadString();

        while (!clsStudentDorm::IsDormStudentExist(DormStudentId))
        {
            cout << Yellow<< "\n" << setw(ScreenWidth) << "" << left << "Dorm Student is not found, choose another one:  " << White;
            DormStudentId = clsInputValidate::ReadString();

        }
        return DormStudentId;

    }
public:


    static void FindDormStudentScreen()
    {

        system("cls");
        _DrawScreenHeader("\t\tFind Client Screen");
        if (clsInputValidate::IsSureToPerform())
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Student Dorm Id: ";
            string StudentDormId = ReadStudentDormId();

            clsStudentDorm Client = clsStudentDorm::FindByDormId(StudentDormId);
            if (!Client.IsEmpty())
            {
                cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Object Found :-)\n"<<White;
                _PrintDormStudent(Client);
            }
            else
            {
                cout << "\n" << setw(ScreenWidth) << "" << left << Red << "Student Was not Found :-(\n" << White;
            }

        }


    }




};

