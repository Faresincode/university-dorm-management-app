#pragma once
#include<iostream>
#include <string>
#include <iomanip>
#include "clsStudentDorm.h";
#include "clsBase.h";
#include "clsInputValidate.h";
using namespace std;

class clsDeleteDormStudentScreen :protected clsBase
{

private:



    static void _PrintSpecificClientRecordLine(clsStudentDorm Student)
    {

        cout << setw(ScreenWidth) << left << "" << Green << "| " << White << setw(15) << left << Student.StudentDormId;
        cout << Green << "| " << White << setw(23) << left << Student.FullName() << Green << "|" << White;

    }

    static void _PrintSpecificClientHeader()
    {

        cout << Green;
        cout << "\n" << setw(ScreenWidth) << left << "" << "___________________________________________\n\n";
        cout << White;

        cout << setw(ScreenWidth) << left << "" << Green << "| " << White << left << setw(15) << "Student Dorm Id";
        cout << Green << "| " << White << left << setw(23) << "Student Full Name" << Green << "|" << White;
        cout << Green;
        cout << "\n" << setw(ScreenWidth) << left << "" << "___________________________________________\n";
        cout << White;
    }

    static void _PrintDormStudent(clsStudentDorm Student)
    {
        cout << "\n";
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n";
        cout << setw(ScreenWidth) << "" << left << Blue << "\t\tClient Card : \n";
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n" << White;
        cout << setw(ScreenWidth) << "" << left << " Student Dorm Id   : " << Student.StudentDormId << "\n";
        cout << setw(ScreenWidth) << "" << left << " Student ID        : " << Student.StudentID << "\n";
        cout << setw(ScreenWidth) << "" << left << " Full Name         : " << Student.FullName() << "\n";
        cout << setw(ScreenWidth) << "" << left << " Gender            : " << char(Student.Gender) << "\n";
        cout << setw(ScreenWidth) << "" << left << " Residence Name    : " << Student.ResidenceName << "\n";
        cout << setw(ScreenWidth) << "" << left << " Dorm Building     : " << Student.DormBuilding << "\n";
        cout << setw(ScreenWidth) << "" << left << " RoomNumber        : " << Student.RoomNumber << "\n";
        cout << setw(ScreenWidth) << "" << left << " AdmissionDate     : " << Student.AdmissionDate << "\n";
        cout << setw(ScreenWidth) << "" << left << " Status            : " << clsStudentDorm::GetStatusString(Student.Status) << "\n";

        cout << setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
        cout << endl;

    }

    static void _PrintSmallClientsListInfo()
    {
        vector<clsStudentDorm>vStudents = clsStudentDorm::GetStudentsDormList();

        if (vStudents.size() == 0)
        {
            cout << setw(ScreenWidth) << "" << left << Red << "No Clients Available In the System!\n" << White;
        }
        else
        {
            _PrintSpecificClientHeader();
            for (clsStudentDorm& student : vStudents)
            {
                _PrintSpecificClientRecordLine(student);
                cout << endl;
            }
            cout << Green;
            cout << setw(ScreenWidth) << left << "" << "___________________________________________";
            cout << White;
            cout << endl;
        }
    }

    static string ReadStudentDormIdToDelete()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Dorm Student Id that you want to delete: ";
        string DormStudentId = clsInputValidate::ReadString();

        while (!clsStudentDorm::IsDormStudentExist(DormStudentId))
        {
            cout << clsUtil::Yellow() << "\n" << setw(ScreenWidth) << "" << left << "Dorm Student is not found, choose another one:  " << White;
            DormStudentId = clsInputValidate::ReadString();

        }
        return DormStudentId;

    }


public:

    static void ShowDeleteDormStudent()
    {
        system("cls");

        clsBase::_DrawScreenHeader("\t\tDelete dorm Student Screen\n");

        if (clsInputValidate::IsSureToPerform())
        {

            _PrintSmallClientsListInfo();

            string DormStudentId = ReadStudentDormIdToDelete();

            clsStudentDorm DormStudentToDelete = clsStudentDorm::FindByDormId(DormStudentId);
            _PrintDormStudent(DormStudentToDelete);

            cout << "\n" << setw(ScreenWidth) << "" << left << "Are you sure you want to delete the Student From Dorm Definitely answer [Y/N]: ";
            if (clsInputValidate::IsAnswerIsYes())
            {
                if (DormStudentToDelete.Delete())
                {
                    cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Student Deleted Successfully :-)\n";
                }
                else
                {
                    cout << Red << "\n" << setw(ScreenWidth) << "" << left << "\nError Student Was not Deleted\n";
                }
                cout << White << endl;
            }
        }

    }




};

