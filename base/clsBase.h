#pragma once
#include<iostream>
#include <string>
#include "clsUtil.h";
#include "Global.h";
#include "clsDate.h";
#include <iomanip>;
#include "clsPerson.h";
#include "GlobalLogin.h";

using namespace std;



class clsBase 
{


protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << Green << "___________________________________________\n";
        cout << "\n" << setw(ScreenWidth) << "" << left << Red << Title;
        if (SubTitle != "")
        {
            cout << "\n" << Blue << setw(ScreenWidth) << "" << left  << SubTitle;
        }
        cout << "\n" << setw(ScreenWidth) << "" << left << Green << "___________________________________________\n" << White;
        //cout << "\n" << setw(ScreenWidth) << "" << left << "User : " << CurrentUser.UserName;
        cout << "\n" << setw(ScreenWidth) << "" << left << "\t   Today is : " << clsDate::DateToString(clsDate());
        cout << "\n" << setw(ScreenWidth) << "" << left << Green << "___________________________________________" << White << endl;

    }
    static bool _CheckAccessRights(clsLogin::enPermissions Permission)
    {

        if (!CurrentUser.IsHasPermission(Permission))
        {
            _DrawScreenHeader("Access Denied! Contact your Admin.");
            return false;

        }
        else
        {
            return true;
        }

    }


public:





};

