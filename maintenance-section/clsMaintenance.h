#pragma once

#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "Global.h";


using namespace std;


class clsMaintenance
{




private:

    enum enMaintenanceMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };

    enum enPriorityLevel;
    enum enMaintenanceStatus;
    enMaintenanceMode _Mode;             // Add, Update, Delete (like in your other classes)
    string _RequestID;                   // Unique identifier for the maintenance request
    string _DormBuilding;                      // Which dorm/room the request belongs to
    short _RoomNumber;
    string _ReportedBy;                  // Who reported the issue (student/employee)
    string _IssueType;                   // Type of problem (e.g., Electrical, Plumbing, etc.)
    string _Description;                 // Description of the issue
    enPriorityLevel _Priority;           // Low, Medium, High
    enMaintenanceStatus _Status;         // Pending, InProgress, Completed, Cancelled
    string _RequestDate;                 // Date the request was made   q
    string _AssignedStaffID;             // ID of staff assigned to fix it (can be empty)
    string _LastUpdateDate;              // When it was last modified
    bool _MarkForDelete = false;


    static clsMaintenance _ConvertLineToMaintenanceRecord(string Line)
    {
        vector<string> vLine = clsString::Split(Line, "#//#");

        return clsMaintenance(
            enMaintenanceMode::eUpdateMode,   // Mode when loading from file
            vLine[0],                         // RequestID
            vLine[1],                         // DormBuilding
            stoi(vLine[2]),                   // RoomNumber
            vLine[3],                         // ReportedBy
            vLine[4],                         // IssueType
            vLine[5],                         // Description
            (enPriorityLevel)stoi(vLine[6]),  // Priority
            (enMaintenanceStatus)stoi(vLine[7]), // Status
            vLine[8],                         // RequestDate
            vLine[9],                         // AssignedStaffID
            vLine[10]                         // LastUpdateDate
        );
    }

    static string _ConvertMaintenanceRecordToLine(clsMaintenance Request, string Separator = "#//#")
    {
        string Line = "";

        Line += Request.RequestID + Separator;
        Line += Request.DormBuilding + Separator;
        Line += to_string(Request.RoomNumber) + Separator;
        Line += Request.ReportedBy + Separator;
        Line += Request.IssueType + Separator;
        Line += Request.IssueDescription + Separator;
        Line += to_string(Request.Priority) + Separator;
        Line += to_string(Request.Status) + Separator;
        Line += Request.RequestDate + Separator;
        Line += Request.AssignedStaffID + Separator;
        Line += Request.LastUpdateDate;

        return Line;
    }


    static vector<clsMaintenance> _LoadMaintenanceRequestsDataFromFile()
    {
        vector<clsMaintenance> vMaintenanceRequests;

        fstream File;
        File.open(MaintenanceRequestsFileName, ios::in);

        if (File.is_open())
        {
            string Line;

            while (getline(File, Line))
            {
                if (Line != "")
                {
                    clsMaintenance Request = _ConvertLineToMaintenanceRecord(Line);
                    vMaintenanceRequests.push_back(Request);
                }
            }

            File.close();
        }

        return vMaintenanceRequests;
    }

    static void _SaveMaintenanceRequestsDataToFile(vector<clsMaintenance> vMaintenanceRequests)
    {
        fstream File;
        File.open(MaintenanceRequestsFileName, ios::out);

        if (File.is_open())
        {
            for (clsMaintenance& Request : vMaintenanceRequests)
            {
                if (Request._MarkForDelete == false)
                {
                    File << _ConvertMaintenanceRecordToLine(Request) << endl;

                }
            }

            File.close();
        }
    }
    

    static void _AddMaintenanceRequestsLineToFile(string Line)
    {
        fstream MyFile;
        MyFile.open(MaintenanceRequestsFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << Line << endl;
            MyFile.close();
        }
    }


    void _AddNewMaintenanceRequest()
    {
        _AddMaintenanceRequestsLineToFile(_ConvertMaintenanceRecordToLine(*this));
    }



    bool _UpdateMaintenanceRequest()
    {

        vector<clsMaintenance> vMaintenanceRequests = _LoadMaintenanceRequestsDataFromFile();
        for (clsMaintenance& Request : vMaintenanceRequests)
        {
            if (Request.RequestID == RequestID)
            {
                Request = *this;
                _SaveMaintenanceRequestsDataToFile(vMaintenanceRequests);
                return true;
            }
        }
        return false;


    }

    static clsMaintenance _GetEmptyMaintenanceObject()
    {
        return clsMaintenance(enMaintenanceMode::eEmptyMode, "", "", 0, "", "", "", (enPriorityLevel)0, (enMaintenanceStatus)0, "", "", "");
    }



