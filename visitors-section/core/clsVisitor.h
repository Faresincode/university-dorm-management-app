#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsEmployeeInfo.h"
#include "clsEmployee.h"
#include <string>

using namespace std;

class clsVisitor : public clsBase
{
private:

    enum enVisitorMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };
    enum enVisitorStatus;

    enVisitorMode _VisitorMode;
    string _VisitorID;
    string _FirstName;
    string _LastName;
    string _VisitPurpose;
    string _VisitedDepartment;
    string _VisitedRoom;
    string _VisitDateTime;
    string _ExitDateTime;
    enVisitorStatus _VisitorStatus;
    bool _MarkForDelete = false;
    string _SecurityID;


    // Helper to convert a line from file to a clsVisitor object
    static clsVisitor _ConvertVisitorLineToRecord(string Line)
    {
        vector<string> vVisitorData = clsString::Split(Line, "#//#");

        return clsVisitor(
            eUpdateMode,
            vVisitorData[0], // VisitorID
            vVisitorData[1], // FirstName
            vVisitorData[2], // LastName
            vVisitorData[3], // VisitPurpose
            vVisitorData[4], // VisitedDepartment
            vVisitorData[5], // VisitedRoom
            vVisitorData[6],     //security Guard Id,
            (enVisitorStatus)stoi(vVisitorData[7]), // Status
            vVisitorData[8], // Visit Date
            vVisitorData[9] //exit Date
            );
    }

    // Helper to convert a clsVisitor object to a line to save in file
    static string _ConvertVisitorRecordToLine(clsVisitor Visitor)
    {
        string Line = "";
        Line += Visitor.VisitorID + "#//#";
        Line += Visitor.FirstName + "#//#";
        Line += Visitor.LastName + "#//#";
        Line += Visitor.VisitPurpose + "#//#";
        Line += Visitor.VisitedDepartment + "#//#";
        Line += Visitor.VisitedRoom + "#//#";
        Line += Visitor.SecurityID + "#//#";
        Line += to_string(Visitor.VisitorStatus)+ "#//#";
        Line += Visitor.VisitDateTime+ "#//#" ;
        Line += Visitor.ExitDateTime ;

        return Line;
    }

    static clsVisitor _GetEmptyVisitorObject()
    {
        return clsVisitor(eEmptyMode, "", "", "", "", "", "", "", (enVisitorStatus)0,"","");
    }

    static vector<clsVisitor> _LoadVisitorsDataFromFile()
    {
        vector<clsVisitor> vVisitors;
        fstream MyFile(VisitorsDataFileName, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                vVisitors.push_back(_ConvertVisitorLineToRecord(Line));
            }
            MyFile.close();
        }
        return vVisitors;
    }

    static void _SaveVisitorsDataToFile(vector<clsVisitor> vVisitors)
    {
        fstream MyFile(VisitorsDataFileName, ios::out);
        if (MyFile.is_open())
        {
            for (clsVisitor& V : vVisitors)
            {
                if (!V._MarkForDelete)
                    MyFile << _ConvertVisitorRecordToLine(V) << endl;
            }
            MyFile.close();
        }
    }

    static void _AddVisitorLineToFile(string Line)
    {
        fstream MyFile(VisitorsDataFileName, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << Line << endl;
            MyFile.close();
        }
    }

    void _AddNewVisitor()
    {
        _AddVisitorLineToFile(_ConvertVisitorRecordToLine(*this));
    }

    bool _UpdateVisitor()
    {
        vector<clsVisitor> vVisitors = _LoadVisitorsDataFromFile();

        for (clsVisitor& V : vVisitors)
        {
            if (V.VisitorID == _VisitorID)
            {
                V = *this;
                _SaveVisitorsDataToFile(vVisitors);
                return true;
            }
        }
        return false;
    }

