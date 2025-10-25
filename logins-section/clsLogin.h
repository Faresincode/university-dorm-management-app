
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"
#include "Global.h";
#include "GlobalLogin.h";
using namespace std;

class clsLogin
{
private:



    struct stLoginRegister;
    enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };

    enMode _Mode;
    string _Username;
    string _Password;
    short _Permissions; 
    bool _MarkForDelete = false;

    static clsLogin _ConvertLineToLoginObject(string Line, string Separator = "#//#")
    {
        vector<string> vLoginData = clsString::Split(Line, Separator);
        return clsLogin(enMode::eUpdateMode, vLoginData[0],clsUtil::DecryptText (vLoginData[1]), stoi(vLoginData[2]));
    }

    static clsLogin::stLoginRegister _PrepareLogRegisterStructObject(string Line, string Separator = "#//#")
    {
        vector<string> vLoginData = clsString::Split(Line, Separator);
        clsLogin::stLoginRegister RegisterLogin;
        RegisterLogin.LoginDateTime = vLoginData[0];
        RegisterLogin.Username = vLoginData[1];
        RegisterLogin.Password = clsUtil::DecryptText( vLoginData[2]);
        RegisterLogin.Permissions = stoi(vLoginData[3]);
        RegisterLogin.LogoutDateTime = vLoginData[4];
        return RegisterLogin;
    }

    static string _PrepareLogRegisterLine(clsLogin::stLoginRegister LoginRegister, string Separator = "#//#")
    {
        string Line = "";
        Line += LoginRegister.LoginDateTime + Separator;
        Line += LoginRegister.Username + Separator;
        Line += clsUtil::EncryptText(LoginRegister.Password) + Separator;
        Line += to_string(LoginRegister.Permissions) + Separator;
        Line += LoginRegister.LogoutDateTime;

        return Line;
    }


    static string _ConvertLoginObjectToLine(clsLogin Login, string Separator = "#//#")
    {
        string Line = "";
        Line += Login.UserName + Separator;
        Line +=clsUtil::EncryptText (Login.Password) + Separator;
        Line += to_string(Login.Permissions);
        return Line;
    }

    static vector<clsLogin> _LoadLoginsDataFromFile()
    {
        vector<clsLogin> vLogins;
        fstream File;
        File.open(LoginFileName, ios::in);

        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                if (Line != "")
                {
                    vLogins.push_back(_ConvertLineToLoginObject(Line));

                }
            }
            File.close();
        }
        return vLogins;
    }

    static vector<clsLogin::stLoginRegister> _LoadLogRegisterDataFromFile()
    {
        vector<clsLogin::stLoginRegister> vLogins;
        fstream File( RegisterLoginsDataFileName, ios::in);

        if (File.is_open())
        {
            string Line;
            while (getline(File, Line))
            {
                if (Line != "")
                    vLogins.push_back(_PrepareLogRegisterStructObject(Line));
            }
            File.close();
        }
        return vLogins;
    }


    static void _SaveLoginsDataToFile(vector<clsLogin> vLogins)
    {
        fstream File(LoginFileName, ios::out);
        if (File.is_open())
        {
            for (clsLogin& L : vLogins)
            {
                if (L._MarkForDelete == false)
                {
                    File << _ConvertLoginObjectToLine(L) << endl;

                }
            }
            File.close();
        }
    }

    static clsLogin _GetEmptyLoginObject()
    {
        return clsLogin(enMode::eEmptyMode, "", "", 0);
    }


    static void _AddNewUserToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open(LoginFileName, ios::out | ios::app);
        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    void _AddNewUser()
    {
        _AddNewUserToFile(_ConvertLoginObjectToLine(*this));

    }

    void _UpdateUser()
    {
        vector<clsLogin> vLogins = _LoadLoginsDataFromFile();
        for (clsLogin& Log : vLogins)
        {
            if (Log._Username == _Username)
            {
                Log = *this;
                break;
            }
        }

    }


