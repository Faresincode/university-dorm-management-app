#pragma once
#include "clsUtil.h";
#include<iostream>
#include <iomanip>
#include "clsInputValidate.h";
#include "clsStudentDorm.h";
#include "clsBase.h";
#include "clsGlobalPrint.h";


class clsAddNewDormStudentScreen : protected clsBase
{
private:


    static void _ReadDormStudentInfo(clsStudentDorm& Student)
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "Read Dorm Student Info: \n" << White;

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Residence Name: ";
        Student.ResidenceName = clsInputValidate::ReadString();
        
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Dorm Building: ";
        Student.DormBuilding = clsInputValidate::ReadCharacter();
       
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Room Number: ";
        Student.RoomNumber = clsInputValidate::ReadNumber<short>();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Bed Number: ";
        Student.BedNumber = clsInputValidate::ReadNumber<short>();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Status: as following menu \n ";
        cout << "\n" << setw(ScreenWidth) << "" << left << "[ Checked_out = 1, Active = 2, Suspended = 3, Transferred = 4, Pending = 5, NoStatus = 6 ] : ";
        Student.Status = (clsStudentDorm::enStatus)clsInputValidate::ReadNumberBetween<short>(1,6);

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Meal Plan: as following [  eNoMeal = 0, eFull = 1, eBreakfast = 2, eDinner = 3 ] : ";
        Student.MealPlan = (clsStudentDorm::enMealPlan) clsInputValidate::ReadNumberBetween<short>(0,3);
        
        Student.AdmissionDate = _ReadDate("Read Admission Date : ");
        Student.CheckoutDate = _ReadDate("Read Checkout Date : ");


    }

    static string _ReadDate(string Title="Enter Date")
    {
        cout << "\n" << setw(ScreenWidth) << "" << left <<Blue<< Title<<"\n\n"<<White;
        clsDate Date;
        cout  << setw(ScreenWidth) << "" << left << "Enter Day   :";
        Date.Day = clsInputValidate::ReadNumber<short>();
        cout  << setw(ScreenWidth) << "" << left << "Enter Month : ";
        Date.Month = clsInputValidate::ReadNumber<short>();
        cout << setw(ScreenWidth) << "" << left << "Enter Year  : ";
        Date.Year = clsInputValidate::ReadNumber<short>();
        while (!clsDate::IsValidDate(Date))
        {
            cout << "\n" << setw(ScreenWidth) << "" << left<<Yellow << "Invalid Date try Again  :\n";
            cout << setw(ScreenWidth) << "" << left << "Enter Day   :";
            Date.Day = clsInputValidate::ReadNumber<short>();
            cout  << setw(ScreenWidth) << "" << left << "Enter Month : ";
            Date.Month = clsInputValidate::ReadNumber<short>();
            cout << setw(ScreenWidth) << "" << left << "Enter Year  : ";
            Date.Year = clsInputValidate::ReadNumber<short>();
        }
        return (to_string(Date.Year) + "-" + to_string(Date.Month) + "-" + to_string(Date.Day));
    }

    static clsStudentDorm::enGender _ReadDormStudentGender()
    {

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Gender: as following Menu [ Male= M or Femelle= F ]: ";
        char Gender = toupper(clsInputValidate::ReadCharacter());
        while (Gender != 'M' && Gender != 'F')
        {
            cout << "\n" << setw(ScreenWidth) << "" << left <<Yellow<< "Error! Enter Gender: as following Menu [ Male = M or  Femelle= F ]: ";
            Gender = toupper(clsInputValidate::ReadCharacter());
        }
        return (clsStudentDorm::enGender)Gender;
    }

    static void _ReadPersonalInfo(clsStudentDorm& Person)
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "Read Personal Student Info: \n" << White;

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter FirstName: ";
        Person.FirstName = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter LastName: ";
        Person.LastName = clsInputValidate::ReadString();
        Person.Gender= _ReadDormStudentGender();
        Person.DateOfBirth = _ReadDate();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Nationality: ";
        Person.Nationality = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Email: ";
        Person.Email = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Phone: ";
        Person.Phone = clsInputValidate::ReadString();

    }

    static void _ReadStudentUniversityInfo(clsStudentDorm& Student)
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "Read Student University Info: \n" << White;
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Student ID: ";
        Student.StudentID = clsInputValidate::ReadString();
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter University Name: ";
        Student.UniversityName = clsInputValidate::ReadString();
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Faculty: ";
        Student.Faculty = clsInputValidate::ReadString();
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Department: ";
        Student.Department = clsInputValidate::ReadString();
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter YearLevel: as Following menu : ";
        cout << "\n" << setw(ScreenWidth) << "" << left << "[  Bac1 = 1, Bac2 = 2, Bac3 = 3, Mst1 = 4, Mst2 = 5, Dr1 = 6, Dr2 = 7 ] : ";
        Student.YearLevel = (clsStudentDorm::enYearLevel) clsInputValidate::ReadNumberBetween(1,7);
        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Speciality: ";
        Student.Speciality = clsInputValidate::ReadString();

    }


    static string _ReadStudentDormId()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Dorm Student  id : ";
        string DormStudentId = clsInputValidate::ReadString();

        while (clsStudentDorm::IsDormStudentExist(DormStudentId))
        {
            cout << Yellow << "\n" << setw(ScreenWidth) << "" << left << "Dorm Student is exist, choose another one:  " << White;
            DormStudentId = clsInputValidate::ReadString();
        }
        return DormStudentId;

    }

    static void _ReadFullStudentInfo(clsStudentDorm &Student)
    {

        _ReadPersonalInfo(Student);
        _ReadStudentUniversityInfo(Student);
        _ReadDormStudentInfo(Student);
    }


    static void _PrintResult(clsStudentDorm NewDormStudent, clsStudentDorm::enSaveResults SaveResult)
    {

        switch (SaveResult)
        {
        case clsStudentDorm::enSaveResults::svSucceeded:
            cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Dorm Student added Successfully :-)\n" << White;
            clsGlobalPrint::PrintPersonalInfo(NewDormStudent);
            clsGlobalPrint::PrintStudentInfo(NewDormStudent);
            clsGlobalPrint::PrintDormStudent(NewDormStudent);
            break;
        case clsStudentDorm::enSaveResults::svFaildEmptyObject:
            cout << "\n" << setw(ScreenWidth) << "" << left << clsUtil::Yellow() << "Error Dorm Student was not saved because it's Empty\n" << White;
            break;
        case clsStudentDorm::enSaveResults::svFaildDormStudentExist:
            cout << "\n" << setw(ScreenWidth) << "" << left << Red << "Error Dorm student was not saved dorm Student Id is already used!\n" << White;
            break;

        }

    }

public:
    static void ShowAddNewUserScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t\tAdd New Dorm student Screen");

        if (clsInputValidate::IsSureToPerform())
        {
            string DormStudentId = _ReadStudentDormId();

            clsStudentDorm NewDormStudent = clsStudentDorm::GetAddNewStudentDormObject(DormStudentId);
            _ReadFullStudentInfo(NewDormStudent);

            clsStudentDorm::enSaveResults SaveResult = NewDormStudent.Save();
            _PrintResult(NewDormStudent, SaveResult);

        }
        


    }



};

