#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsStudentDorm.h";
#include "clsInputValidate.h";


using namespace std;

class clsComplainsStudentsListScreen : protected clsBase
{

private:


    static void _PrintDormStudent(clsStudentDorm::stComplaint StudentComplain)
    {
        cout << "\n\n"<<setw(ScreenWidth) << "" << left << Green << "==========================================";
        cout << "\n"<<setw(ScreenWidth) << "" << left << Blue <<    "          Student Complain Card";
        cout << "\n"<<setw(ScreenWidth) << "" << left << Green <<   "==========================================\n" << White;
        cout << "\n"<<setw(ScreenWidth) << "" << left << " ComplaintID          : " << StudentComplain.ComplaintID ;
        cout << "\n"<<setw(ScreenWidth) << "" << left << " Student Dorm Id      : " << StudentComplain.StudentDormId;
        cout << "\n"<<setw(ScreenWidth) << "" << left << " Complaint Date       : " << StudentComplain.ComplaintDate ;
        cout << "\n"<<setw(ScreenWidth) << "" << left << " Complaint Category   : " << clsStudentDorm::GetComplainCategoriesStatusString(StudentComplain.ComplaintCategory) ;
        cout << "\n"<<setw(ScreenWidth) << "" << left << " Description          : " << StudentComplain.Description ;
        cout << "\n"<<setw(ScreenWidth) << "" << left << " Complain Status      : " << clsStudentDorm::GetStudentComplainStatusString(StudentComplain.ComplainStatus) ;
        cout << "\n"<<setw(ScreenWidth) << "" << left << " Resolved Date        : " << StudentComplain.ResolvedDate ;
        cout << "\n\n"<<setw(ScreenWidth) << "" << left << Green << "==========================================" <<endl<< White;

    }




public:


    static void ShowDormStudentComplainsList()
    {

        system("cls");
        clsBase::_DrawScreenHeader("\t    Dorm Students List Screen");

        
        if (clsInputValidate::IsSureToPerform())
        {
            system("cls");

            string Title = "\t    Dorm Students List Screen";
            vector<clsStudentDorm::stComplaint>vStudentsComplains = clsStudentDorm::GetComplaintsList();

            string SubTitle = "\t\t(" + to_string(vStudentsComplains.size()) + ") Complains";
            clsBase::_DrawScreenHeader(Title, SubTitle);

            for (clsStudentDorm::stComplaint& student : vStudentsComplains)
            {
                _PrintDormStudent(student);
            }


        }



    }









};

