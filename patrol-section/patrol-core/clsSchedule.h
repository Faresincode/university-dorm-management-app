#pragma once
#include <iostream>
#include <Vector>
#include <iomanip>
#include <string>
#include "clsInputValidate.h";
#include "clsDate.h";
#include "clsUtil.h"; 
#include "Global.h";
#include "clsEmployee.h".


class clsSchedule 
{


private:

    enum enSchedualMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };

  

    enSchedualMode _Mode;
    string _EmployeeID;
    enum enShift;
    enShift _ShiftStart;     // e.g., "08:00"
    enShift _ShiftEnd;       // e.g., "16:00"
    short _WorkDays;       // e.g., "Mon,Tue,Wed,Thu,Fri"
    string _LastUpdated;    // date when schedule was last changed
    string _ResidenceName;  // optional (if needed)
    bool _MarkForDelete = false;

    static string _ConvertScheduleObjectToLine(clsSchedule Schedule, string Separator = "#//#")
    {
        string Line = "";
        Line += Schedule.EmployeeID + Separator;
        Line += Schedule.ResidenceName + Separator;
        Line += to_string(Schedule.ShiftStart) + Separator;
        Line += to_string(Schedule.ShiftEnd) + Separator;
        Line += to_string(Schedule.WorkDays) + Separator;
        Line += clsDate::GetSystemDateAsFormat("dd-mm-yyyy") ;
        return Line;
    }

    static clsSchedule _ConvertLineToScheduleObject(string Line, string Separator = "#//#")
    {
        vector<string> vData = clsString::Split(Line, Separator);

        return clsSchedule
        (
            enSchedualMode::eUpdateMode,
            vData[0],                  // EmployeeID
            vData[1] ,                 // ResidenceName
            (enShift)stoi(vData[2]),   // ShiftStart
            (enShift)stoi(vData[3]),   // ShiftEnd
            (enDay)stoi(vData[4]),                  // WorkDays
            vData[5]                   // LastUpdated
        );
    }

    static vector<clsSchedule> _LoadSchedulesFromFile()
    {
        vector<clsSchedule> vSchedules;
        fstream MyFile;
        MyFile.open(ScheduleFileName, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsSchedule Schedule = _ConvertLineToScheduleObject(Line);
                vSchedules.push_back(Schedule);
            }
            MyFile.close();
        }
        return vSchedules;
    }

    static void _SaveSchedulesToFile(vector<clsSchedule> vSchedules)
    {
        fstream MyFile;
        MyFile.open(ScheduleFileName, ios::out);

        if (MyFile.is_open())
        {
            for (clsSchedule& Schedule : vSchedules)
            {
                if (Schedule._MarkForDelete == false)
                {
                    MyFile << _ConvertScheduleObjectToLine(Schedule) << endl;

                }
            }
            MyFile.close();
        }
    }

    void _AddNew(string Line)
    {
        fstream MyFile;
        MyFile.open(ScheduleFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << Line << endl;
            MyFile.close();
        }
    }

    void _AddNewSchedule()
    {

        _AddNew(_ConvertScheduleObjectToLine(*this));
    }
    static clsSchedule _GetEmptyScheduleObject()
    {

        return clsSchedule(enSchedualMode::eEmptyMode, "", "", enShift::eNoShift, enShift::eNoShift, enDay::NoDay, "");
    }

    bool _UpdateSchedule()
    {

        vector<clsSchedule> vSchedules = _LoadSchedulesFromFile();
        for (clsSchedule& Employee : vSchedules)
        {
            if (Employee.EmployeeID == EmployeeID)
            {
                Employee = *this;
                _SaveSchedulesToFile(vSchedules);
                return true;
            }
        }
        return false;
    }

