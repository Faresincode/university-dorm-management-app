#pragma once
#include<iostream>
#include <string>
#include <iomanip>
#include "clsStudentDorm.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsGlobalPrint.h";
#include "clsGlobalRead.h";
using namespace std;


class clsUpdateDormStudentScreen :protected clsBase
{
private:





    static void _ReadDormStudentInfo(clsStudentDorm& Student)
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "To skip Anything enter -> skip\n" << White;
        string StringInput = "";
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Dorm Building: ";

        if ((StringInput = clsInputValidate::ReadCharacter()) != "skip")
        {
            Student.DormBuilding = StringInput[0];
        }
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Room Number: ";
        if ((StringInput = clsInputValidate::ReadString())!= "skip")
        {
            Student.RoomNumber = stoi(StringInput);
        }
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Bed Number: ";
        if ((StringInput = clsInputValidate::ReadString()) != "skip")
        {
            Student.BedNumber = stoi(StringInput);
        }
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Status: as following menu \n ";
        cout << "\n" << setw(ScreenWidth) << "" << left << "[Checked_out = 1, Active = 2, Suspended = 3, Transferred = 4, Pending = 5, NoStatus = 6] : ";
        if ((StringInput = clsInputValidate::ReadString()) != "skip")
        {
            Student.Status = (clsStudentDorm::enStatus)stoi(StringInput);
        }
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Meal Plan: as following [  NoMeal = 0, Full = 1, Half = 2 ] : ";
        if ((StringInput = clsInputValidate::ReadString()) != "skip")
        {
            Student.MealPlan =(clsStudentDorm::enMealPlan) stoi(StringInput);
        }

    }

    enum enWhatToUpdate { eDormBuilding = 1, eRoomNumber = 2, eBedNumber = 3 ,eStatus = 4, eMealPlan = 5, eAll = 6 };

    static void _PerformUpdateMenuScreen(enWhatToUpdate WhatToUpdate, clsStudentDorm& Student)
    {

        switch (WhatToUpdate)
        {

        case enWhatToUpdate::eDormBuilding:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Dorm Building: ";
            Student.DormBuilding = clsInputValidate::ReadCharacter();
            break;
        }

        case enWhatToUpdate::eRoomNumber:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Room Number: ";
            Student.RoomNumber = clsInputValidate::ReadNumber<short>();
            break;
        }
        case enWhatToUpdate::eBedNumber:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Bed Number: ";

            Student.BedNumber = clsInputValidate::ReadNumber<short>();

            break;
        }
        case enWhatToUpdate::eStatus:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Status: as following menu ( Checked_out = 1, Active = 2, Suspended = 3, Transferred = 4, Pending = 5, NoStatus=6 )";

            Student.Status = (clsStudentDorm::enStatus)clsInputValidate::ReadNumberBetween<short>(1,6);

            break;
        }
        case enWhatToUpdate::eMealPlan:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Meal Plan: as following [  NoMeal = 0, Full = 1, Half = 2 ] ";
            Student.MealPlan = (clsStudentDorm::enMealPlan)clsInputValidate::ReadNumberBetween<short>(0,2);
            break;
        }
        case enWhatToUpdate::eAll:
        {
            _ReadDormStudentInfo(Student);

            break;
        }
        default:
        {
            _ReadDormStudentInfo(Student);
            break;
        }


        }

    }

    static void _ShowUpdateMenuScreen(clsStudentDorm& Student)
    {
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n";
        cout << setw(ScreenWidth) << "" << left << Red <<   "     Update Dorm Student Menu Screen \n";
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n" << White;
        cout << setw(ScreenWidth) << "" << left << " [1] Dorm Building       \n";
        cout << setw(ScreenWidth) << "" << left << " [2] Room Number           \n";
        cout << setw(ScreenWidth) << "" << left << " [4] Bed Number       \n";
        cout << setw(ScreenWidth) << "" << left << " [3] Status           \n";
        cout << setw(ScreenWidth) << "" << left << " [5] Meal Plan         \n";
        cout << setw(ScreenWidth) << "" << left << " [6] All Client Info \n";
        cout << setw(ScreenWidth) << "" << left << Green << "==========================================\n\n";
        
        cout << setw(ScreenWidth) << "" << left << Yellow << "What do you want to update (answer as following menu from  1 to 6 ) : " << White;
        _PerformUpdateMenuScreen((enWhatToUpdate)clsInputValidate::ReadNumberBetween<short>(1, 6), Student);
    }



public:


    static void ShowUpdateDormStudent()
    {

        system("cls");
        clsBase::_DrawScreenHeader("\t\tUpdate Dorm Student Screen\n");

        if (clsInputValidate::IsSureToPerform())
        {

            string DormStudentId = clsGlobalRead::ReadStudentDormId();

            clsStudentDorm Student = clsStudentDorm::FindByDormId(DormStudentId);
            clsGlobalPrint::PrintDormStudent(Student);
            _ShowUpdateMenuScreen(Student);

            clsStudentDorm::enSaveResults SaveResult = Student.Save();
            clsGlobalPrint::PrintResult(SaveResult, Student);
        }





    }




};