public:
    enum enVisitorStatus { eInside = 1, eExited = 2 };

    clsVisitor(enVisitorMode VisitorMode, string VisitorID, string FirstName, string LastName,
        string VisitPurpose, string VisitedDepartment, string VisitedRoom,
        string SecurityID, enVisitorStatus VisitorStatus,string VisitDateTime ,string ExitDateTime)
    {
        _VisitorMode = VisitorMode;
        _VisitorID = VisitorID;
        _FirstName = FirstName;
        _LastName = LastName;
        _VisitPurpose = VisitPurpose;
        _VisitedDepartment = VisitedDepartment;
        _VisitedRoom = VisitedRoom;
        _VisitDateTime = VisitDateTime;
        _VisitorStatus = VisitorStatus;
        _SecurityID = SecurityID;
        _ExitDateTime = ExitDateTime;
    }

    // Getters & Setters
    void SetVisitorID(string VisitorID) { _VisitorID = VisitorID; }
    string GetVisitorID() { return _VisitorID; }

    void SetFirstName(string FirstName) { _FirstName = FirstName; }
    string GetFirstName() { return _FirstName; }

    void SetLastName(string LastName) { _LastName = LastName; }
    string GetLastName() { return _LastName; }

    void SetVisitPurpose(string VisitPurpose) { _VisitPurpose = VisitPurpose; }
    string GetVisitPurpose() { return _VisitPurpose; }

    void SetVisitedDepartment(string VisitedDepartment) { _VisitedDepartment = VisitedDepartment; }
    string GetVisitedDepartment() { return _VisitedDepartment; }

    void SetVisitedRoom(string VisitedRoom) { _VisitedRoom = VisitedRoom; }
    string GetVisitedRoom() { return _VisitedRoom; }

    void SetVisitDateTime(string VisitDate) { _VisitDateTime = VisitDate; }
    string GetVisitDateTime() { return _VisitDateTime; }

    void SetExitDateTime(string ExitDate) { _ExitDateTime = ExitDate; }
    string GetExitDateTime() { return _ExitDateTime; }

    void SetVisitorStatus(enVisitorStatus VisitorStatus) { _VisitorStatus = VisitorStatus; }
    enVisitorStatus GetVisitorStatus() { return _VisitorStatus; }

    void SetSecurityID(string  SecurityID) { _SecurityID = SecurityID; }
    string  GetSecurityID() { return _SecurityID; }

    __declspec(property(get = GetVisitorID, put = SetVisitorID)) string VisitorID;
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;
    __declspec(property(get = GetVisitPurpose, put = SetVisitPurpose)) string VisitPurpose;
    __declspec(property(get = GetVisitedDepartment, put = SetVisitedDepartment)) string VisitedDepartment;
    __declspec(property(get = GetVisitedRoom, put = SetVisitedRoom)) string VisitedRoom;
    __declspec(property(get = GetVisitDateTime, put = SetVisitDateTime)) string VisitDateTime;
    __declspec(property(get = GetExitDateTime, put = SetExitDateTime)) string ExitDateTime;
    __declspec(property(get = GetVisitorStatus, put = SetVisitorStatus)) enVisitorStatus VisitorStatus;
    __declspec(property(get = GetSecurityID, put = SetSecurityID)) string SecurityID;


    string FullName()
    {
        return _FirstName + " " + _LastName;
    }


    // Main public functions
    static vector<clsVisitor> GetVisitorList()
    {
        return _LoadVisitorsDataFromFile();
    }

    static clsVisitor GetAddNewVisitorObject()
    {
        return clsVisitor(eAddNewMode, "", "", "", "", "", "", "" ,(enVisitorStatus)0,"","");
    }

    static clsVisitor GetUpdateVisitorObject()
    {
        return clsVisitor(eUpdateMode, "", "", "", "", "", "", "", (enVisitorStatus)0,"","");
    }

    bool DeleteVisitor()
    {
        vector<clsVisitor> vVisitors = _LoadVisitorsDataFromFile();

        for (clsVisitor& V : vVisitors)
        {
            if (V.VisitorID == _VisitorID)
            {
                V._MarkForDelete = true;
                _SaveVisitorsDataToFile(vVisitors);
                return true;
            }
        }
        return false;
    }

    static clsVisitor FindVisitor(string VisitorID)
    {
        vector<clsVisitor> vVisitors = _LoadVisitorsDataFromFile();
        for (clsVisitor& V : vVisitors)
        {
            if (V.VisitorID == VisitorID)
                return V;
        }
        return _GetEmptyVisitorObject();
    }

    static bool IsVisitorExist(string VisitorID)
    {
        clsVisitor Visitor = FindVisitor(VisitorID);
        return !(Visitor.IsEmpty());
    }

    bool IsEmpty()
    {
        return _VisitorMode == enVisitorMode::eEmptyMode;
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildVisitorExist = 2 };

    enSaveResults SaveVisitor()
    {
        switch (_VisitorMode)
        {
        case eEmptyMode:
            return svFaildEmptyObject;

        case eUpdateMode:
            _UpdateVisitor();
            return svSucceeded;

        case eAddNewMode:
            if (clsVisitor::IsVisitorExist(_VisitorID))
                return svFaildVisitorExist;
            else
            {
                _AddNewVisitor();
                _VisitorMode = eUpdateMode;
                return svSucceeded;
            }
        }
        return svFaildEmptyObject;
    }

    static int CountVisitorsByStatus(enVisitorStatus Status)
    {
        vector<clsVisitor> vVisitors = _LoadVisitorsDataFromFile();
        int Counter = 0;
        for (clsVisitor& V : vVisitors)
        {
            if (V.VisitorStatus == Status)
                Counter++;
        }
        return Counter;
    }

    static string VisitorStatusString(enVisitorStatus VisitorStatus)
    {
        switch (VisitorStatus)
        {
        case eInside:
            return "Inside";
        case eExited:
            return "Exited";
        default:
            return "Unknown";
        }
    }

    static vector<clsVisitor> GetVisitorListByStatus(enVisitorStatus FiltredVisitorStatus)
    {
        vector<clsVisitor>vFullVisitorsList = clsVisitor::_LoadVisitorsDataFromFile();
        vector<clsVisitor>vFiltredList;

        for (clsVisitor& Visitor : vFullVisitorsList)
        {

            if (Visitor.VisitorStatus == FiltredVisitorStatus)
            {
                vFiltredList.push_back(Visitor);
            }

        }
        return vFiltredList;
    }

    static bool IsTodayVisit(clsVisitor Visitor)
    {
        clsDate Today = clsDate();
        string Day = "", Month = "", Year = "";
        Day += Visitor.VisitDateTime[0];
        Day += Visitor.VisitDateTime[1];
        Month += Visitor.VisitDateTime[3];
        Month += Visitor.VisitDateTime[4];
        Year += Visitor.VisitDateTime[6];
        Year += Visitor.VisitDateTime[7];
        Year += Visitor.VisitDateTime[8];
        Year += Visitor.VisitDateTime[9];
        return (to_string(Today.Day) == Day && to_string(Today.Month) == Month && to_string(Today.Year) == Year);
    }
    
    static vector<clsVisitor>GetTodayEntredVisitorsList()
    {
        vector<clsVisitor>vFullVisitorsList = clsVisitor::_LoadVisitorsDataFromFile();
        vector<clsVisitor>vFiltredList;

        for (clsVisitor& Visitor : vFullVisitorsList)
        {
            if (IsTodayVisit(Visitor))
            {
                vFiltredList.push_back(Visitor);
            }
        }
        return vFiltredList;
    }

    static vector<clsVisitor> GetVisitorListByVisitedDepartment(string  DepartmentToVisit)
    {
        vector<clsVisitor>vFullVisitorsList = clsVisitor::_LoadVisitorsDataFromFile();
        vector<clsVisitor>vFiltredList;

        for (clsVisitor& Visitor : vFullVisitorsList)
        {
            if (Visitor.VisitedDepartment == DepartmentToVisit)
            {
                vFiltredList.push_back(Visitor);
            }

        }
        return vFiltredList;
    }



    static vector<clsVisitor> GetVisitorListByName(string  FirstName,string LastName)
    {
        vector<clsVisitor>vFullVisitorsList = clsVisitor::_LoadVisitorsDataFromFile();
        vector<clsVisitor>vFiltredList;

        for (clsVisitor& Visitor : vFullVisitorsList)
        {
            if (Visitor.FirstName == FirstName && Visitor.LastName== LastName)
            {
                vFiltredList.push_back(Visitor);
            }

        }
        return vFiltredList;
    }


};