public:



    enum enMaintenanceStatus { ePending = 1, eInProgress = 2, eCompleted = 3, eCancelled = 4 };
    enum enPriorityLevel { eLow = 1, eMedium = 2, eHigh = 3 };

    static string GetStatusString(enMaintenanceStatus MaintStatus)
    {
        switch (MaintStatus)
        {
        case clsMaintenance::ePending:
            return  "Pending";
        case clsMaintenance::eInProgress:
            return "InProgress";
        case clsMaintenance::eCompleted:
            return "Completed";
        case clsMaintenance::eCancelled:
            return "Cancelled";
        default:
            return "No Status";
        }

    }
    static string GetPriorityLevelString(enPriorityLevel Level)
    {
        switch (Level)
        {
        case clsMaintenance::eLow:
            return "Low";
        case clsMaintenance::eMedium:
            return "Medium";
        case clsMaintenance::eHigh:
            return "High";
        default:
            return "No Priority";
        }

    }

    // ========== Request ID ==========
    string GetRequestID() { return _RequestID; }
    void SetRequestID(string RequestID) { _RequestID = RequestID; }
    __declspec(property(get = GetRequestID, put = SetRequestID)) string RequestID;

    // ========== Dorm Building ==========
    string GetDormBuilding() { return _DormBuilding; }
    void SetDormBuilding(string DormBuilding) { _DormBuilding = DormBuilding; }
    __declspec(property(get = GetDormBuilding, put = SetDormBuilding)) string DormBuilding;

    // ========== Room Number ==========
    short GetRoomNumber() { return _RoomNumber; }
    void SetRoomNumber(short RoomNumber) { _RoomNumber = RoomNumber; }
    __declspec(property(get = GetRoomNumber, put = SetRoomNumber)) short RoomNumber;

    // ========== Reported By ==========
    string GetReportedBy() { return _ReportedBy; }
    void SetReportedBy(string ReportedBy) { _ReportedBy = ReportedBy; }
    __declspec(property(get = GetReportedBy, put = SetReportedBy)) string ReportedBy;

    // ========== Issue Type ==========
    string GetIssueType() { return _IssueType; }
    void SetIssueType(string IssueType) { _IssueType = IssueType; }
    __declspec(property(get = GetIssueType, put = SetIssueType)) string IssueType;

    // ========== Description ==========
    string GetDescription() { return _Description; }
    void SetDescription(string Description) { _Description = Description; }
    __declspec(property(get = GetDescription, put = SetDescription)) string IssueDescription;

    // ========== Priority ==========
    enPriorityLevel GetPriority() { return _Priority; }
    void SetPriority(enPriorityLevel Priority) { _Priority = Priority; }
    __declspec(property(get = GetPriority, put = SetPriority)) enPriorityLevel Priority;

    // ========== Status ==========
    enMaintenanceStatus GetStatus() { return _Status; }
    void SetStatus(enMaintenanceStatus Status) { _Status = Status; }
    __declspec(property(get = GetStatus, put = SetStatus)) enMaintenanceStatus Status;

    // ========== Request Date ==========
    string GetRequestDate() { return _RequestDate; }
    void SetRequestDate(string RequestDate) { _RequestDate = RequestDate; }
    __declspec(property(get = GetRequestDate, put = SetRequestDate)) string RequestDate;

    // ========== Assigned Staff ID ==========
    string GetAssignedStaffID() { return _AssignedStaffID; }
    void SetAssignedStaffID(string AssignedStaffID) { _AssignedStaffID = AssignedStaffID; }
    __declspec(property(get = GetAssignedStaffID, put = SetAssignedStaffID)) string AssignedStaffID;

    // ========== Last Update Date ==========
    string GetLastUpdateDate() { return _LastUpdateDate; }
    void SetLastUpdateDate(string LastUpdateDate) { _LastUpdateDate = LastUpdateDate; }
    __declspec(property(get = GetLastUpdateDate, put = SetLastUpdateDate)) string LastUpdateDate;

    clsMaintenance(enMaintenanceMode Mode,string RequestID,string DormBuilding,short RoomNumber,string ReportedBy,string IssueType,string Description,enPriorityLevel Priority, enMaintenanceStatus Status,string RequestDate,string AssignedStaffID,string LastUpdateDate)
    {
        _Mode = Mode;
        _RequestID = RequestID;
        _DormBuilding = DormBuilding;
        _RoomNumber = RoomNumber;
        _ReportedBy = ReportedBy;
        _IssueType = IssueType;
        _Description = Description;
        _Priority = Priority;
        _Status = Status;
        _RequestDate = RequestDate;
        _AssignedStaffID = AssignedStaffID;
        _LastUpdateDate = LastUpdateDate;
    }

    static vector<clsMaintenance>GetMaintenanceRequestsList()
    {

        return _LoadMaintenanceRequestsDataFromFile();
    }

    static clsMaintenance GetUpdateMaintenanceObject()
    {
        return clsMaintenance(enMaintenanceMode::eUpdateMode, "", "", 0, "", "", "", (enPriorityLevel)0, (enMaintenanceStatus)0, "", "", "");
    }

    static clsMaintenance GetAddNewMaintenanceObject()
    {
        return clsMaintenance(enMaintenanceMode::eAddNewMode, "", "", 0, "", "", "", (enPriorityLevel)0, (enMaintenanceStatus)0, "", "", "");
    }

    bool DeleteMaintRequest()
    {

        vector<clsMaintenance>vMaintenanceRequests = _LoadMaintenanceRequestsDataFromFile();
        for (clsMaintenance& request : vMaintenanceRequests)
        {
            if (request.RequestID == RequestID)
            {
                request._MarkForDelete = true;
                _SaveMaintenanceRequestsDataToFile(vMaintenanceRequests);
                return true;
            }
        }
        return false;
    }

    static clsMaintenance FindMaintenanceRequest(string RequestID)
    {
        vector<clsMaintenance> vMaintenanceRequests = _LoadMaintenanceRequestsDataFromFile();

        for (clsMaintenance& request : vMaintenanceRequests)
        {
            if (request.RequestID == RequestID )
                return request;
        }

        return _GetEmptyMaintenanceObject(); 
    }

    static bool IsMaintenanceRequestExist(string RequestID)
    {
        clsMaintenance Employee = FindMaintenanceRequest(RequestID);
        return !(Employee.IsEmpty());
    }

    bool IsEmpty()
    {
        return _Mode == enMaintenanceMode::eEmptyMode;
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildMaintenanceRequestExist = 2 };

    enSaveResults SaveMaintRequest()
    {
        switch (_Mode)
        {

        case enMaintenanceMode::eEmptyMode:
            return enSaveResults::svFaildEmptyObject;

        case enMaintenanceMode::eUpdateMode:
            _UpdateMaintenanceRequest();
            return enSaveResults::svSucceeded;

        case enMaintenanceMode::eAddNewMode:

            if (!clsMaintenance::IsMaintenanceRequestExist(RequestID))
            {
                return enSaveResults::svFaildMaintenanceRequestExist;
            }
            else
            {
                _AddNewMaintenanceRequest();
                _Mode =enMaintenanceMode::eUpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
    }



    static vector<clsMaintenance> GetMaintRequestsListByStatus(enMaintenanceStatus MaintStatus)
    {

        vector<clsMaintenance> vMaintenanceRequests = _LoadMaintenanceRequestsDataFromFile();
        vector<clsMaintenance> vMainRequests;
        for (clsMaintenance& request : vMaintenanceRequests)
        {
            if (request.Status == MaintStatus)
            {
                vMainRequests.push_back(request);
            }
        }
        return vMainRequests;
    }

    static vector<clsMaintenance> GetMaintRequestsListByPriority(enPriorityLevel PriorityLevel)
    {

        vector<clsMaintenance> vMaintenanceRequests = _LoadMaintenanceRequestsDataFromFile();
        vector<clsMaintenance> vMainRequests;
        for (clsMaintenance& request : vMaintenanceRequests)
        {
            if (request.Priority == PriorityLevel)
            {
                vMainRequests.push_back(request);
            }
        }
        return vMainRequests;
    }



    static clsMaintenance FindMaintRequestExistByStatus(string RequestId, enMaintenanceStatus MaintStatus)
    {
        vector<clsMaintenance> vMaintenanceRequests = _LoadMaintenanceRequestsDataFromFile();

        for (clsMaintenance& request : vMaintenanceRequests)
        {
            if (request.RequestID == RequestId && request.Status == MaintStatus)
                return request;
        }

        return _GetEmptyMaintenanceObject(); // returns empty if not found


    }

    static bool IsMaintRequestExistByStatus(string RequestId, enMaintenanceStatus MaintStatus)
    {
        clsMaintenance MaintRequest = clsMaintenance::FindMaintRequestExistByStatus(RequestId, MaintStatus);
        return !(MaintRequest.IsEmpty());
    }

    static clsMaintenance FindRequestByStuffId(string StuffId)
    {

        vector<clsMaintenance> vMaintenanceRequests = _LoadMaintenanceRequestsDataFromFile();

        for (clsMaintenance& request : vMaintenanceRequests)
        {
            if (request.AssignedStaffID == StuffId)
                return request;
        }

        return _GetEmptyMaintenanceObject();


    }
    
    static bool IsRequestExistByStuffId(string StuffId)
    {

        clsMaintenance MainRequestByStuffId = FindRequestByStuffId(StuffId);
        return !(MainRequestByStuffId.IsEmpty());

    }

    static int CountRequestsByStatus(enMaintenanceStatus MaintStatus)
    {
        return GetMaintRequestsListByStatus(MaintStatus).size();

    }

    static int CountRequestsByPriority(enPriorityLevel PriorityLevel)
    {
        return GetMaintRequestsListByPriority(PriorityLevel).size();

    }



};

