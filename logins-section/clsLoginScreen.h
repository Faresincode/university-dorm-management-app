
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
#include "clsAdminPanelScreen.h";
using namespace std;




class clsLoginScreen : protected clsBase
{
private:



    static string _ReadUserName()
    {
        cout << setw(ScreenWidth) << "" << left << "Enter Username? ";
        string UserName=clsInputValidate::ReadString();
        return UserName;
    }

    static string _ReadPassword()
    {
        cout << setw(ScreenWidth) << "" << left << "Enter Password? ";
        string Password=clsInputValidate::ReadString();
        return  Password;
    }

    static bool IsWantToExit(string InputToCheckIfExist)
    {
        if (InputToCheckIfExist == "exit")
        {
            system("cls");
            clsBase::_DrawScreenHeader("\tThank's for trying To Use Our App");
            return true;
        }
        return false;
    }


public:

    static bool ShowLoginScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t\t  Login Screen");
    
        bool LoginFailed = false; string Username = "", Password = ""; short FailedLoginCount = 0;
        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "To Exit enter (exit)\n\n" << White;
        do
        {
            if (LoginFailed)
            {
                FailedLoginCount++;
                cout << "\n" << setw(ScreenWidth) << "" << left << Red << "Invalid Username/Password! " << White;
                cout << "\n" << setw(ScreenWidth) << "" << left << Yellow << "You have " << (3 - FailedLoginCount) << " Trial (s) to LogIn\n" << White;
            }
            if (FailedLoginCount == 3)
            {
                cout << "\n" << setw(ScreenWidth) << "" << left << Yellow << "You are locked after 3 failed trails bey bey Koko " << White << endl;
                return false;
            }
            Username = _ReadUserName();
            if (IsWantToExit(Username))
            {
                return false;
            }

            Password = _ReadPassword();
            if (IsWantToExit(Password))
            {
                return false;
            }

            CurrentUser = clsLogin::GetLogin(Username, Password);
            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);
        clsLogin::stLoginRegister LoginRegister;
        LoginRegister.LoginDateTime = clsDate::GetSystemDateTimeString();
        LoginRegister.LogoutDateTime = "Not logout yet";
        LoginRegister.Password = CurrentUser.Password;
        LoginRegister.Username = CurrentUser.UserName;
        LoginRegister.Permissions = CurrentUser.Permissions;
        CurrentUser.SaveRegister(LoginRegister);
        clsAdminPanelScreen::ShowManageDormMenuScreen();

        return true;
    
    
    }




};




