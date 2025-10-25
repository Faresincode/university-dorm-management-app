#pragma once
#include <iostream>
#include <iomanip>
#include "clsDate.h";
#include "clsUtil.h";
#include "Global.h";
#include "clsBase.h";
#include "clsLogin.h";
#include "clsInputValidate.h";
#include "GlobalLogin.h";
#include "clsGlobalRead.h";
#include "clsGlobalPrint.h";
#include "clsEmployee.h";

using namespace std;

class clsAddNewResponsibleScreen : protected clsBase
{

private:
    static string  ReadNewLoginUserName()
    {

        cout << "\n" << setw(ScreenWidth) << left << "" << Green << "Enter New UserName: " << White;
        string UserName=clsInputValidate::ReadString();

        while (clsLogin::IsLoginExist(UserName))
        {
            cout << setw(ScreenWidth) << left << "" << Green << Yellow << "Error! this username is already exist : try other one: " << White;
            UserName = clsInputValidate::ReadString();
  
        }
        return UserName;
    }

    static string  ReadLoginPassword()
    {

        cout << "\n" << setw(ScreenWidth) << left << "" << Green << "Enter Password: " << White;
        string Password = clsInputValidate::ReadString();
        return Password;
    }

    static short ReadPermissionsToSet()
    {

        short Permissions = 0;
        char Answer = ' ';
        cout << "\n" << setw(ScreenWidth) << left << "" << Blue << "Do you want to give him full access to system? y/n? " << White;
        
        if (clsInputValidate::IsAnswerIsYes())
        {
            return clsLogin::enPermissions::FullAccesse;
        }
        cout << "\n" << setw(ScreenWidth) << left << "" << "Do you want to give him access to: \n";

        cout << "\n" << setw(ScreenWidth) << left << "" << " Manage Student? y/n? ";
        if (clsInputValidate::IsAnswerIsYes())
        {
            Permissions += clsLogin::enPermissions::eManageStudent;
        }
       
        cout << "\n" << setw(ScreenWidth) << left << "" << " Manage Employee? y/n? ";
        if (clsInputValidate::IsAnswerIsYes())
        {
            Permissions += clsLogin::enPermissions::eManageEmployee;
        }
       
        cout << "\n" << setw(ScreenWidth) << left << "" << " Manage Finance? y/n? ";
        if (clsInputValidate::IsAnswerIsYes())
        {
            Permissions += clsLogin::enPermissions::eManageFinance;
        }
       
        cout << "\n" << setw(ScreenWidth) << left << "" << " Manage Maintenance? y/n? ";
        if (clsInputValidate::IsAnswerIsYes())
        {
            Permissions += clsLogin::enPermissions::eManageMaintenance;
        }
      
        cout << "\n" << setw(ScreenWidth) << left << "" << " Manage Rooms? y/n? ";
        if (clsInputValidate::IsAnswerIsYes())
        {
            Permissions += clsLogin::enPermissions::eManageRooms;
        }

        cout << "\n" << setw(ScreenWidth) << left << "" << " Manage Security? y/n? ";
        if (clsInputValidate::IsAnswerIsYes())
        {
            Permissions += clsLogin::enPermissions::eManageSecurity;
        }

        cout << "\n" << setw(ScreenWidth) << left << "" << " Login Register? y/n? ";
        if (clsInputValidate::IsAnswerIsYes())
        {
            Permissions += clsLogin::enPermissions::eLoginRegister;
        }
       
        cout << "\n" << setw(ScreenWidth) << left << "" << " Full Reports? y/n? ";
        if (clsInputValidate::IsAnswerIsYes())
        {
            Permissions += clsLogin::enPermissions::eFullReports;
        }
        cout << "\n" << setw(ScreenWidth) << left << "" << " Add New Responsible? y/n? ";
        if (clsInputValidate::IsAnswerIsYes())
        {
            Permissions += clsLogin::enPermissions::eAddNewResponsible;
        }
        return Permissions;
    }

    static clsLogin ReadLoginInfo()
    {
        clsLogin NewLogin = clsLogin::GetAddNewLoginObject();
        NewLogin.UserName = ReadNewLoginUserName();
        NewLogin.Password = ReadLoginPassword();
        NewLogin.Permissions = ReadPermissionsToSet();
        return NewLogin;
    }

    static clsEmployee ReadNewEmployeeInfo()
    {
        string NewEmployeeId =clsGlobalRead::GenerateNewEmployeeID();
        clsEmployee NewEmployee= clsGlobalRead::ReadFullEmployeeInfo(NewEmployeeId);
        return NewEmployee;
    }



public:

    static void ShowAddNewResponsibleScreen()
    {
        if (!clsBase::_CheckAccessRights(clsLogin::enPermissions::eAddNewResponsible))
        {
            return;
        }
        system("cls");
        clsBase::_DrawScreenHeader("\t\tAdd New Responsible Screen");
        cout << "\n" << setw(ScreenWidth) << left << "" << Blue << "Are you want add responsible in the system ? y/n? " << White;
        if (clsInputValidate::IsAnswerIsYes())
        {
            clsEmployee NewEmployee = ReadNewEmployeeInfo();
            clsLogin NewLogin = ReadLoginInfo();
            clsGlobalPrint::PrintFullDormEmployeeInfo(NewEmployee);
            clsGlobalPrint::PrintLoginInfo(NewLogin);

            cout << "\n" << setw(ScreenWidth) << left << "" << Blue << "Are you want to save this responsible in the system ? y/n? " << White;
            if (clsInputValidate::IsAnswerIsYes()==true)
            {
                clsEmployee::enSaveResults SaveEmployeeResult = NewEmployee.Save();
                clsGlobalPrint::PrintResult(SaveEmployeeResult, NewEmployee);
                clsLogin::enSaveResults SaveLoginResult= NewLogin.Save();
                clsGlobalPrint::PrintResult(SaveLoginResult, NewLogin);


            }
            else
            {
                cout << "\n" << setw(ScreenWidth) << left << "" << Yellow << "ok the responsible not save in the system " << White;

            }


        }
        else
        {
            return;
        }




    }

};
