#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsInputValidate.h"
#include "Global.h";
#include "clsUtil.h";

using namespace std;

class clsIncidentReport
{
private:
    enum enIncidentMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };
    enIncidentMode _IncidentMode;
    enum enIncidentSaverity;
    enum enIncidentStatus;
    string _IncidentID;
    string _SecurityID;
    string _IncidentDateTime;
    string _IncidentType;
    string _Description;
    enIncidentSaverity _Severity; // 
    enIncidentStatus _Status;   // 
    string _LastUpdateDateTime;

    bool _MarkForDelete = false;

    static clsIncidentReport _ConvertLineToIncidentReport(string Line)
    {
        vector<string> vData = clsString::Split(Line, "#//#");
        return clsIncidentReport(
            enIncidentMode::eUpdateMode,
            vData[0], vData[1], vData[2], vData[3], vData[4],
            (enIncidentSaverity)stoi(vData[5]), (enIncidentStatus)stoi(vData[6]), vData[7]
        );
    }

    static string _ConvertIncidentReportToLine(clsIncidentReport Report)
    {
        string Line = "";
        Line += Report.IncidentID + "#//#";
        Line += Report.SecurityID + "#//#";
        Line += Report.IncidentDateTime + "#//#";
        Line += Report.IncidentType + "#//#";
        Line += Report.Description + "#//#";
        Line += to_string(Report.Severity) + "#//#";
        Line += to_string(Report.Status) + "#//#";
        Line += Report.LastUpdateDateTime;
        return Line;
    }

    static vector<clsIncidentReport> _LoadIncidentsDataFromFile()
    {
        vector<clsIncidentReport> vIncidents;
        fstream MyFile;
        MyFile.open(IncidentReportsFileName, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                if (Line != "")
                    vIncidents.push_back(_ConvertLineToIncidentReport(Line));
            }
            MyFile.close();
        }
        return vIncidents;
    }

    static void _SaveIncidentsDataToFile(vector<clsIncidentReport> vIncidents)
    {
        fstream MyFile;
        MyFile.open(IncidentReportsFileName, ios::out);

        if (MyFile.is_open())
        {
            for (clsIncidentReport& I : vIncidents)
            {
                if (I._MarkForDelete == false)
                    MyFile << _ConvertIncidentReportToLine(I) << endl;
            }
            MyFile.close();
        }
    }

    static clsIncidentReport _GetEmptyIncidentReportObject()
    {
        return clsIncidentReport(
            clsIncidentReport::enIncidentMode::eEmptyMode,
            "", "", "", "", "",(enIncidentSaverity) 0, (enIncidentStatus)0, ""
        );
    }

    bool _UpdateIncident()
    {
        vector<clsIncidentReport> vIncidents = _LoadIncidentsDataFromFile();

        for (clsIncidentReport& I : vIncidents)
        {
            if (I.IncidentID == IncidentID)
            {
                I = *this;
                _SaveIncidentsDataToFile(vIncidents);
                return true;
            }
        }
        return false;
    }

    void _AddNewIncident()
    {
        _AddIncidentLineToFile(_ConvertIncidentReportToLine(*this));
    }