public:

    enum enPermissions
    {
        eManageStudent = 1,
        eManageFinance = 2,
        eManageSecurity = 4,
        eManageEmployee = 8,
        eManageMaintenance = 16,
        eManageRooms = 32,
        eFullReports = 64,
        eLoginRegister=128,
        eAddNewResponsible=256,
        FullAccesse=-1
    };
    
    struct stLoginRegister
    {
        string LoginDateTime;
        string Username;
        string Password;
        short Permissions;
        string LogoutDateTime;

    };

    static clsLogin GetAddNewLoginObject()
    {
        return clsLogin(enMode::eAddNewMode, "", "", 0);
    }
    static clsLogin GetUpdateLoginObject()
    {
        return clsLogin(enMode::eUpdateMode, "", "", 0);
    }
    clsLogin(enMode Mode, string Username, string Password, short Permissions)
    {
        _Mode = Mode;
        _Username = Username;
        _Password = Password;
        _Permissions = Permissions;
    }

    void SetUserName(string UserName)
    {
        _Username = UserName;
    }
    void SetPassword(string Password)
    {
        _Password = Password;
    }
    void SetPermission(short Permissions)
    {
        _Permissions = Permissions;
    }

    string GetUsername() const 
    {
        return _Username; 
    }
    string GetPassword()  const
    {
        return _Password; 
    }
    short GetPermissions() const 
    {
        return _Permissions; 
    }

    __declspec(property(get = GetUsername, put = SetUserName))string UserName;
    __declspec(property(get = GetPassword, put = SetPassword))string Password;
    __declspec(property(get = GetPermissions, put = SetPermission))short Permissions;


    // ===== Static Functionalities =====

    bool IsEmpty()
    {
        return _Mode == enMode::eEmptyMode;
    }

    static clsLogin Find(string Username)
    {
        vector<clsLogin> vLogins = _LoadLoginsDataFromFile();
        for (clsLogin& Log : vLogins)
        {
            if (Log.UserName == Username)
                return Log;
        }
        return _GetEmptyLoginObject();
    }

    static bool IsLoginExist(string Username)
    {
        clsLogin Log = Find(Username);
        return !(Log.IsEmpty());
    }

    static bool ValidateLogin(string Username, string Password)
    {
        vector<clsLogin> vLogins = _LoadLoginsDataFromFile();
        for (clsLogin& Log : vLogins)
        {
            if (Log.UserName == Username && Log.Password == Password)
                return true;
        }
        return false;
    }

    static clsLogin GetLogin(string Username, string Password)
    {
        vector<clsLogin> vLogins = _LoadLoginsDataFromFile();
        for (clsLogin& Log : vLogins)
        {
            if (Log.UserName == Username && Log.Password == Password)
            {
                return Log;

            }
        }
        return _GetEmptyLoginObject();
    }

    bool IsHasPermission(enPermissions PermissionToCheck)
    {
        if (PermissionToCheck == enPermissions::FullAccesse)
        {
            return true;
        }
        if ((PermissionToCheck & Permissions) == PermissionToCheck)
            return true;
        else
            return false;
        
    }

    static void SaveRegister(stLoginRegister LoginRegister)
    {
        clsUtil::AddDataLineToFile(_PrepareLogRegisterLine(LoginRegister), RegisterLoginsDataFileName);
    }

    enum enSaveResults { svFailEmpty = 0, svSuccess = 1, svFailUsernameExists = 2 };

    static vector<clsLogin::stLoginRegister>GetRegisterLoginsList()
    {
        return _LoadLogRegisterDataFromFile();
    }

    enSaveResults Save()
    {
        switch (_Mode)
        {

        case enMode::eEmptyMode:
            return enSaveResults::svFailEmpty;

        case enMode::eUpdateMode:
            _UpdateUser();
            return enSaveResults::svSuccess;

        case enMode::eAddNewMode:

            if (clsLogin::IsLoginExist(UserName))
            {
                return enSaveResults::svFailUsernameExists;
            }
            else
            {
                _AddNewUser();
                _Mode = enMode::eUpdateMode;
                return enSaveResults::svSuccess;
            }
        }
        return svSuccess;
    }

    bool Delete()
    {
        vector<clsLogin> vLogins = _LoadLoginsDataFromFile();
        for (clsLogin& Log : vLogins)
        {

            if (Log.UserName == UserName)
            {
                Log._MarkForDelete = true;
                _SaveLoginsDataToFile(vLogins);
                return true;
            }
        }
        return false;
    }

    static vector<clsLogin> GetLoginsList()
    {
        return _LoadLoginsDataFromFile();
    }

    static void SaveLogRegistersDataToFile(vector<clsLogin::stLoginRegister> vLoginsRegister)
    {
        fstream File;
        File.open(RegisterLoginsDataFileName, ios::out);
        if (File.is_open())
        {
            for (clsLogin::stLoginRegister& L : vLoginsRegister)
            {

                File << _PrepareLogRegisterLine(L) << endl;
            }
            File.close();
        }
    }





};
