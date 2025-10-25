#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsStudentDorm.h";
#include "clsInputValidate.h";


using namespace std;

class clsRecordComplainScreen : protected clsBase
{

private:


    static clsStudentDorm::stComplaint  ReadComplain(clsStudentDorm & StudentDorm)
    {

        cout << "\n" << setw(ScreenWidth) << "" << left << Blue<<"Read Complaint"<<White;
        clsStudentDorm::stComplaint  Complain;
        Complain.StudentDormId = StudentDorm.StudentDormId;
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Complain Categories: as Following Menu: ";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [ eMaintenance = 1, eCleanliness = 2, eNoise = 3, eFood = 4, eSecurity = 5, eOther = 6 ] : ";
        Complain.ComplaintCategory =(clsStudentDorm::enComplaintCategory) clsInputValidate::ReadNumberBetween(1,6);
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Complain Description: ";
        Complain.Description = clsInputValidate::ReadString();
        Complain.ComplainStatus = clsStudentDorm::enComplainStatus::eInProgress;
        Complain.ComplaintDate = "Not Yet";
        return Complain;
    }

    static string ReadStudentDormId()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Student Dorm: ";
        string DormStudentId = clsInputValidate::ReadString();

        if (DormStudentId == "exit")
            return "exit";
        while (!clsStudentDorm::IsDormStudentExist(DormStudentId))
        {
            cout << clsUtil::Yellow() << "\n" << setw(ScreenWidth) << "" << left << "Dorm Student is not found, choose another one:  " << White;
            DormStudentId = clsInputValidate::ReadString();
            if (DormStudentId == "exit")
                return "exit";
        }
        return DormStudentId;

    }

    static void _PrintDormStudent(clsStudentDorm Student)
    {
        cout << "\n";
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n";
        cout << setw(ScreenWidth) << "" << left << Blue << "\t\tDorm Student Info : \n";
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


public:


    static void RecordDormStudentComplaint()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t  Record Dorm Student Complaint");
        if (clsInputValidate::IsSureToPerform())
        {
            string StudentDormId = ReadStudentDormId();

            clsStudentDorm DormStudent=  clsStudentDorm::FindByDormId(StudentDormId);
            _PrintDormStudent(DormStudent);

            cout << "\n" << setw(ScreenWidth) << "" << left << "Are you sure to perform this operation. Answer with Y/N? : ";
            if (clsInputValidate::IsAnswerIsYes())
            {
                clsStudentDorm::stComplaint  Complain;
                Complain=ReadComplain(DormStudent);
                clsStudentDorm::RecordComplaint(Complain);

            }

        }












    }





};