public:



    enum enIncidentStatus { Open = 1, InReview = 2, Resolved = 3, Closed = 4 };
    enum enIncidentSaverity { Low = 1, Medium = 2, High = 3 };


    static string GetIncidentStatusString(enIncidentStatus Status)
    {
        switch (Status)
        {
        case enIncidentStatus::Open:
            return "Open";
        case enIncidentStatus::InReview:
            return "In Review";
        case enIncidentStatus::Resolved:
            return "Resolved";
        case enIncidentStatus::Closed:
            return "Closed";
        default:
            return "Unknown";
        }
    }


    clsIncidentReport(
        enIncidentMode IncidentMode,
        string IncidentID,
        string SecurityID,
        string IncidentDateTime,
        string IncidentType,
        string Description,
        enIncidentSaverity Severity,
        enIncidentStatus Status,
        string LastUpdateDateTime)
    {
        _IncidentMode = IncidentMode;
        _IncidentID = IncidentID;
        _SecurityID = SecurityID;
        _IncidentDateTime = IncidentDateTime;
        _IncidentType = IncidentType;
        _Description = Description;
        _Severity = Severity;
        _Status = Status;
        _LastUpdateDateTime = LastUpdateDateTime;
    }

    // Getters
    string getIncidentID() { return _IncidentID; }
    string getSecurityID() { return _SecurityID; }
    string getIncidentDateTime() { return _IncidentDateTime; }
    string getIncidentType() { return _IncidentType; }
    string getDescription() { return _Description; }
    enIncidentSaverity getSeverity() { return _Severity; }
    enIncidentStatus getStatus() { return _Status; }
    string getLastUpdateDateTime() { return _LastUpdateDateTime; }

    // Setters
    void setIncidentID(string IncidentID) { _IncidentID = IncidentID; }
    void setSecurityID(string SecurityID) { _SecurityID = SecurityID; }
    void setIncidentDateTime(string IncidentDateTime) { _IncidentDateTime = IncidentDateTime; }
    void setIncidentType(string IncidentType) { _IncidentType = IncidentType; }
    void setDescription(string Description) { _Description = Description; }
    void setSeverity(enIncidentSaverity Severity) { _Severity = Severity; }
    void setStatus(enIncidentStatus Status) { _Status = Status; }
    void setLastUpdateDateTime(string LastUpdateDateTime) { _LastUpdateDateTime = LastUpdateDateTime; }

    // __declspec(property)
    __declspec(property(get = getIncidentID, put = setIncidentID)) string IncidentID;
    __declspec(property(get = getSecurityID, put = setSecurityID)) string SecurityID;
    __declspec(property(get = getIncidentDateTime, put = setIncidentDateTime)) string IncidentDateTime;
    __declspec(property(get = getIncidentType, put = setIncidentType)) string IncidentType;
    __declspec(property(get = getDescription, put = setDescription)) string Description;
    __declspec(property(get = getSeverity, put = setSeverity)) enIncidentSaverity Severity;
    __declspec(property(get = getStatus, put = setStatus)) enIncidentStatus Status;
    __declspec(property(get = getLastUpdateDateTime, put = setLastUpdateDateTime)) string LastUpdateDateTime;

    static string GetStatusString(int Status)
    {
        switch (Status)
        {
        case 1: return "Open";
        case 2: return "In Review";
        case 3: return "Resolved";
        case 4: return "Closed";
        default: return "Unknown";
        }
    }

    static string GetSeverityString(int Severity)
    {
        switch (Severity)
        {
        case 1: return "Low";
        case 2: return "Medium";
        case 3: return "High";
        default: return "Unknown";
        }
    }

    static vector<clsIncidentReport> GetIncidentsList()
    {
        return _LoadIncidentsDataFromFile();
    }

    static void _AddIncidentLineToFile(string Line)
    {
        fstream MyFile;
        MyFile.open(IncidentReportsFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << Line << endl;
            MyFile.close();
        }
    }

    static clsIncidentReport GetAddNewIncidentObject(string IncidentID)
    {
        return clsIncidentReport(
            clsIncidentReport::enIncidentMode::eAddNewMode,
            IncidentID, "", "", "", "",(enIncidentSaverity) 0, (enIncidentStatus)0, ""
        );
    }

    static clsIncidentReport GetUpdateIncidentObject()
    {
        return clsIncidentReport(
            clsIncidentReport::enIncidentMode::eUpdateMode,
            "", "", "", "", "",(enIncidentSaverity) 0, (enIncidentStatus)0, ""
        );
    }

    static clsIncidentReport FindIncident(string IncidentID)
    {
        vector<clsIncidentReport> vIncidents = _LoadIncidentsDataFromFile();
        for (clsIncidentReport& I : vIncidents)
        {
            if (I.IncidentID == IncidentID)
                return I;
        }
        return _GetEmptyIncidentReportObject();
    }

    bool IsEmpty()
    {
        return _IncidentMode == enIncidentMode::eEmptyMode;
    }

    static bool IsIncidentExist(string IncidentID)
    {
        clsIncidentReport Incident = FindIncident(IncidentID);
        return !Incident.IsEmpty();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildObjectExist = 2 };

    enSaveResults SaveIncident()
    {
        switch (_IncidentMode)
        {
        case enIncidentMode::eEmptyMode:
            return enSaveResults::svFaildEmptyObject;

        case enIncidentMode::eUpdateMode:
            _UpdateIncident();
            return enSaveResults::svSucceeded;

        case enIncidentMode::eAddNewMode:
            if (clsIncidentReport::IsIncidentExist(IncidentID))
                return enSaveResults::svFaildObjectExist;
            else
            {
                _AddNewIncident();
                _IncidentMode = enIncidentMode::eUpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
        return enSaveResults::svFaildEmptyObject;
    }

    bool DeleteIncident()
    {
        vector<clsIncidentReport> vIncidents = _LoadIncidentsDataFromFile();

        for (clsIncidentReport& I : vIncidents)
        {
            if (I.IncidentID == IncidentID)
            {
                I._MarkForDelete = true;
                _SaveIncidentsDataToFile(vIncidents);
                return true;
            }
        }
        return false;
    }

    struct stIncidentsCount
    {
        int Open = 0, InReview = 0, Resolved = 0, Closed = 0, HighSaverity=0,MediumSaverity=0,LowSaverity=0;
    };

    static stIncidentsCount CountIncidents()
    {
        vector<clsIncidentReport> vIncidents = _LoadIncidentsDataFromFile();
        stIncidentsCount IncidentCount;

        for (clsIncidentReport& I : vIncidents)
        {
            
            switch (I.Status)
            {
                case enIncidentStatus ::Open:
                {
                    IncidentCount.Open++;
                    break;
                }

                case enIncidentStatus::InReview:
                {
                    IncidentCount.InReview++;
                    break;
                }

                case enIncidentStatus::Resolved:
                {
                    IncidentCount.Resolved++;
                    break;
                }

                case enIncidentStatus::Closed:
                {
                    IncidentCount.Closed++;
                    break;
                }

                default: 
                {
                    break;
                }

            }

            switch (I.Severity)
            {

                case enIncidentSaverity::High:
                {
                    IncidentCount.HighSaverity++;
                    break;
                }
                case enIncidentSaverity::Medium:
                {
                    IncidentCount.MediumSaverity++;
                    break;
                }
                case enIncidentSaverity::Low:
                {
                    IncidentCount.LowSaverity++;
                    break;
                }
                default:
                {

                    break;
                }
            }

        }
        return IncidentCount;
    }


    static stIncidentsCount CountIncidentsBySaverity()
    {
        vector<clsIncidentReport> vIncidents = _LoadIncidentsDataFromFile();
        stIncidentsCount IncidentCount;

        for (clsIncidentReport& I : vIncidents)
        {
            switch (I.Status)
            {
            case enIncidentStatus::Open:
                IncidentCount.Open++;
                break;
            case enIncidentStatus::InReview:
                IncidentCount.InReview++;
                break;
            case enIncidentStatus::Resolved:
                IncidentCount.Resolved++;
                break;
            case enIncidentStatus::Closed:
                IncidentCount.Closed++;
                break;
            default:
                IncidentCount = stIncidentsCount();

                break;
            }
        }
        return IncidentCount;
    }


    static vector<clsIncidentReport> GetIncidentListByStatus(enIncidentStatus In_Status)
    {
        vector<clsIncidentReport>vFullIncidents = _LoadIncidentsDataFromFile();

        vector<clsIncidentReport>vFiltredIncident ;


        for (clsIncidentReport& Incident : vFullIncidents)
        {
            if (Incident.Status == In_Status)
            {

                vFiltredIncident.push_back(Incident);

            }


        }
        return vFiltredIncident;

    }


    static vector<clsIncidentReport> GetIncidentListBySaverity(enIncidentSaverity  Saverity)
    {
        vector<clsIncidentReport>vFullIncidents = _LoadIncidentsDataFromFile();
        vector<clsIncidentReport>vFiltredIncident;
        for (clsIncidentReport& Incident : vFullIncidents)
        {
            if (Incident.Severity == Saverity)
            {

                vFiltredIncident.push_back(Incident);
            }
        }
        return vFiltredIncident;
    }



    static vector<clsIncidentReport> GetIncidentListBySeCurityID(string  SecurityID)
    {
        vector<clsIncidentReport>vFullIncidents = _LoadIncidentsDataFromFile();
        vector<clsIncidentReport>vFiltredIncident;
        for (clsIncidentReport& Incident : vFullIncidents)
        {
            if (Incident.SecurityID == SecurityID)
            {

                vFiltredIncident.push_back(Incident);
            }
        }
        return vFiltredIncident;
    }

    static vector<clsIncidentReport> GetIncidentListByType(string  IncidentType)
    {
        vector<clsIncidentReport>vFullIncidents = _LoadIncidentsDataFromFile();
        vector<clsIncidentReport>vFiltredIncident;
        for (clsIncidentReport& Incident : vFullIncidents)
        {
            if (Incident.IncidentType == IncidentType)
            {

                vFiltredIncident.push_back(Incident);
            }
        }
        return vFiltredIncident;
    }

};