public:

    clsSchedule(enSchedualMode Mode,string EmployeeID,string ResidenceName , enShift ShiftStart , enShift ShiftEnd,
        short WorkDays, string LastUpdated )
    {
        _Mode = Mode;
        _EmployeeID = EmployeeID;
        _ShiftStart = ShiftStart;
        _ShiftEnd = ShiftEnd;
        _WorkDays = WorkDays;
        _LastUpdated = LastUpdated;
        _ResidenceName = ResidenceName;
    }


    enum enShift { eMorning = 1, eEvening = 2, eNight = 3, eNoShift = 0 };
    enum enDay { Sun = 1, Mon = 2, Tue = 4, Wed = 8, Thu = 16, Fri = 32, Sat = 64, NoDay = 0 };



    string GetEmployeeID() const { return _EmployeeID; }
    enShift GetShiftStart() const { return _ShiftStart; }
    enShift GetShiftEnd() const { return _ShiftEnd; }
    short GetWorkDays() const { return _WorkDays; }
    string GetLastUpdated() const { return _LastUpdated; }
    string GetResidenceName() const { return _ResidenceName; }

    void SetEmployeeID(string ID) { _EmployeeID = ID; }
    void SetShiftStart(enShift ShiftStart) { _ShiftStart = ShiftStart; }
    void SetShiftEnd(enShift ShiftEnd) { _ShiftEnd = ShiftEnd; }
    void SetWorkDays(short WorkDays) { _WorkDays = WorkDays; }
    void SetLastUpdated(string LastUpdated) { _LastUpdated = LastUpdated; }
    void SetResidenceName(string ResidenceName) { _ResidenceName = ResidenceName; }

    __declspec(property(get = GetEmployeeID, put = SetEmployeeID)) string EmployeeID;
    __declspec(property(get = GetShiftStart, put = SetShiftStart)) enShift ShiftStart;
    __declspec(property(get = GetShiftEnd, put = SetShiftEnd)) enShift ShiftEnd;
    __declspec(property(get = GetWorkDays, put = SetWorkDays)) short WorkDays;
    __declspec(property(get = GetLastUpdated, put = SetLastUpdated)) string LastUpdated;
    __declspec(property(get = GetResidenceName, put = SetResidenceName)) string ResidenceName;


    static clsSchedule GetAddNewScheduleObject()
    {

        return clsSchedule(enSchedualMode::eAddNewMode, "", "", enShift::eNoShift, enShift::eNoShift,enDay::NoDay, "");
    }
    static clsSchedule GetUpdateScheduleObject()
    {

        return clsSchedule(enSchedualMode::eUpdateMode, "", "", enShift::eNoShift, enShift::eNoShift,enDay::NoDay, "");
    }



    static clsSchedule FindSchedule(string EmployeeID)
    {
        vector<clsSchedule> vScheduales = _LoadSchedulesFromFile();

        for (clsSchedule& Scheduale : vScheduales)
        {
            if (Scheduale.EmployeeID == EmployeeID)
                return Scheduale;
        }

        return _GetEmptyScheduleObject(); // returns empty if not found
    }

    static bool IsScheduleExist(string EmployeeID)
    {
        clsSchedule Schedual = clsSchedule::FindSchedule(EmployeeID);
        return !(Schedual.IsEmpty());
    }

    bool IsEmpty()
    {
        return _Mode == enSchedualMode::eEmptyMode;
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildEmployeeExist = 2 };

    enSaveResults Save()
    {
        switch (_Mode)
        {

        case enSchedualMode::eEmptyMode:
            return enSaveResults::svFaildEmptyObject;

        case enSchedualMode::eUpdateMode:
            _UpdateSchedule();
            return enSaveResults::svSucceeded;

        case enSchedualMode::eAddNewMode:

            if (clsEmployee::IsEmployeeExist(EmployeeID))
            {
                return enSaveResults::svFaildEmployeeExist;
            }
            else
            {
                _AddNewSchedule();
                _Mode = enSchedualMode::eUpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
    }

    bool DeleteSchedule()
    {

        vector<clsSchedule>vSchedules = _LoadSchedulesFromFile();
        for (clsSchedule& Schedule : vSchedules)
        {
            if (Schedule.EmployeeID == EmployeeID)
            {
                Schedule._MarkForDelete = true;
                _SaveSchedulesToFile(vSchedules);
                return true;
            }
        }
        return false;


    }


    static vector<clsSchedule> GetSchedulesList()
    {
        return _LoadSchedulesFromFile();
    }


    bool IsWorkDay(enDay WeekDay)
    {
        return((_WorkDays & WeekDay) == WeekDay);
    }

    static string WorkDaysString(clsSchedule EmployeeSchedule)
    {
        string WorkDaysString = "";
        
        if (EmployeeSchedule.IsWorkDay(enDay::Sun))
        {
            WorkDaysString += "Sun.";
        }
        if(EmployeeSchedule.IsWorkDay(enDay::Mon))
        {
            WorkDaysString += "Mon.";
        }
        if (EmployeeSchedule.IsWorkDay(enDay::Tue))
        {
            WorkDaysString += "Tue.";
        }
        if (EmployeeSchedule.IsWorkDay(enDay::Wed))
        {
            WorkDaysString += "Wed.";
        }
        if (EmployeeSchedule.IsWorkDay(enDay::Thu))
        {
            WorkDaysString += "Thu.";
        }
        if (EmployeeSchedule.IsWorkDay(enDay::Fri))
        {
            WorkDaysString += "Fri.";
        }
        if(EmployeeSchedule.IsWorkDay(enDay::Sat))
        {
            WorkDaysString += "Sat.";
        }
        

        return WorkDaysString;





    }

    static string GetShiftString(enShift Shift)
    {

        switch (Shift)
        {
        case clsSchedule::eMorning:
            return "Morning";
        case clsSchedule::eEvening:
            return "Evening";
        case clsSchedule::eNight:
            return "Night";
        case clsSchedule::eNoShift:
            return "No Shift";
        default:
            return "No Shift";
        }
    }



};

