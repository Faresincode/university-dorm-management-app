#pragma once
#include <iostream>
#include "clsPerson.h";
#include "clsStudentInfo.h";
#include "Global.h";
#include <vector> 
#include "clsString.h";



using namespace std;

class clsStudentDorm : public clsStudentInfo
{
protected:

    enum enMealPlan { eNoMeal = 0, eFull = 1, eBreakfast = 2, eDinner = 3 };
    enMealPlan _MealPlan;
    enum enStatus ;
    enStatus _Status;
    struct stComplaint;

private:
    friend class clsUpdateDormStudentScreen;
    friend class clsAddNewDormStudentScreen;

    enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };

    enMode _Mode;
    string _ResidenceName;
    char _DormBuilding;
    short _RoomNumber;
    short _BedNumber;
    string _AdmissionDate;
    string _CheckoutDate;
    string _StudentDormId;
    bool   _MarkedForDelete = false;


    static clsStudentDorm _ConvertLineToClientObject(string Line)
    {
        vector<string> vClientData = clsString::Split(Line, FileSeparator);

        return clsStudentDorm
        (
            enMode::eUpdateMode,
            vClientData[0],                                      // StudentDormId
            vClientData[1],                                      // StudentID
            vClientData[2],                                      // FirstName
            vClientData[3],                                      // LastName
            (clsPerson::enGender)stoi(vClientData[4]),           // Gender
            vClientData[5],                                      // DateOfBirth
            vClientData[6],                                      // Nationality
            vClientData[7],                                      // Email
            vClientData[8],                                      // Phone
            vClientData[9],                                      // UniversityName
            vClientData[10],                                     // Faculty
            vClientData[11],                                     // Department
            (clsStudentInfo::enYearLevel)stoi(vClientData[12]),  // YearLevel
            vClientData[13],                                     // Speciality
            vClientData[14],                                     // ResidenceName
            stoi(vClientData[15]),                               // DormBuilding
            stoi(vClientData[16]),                               // RoomNumber
            stoi(vClientData[17]),                               // BedNumber
            vClientData[18],                                     // AdmissionDate
            vClientData[19],                                     // CheckoutDate
            (enStatus)stoi(vClientData[20]),                     // Status
            (enMealPlan)stoi(vClientData[21])                    // MealPlan
        );


    }

    static  vector <clsStudentDorm> _LoadStudentsDormDataFromFile()
    {

        vector <clsStudentDorm> vClients;
        fstream MyFile;
        MyFile.open(StudentsDormFileName, ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {

                clsStudentDorm Client = _ConvertLineToClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static string _ConvertStudentDormObjectToLine(clsStudentDorm StudentDormObject)
    {
        string StudentDormRecord = "";
        StudentDormRecord += StudentDormObject.StudentDormId + FileSeparator;
        StudentDormRecord += StudentDormObject.StudentID + FileSeparator;
        StudentDormRecord += StudentDormObject.FirstName + FileSeparator;
        StudentDormRecord += StudentDormObject.LastName + FileSeparator;
        StudentDormRecord += to_string(StudentDormObject.Gender) + FileSeparator;
        StudentDormRecord += StudentDormObject.DateOfBirth + FileSeparator;
        StudentDormRecord += StudentDormObject.Nationality + FileSeparator;
        StudentDormRecord += StudentDormObject.Email + FileSeparator;
        StudentDormRecord += StudentDormObject.Phone + FileSeparator;
        StudentDormRecord += StudentDormObject.UniversityName + FileSeparator;
        StudentDormRecord += StudentDormObject.Faculty + FileSeparator;
        StudentDormRecord += StudentDormObject.Department + FileSeparator;
        StudentDormRecord += to_string(StudentDormObject.YearLevel) + FileSeparator;
        StudentDormRecord += StudentDormObject.Speciality + FileSeparator;
        StudentDormRecord += StudentDormObject.ResidenceName + FileSeparator;
        StudentDormRecord += to_string((int)StudentDormObject.DormBuilding) + FileSeparator;
        StudentDormRecord += to_string(StudentDormObject.RoomNumber) + FileSeparator;
        StudentDormRecord += to_string(StudentDormObject.BedNumber) + FileSeparator;
        StudentDormRecord += StudentDormObject.AdmissionDate + FileSeparator;
        StudentDormRecord += StudentDormObject.CheckoutDate + FileSeparator;
        StudentDormRecord += to_string(StudentDormObject.Status) + FileSeparator;
        StudentDormRecord += to_string(StudentDormObject._MealPlan);

        return StudentDormRecord;
    }

    static void _SaveStudentsDormDataToFile(vector<clsStudentDorm> vDormStudents)
    {

        fstream MyFile;
        MyFile.open(StudentsDormFileName, ios::out);//overwrite
        if (MyFile.is_open())
        {
            for (clsStudentDorm& C : vDormStudents)
            {
                if (C._MarkedForDelete == false)
                {
                    MyFile << _ConvertStudentDormObjectToLine(C) << endl;
                }
            }
            MyFile.close();
        }




    }

    static string _PrepareComplaintLine(stComplaint Complain)
    {

        string ComplainRecord = "";

        ComplainRecord += Complain.ComplaintID + FileSeparator;
        ComplainRecord += Complain.StudentDormId + FileSeparator;
        Complain.ComplaintDate = clsDate::GetSystemDateAsFormat("yy-mm-dd");
        ComplainRecord += Complain.ComplaintDate + FileSeparator;
        ComplainRecord += to_string(Complain.ComplaintCategory) + FileSeparator;
        ComplainRecord += Complain.Description + FileSeparator;
        ComplainRecord += to_string(Complain.ComplainStatus) + FileSeparator;
        ComplainRecord += Complain.ResolvedDate;
        return ComplainRecord;
    }

    static stComplaint _ConvertLineToComplainRecord(string Line)
    {
        stComplaint Complain;
        vector<string> vComplaints = clsString::Split(Line, FileSeparator);
        Complain.ComplaintID = vComplaints[0];
        Complain.StudentDormId = vComplaints[1];
        Complain.ComplaintDate = vComplaints[2];
        Complain.ComplaintCategory = (enComplaintCategory)stoi(vComplaints[3]);
        Complain.Description = vComplaints[4];
        Complain.ComplainStatus = (enComplainStatus)stoi(vComplaints[5]);
        Complain.ResolvedDate = vComplaints[6];

        return Complain;

    }

    static vector<stComplaint> _LoadComplaintsFromFile()
    {

        vector<stComplaint> vComplaints;
        fstream MyFile;
        MyFile.open(StudentsDormComplaintsFileName, ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                stComplaint Complain = _ConvertLineToComplainRecord(Line);
                vComplaints.push_back(Complain);

            }

            MyFile.close();

        }

        return vComplaints;
    }

    bool _Update()
    {

        vector <clsStudentDorm> vStudents = GetStudentsDormList();
        for (clsStudentDorm& Student : vStudents)
        {
            if (Student.StudentDormId == StudentDormId)
            {
                Student = *this;
                _SaveStudentsDormDataToFile(vStudents);
                return true;
            }
        }
        return false;
    }


    void _AddNew()
    {

        clsUtil::AddDataLineToFile(_ConvertStudentDormObjectToLine(*this), StudentsDormFileName);
    }



    static clsStudentDorm _GetEmptyStudentDormObject()
    {
        return clsStudentDorm(enMode::eEmptyMode, "", "", "", "", clsPerson::enGender::eNoGender, "", "", "", "", "", "", "", (clsStudentInfo::enYearLevel::NoLevel),"", "", ' ', 0, 0, "", "", enStatus::eNoStatus, enMealPlan::eNoMeal);

    }



public:

    enum enComplaintCategory { eMaintenance = 1, eCleanliness = 2, eNoise = 3, eFood = 4, eSecurity = 5, eOther = 6 };
    enum enComplainStatus { eInPending = 1, eInProgress = 2, eResolved = 3, eDismissed = 4};
    enum enStatus { eChecked_out = 1, eActive = 2, eSuspended = 3, eTransferred = 4, ePending = 5, eNoStatus = 6 };
    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildDormStudentExist = 2 };

    clsStudentDorm(enMode Mode, string StudentDormId,string StudentID,string FirstName,string LastName,enGender Gender,string DateOfBirth,
        string Nationality,string Email,string Phone,string UniversityName,string Faculty,string Department,enYearLevel YearLevel,string Speciality,string ResidenceName,
        char DormBuilding,short RoomNumber,short BedNumber,string AdmissionDate,string CheckoutDate,enStatus Status,enMealPlan MealPlan)
       
        :clsStudentInfo( FirstName,LastName, Gender,DateOfBirth,Nationality,Email,Phone,StudentID,UniversityName,Faculty,Department,YearLevel,Speciality)
    
    {
        _Mode = Mode;
        _StudentDormId = StudentDormId;
        _ResidenceName = ResidenceName;
        _DormBuilding = DormBuilding;
        _RoomNumber  = RoomNumber;
        _BedNumber  = BedNumber;
        _AdmissionDate  = AdmissionDate;
        _CheckoutDate = CheckoutDate;
        _Status = Status;
        _MealPlan = MealPlan;
        
    }

    static clsStudentDorm FindByDormId(string StudentDormId)
    {
        vector <clsStudentDorm> vStudents = GetStudentsDormList();
        for (clsStudentDorm& Student : vStudents)
        {
            if (Student.StudentDormId == StudentDormId)
            {
                return Student;
            }
        }
        return _GetEmptyStudentDormObject();
    }

    static clsStudentDorm FindByStudentId(string StudentId)
    {
        vector <clsStudentDorm> vStudents = GetStudentsDormList();
        for (clsStudentDorm& Student : vStudents)
        {
            if (Student.StudentID == StudentId)
            {
                return Student;
            }
        }
        return _GetEmptyStudentDormObject();
    }


    static clsStudentDorm FindByDormIDAndStudentId(string StudentDormId, string StudentId)
    {
        vector <clsStudentDorm> vStudents = GetStudentsDormList();
        for (clsStudentDorm& Student : vStudents)
        {
            if (Student.StudentDormId == StudentDormId && Student.StudentID == StudentId)
            {
                return Student;
            }
        }
        return _GetEmptyStudentDormObject();
    }

    static clsStudentDorm GetAddNewStudentDormObject(string DormStudentId )
    {
        return clsStudentDorm(enMode::eAddNewMode, DormStudentId, "", "", "", clsPerson::enGender::eNoGender, "", "", "", "", "", "", "", (clsStudentInfo::enYearLevel::NoLevel),"", "", ' ', 0, 0, "", "", enStatus::eNoStatus, enMealPlan::eNoMeal);
    }

    static clsStudentDorm GetUpdateStudentDormObject(string DormStudentId)
    {
        return clsStudentDorm(enMode::eUpdateMode, DormStudentId, "", "", "", clsPerson::enGender::eNoGender, "", "", "", "", "", "", "", (clsStudentInfo::enYearLevel::NoLevel), "", "", ' ', 0, 0, "", "", enStatus::eNoStatus, enMealPlan::eNoMeal);
    }


    //_____________________________________________ Properties set and get ______________________________________________
    
    void SetStudentDormId(string StudentDormId)
    {
        _StudentDormId = StudentDormId;
    }
    string GetStudentDormId()
    {
        return _StudentDormId;
    }
    __declspec(property(get = GetStudentDormId, put = SetStudentDormId)) string StudentDormId;

    string GetResidenceName()
    {
        return _ResidenceName;
    }
    void SetResidenceName(string ResidenceName)
    {
        _ResidenceName = ResidenceName;
    }
    __declspec(property(get = GetResidenceName, put = SetResidenceName)) string ResidenceName;

    void SetDormBuilding(char DormBuilding)
    {
        _DormBuilding = DormBuilding;
    }
     char GetDormBuilding()
    {
        return _DormBuilding;
    }
    __declspec(property(get = GetDormBuilding, put = SetDormBuilding)) char DormBuilding;

    void SetRoomNumber(short RoomNumber)
    {
        _RoomNumber = RoomNumber;
    }
    short GetRoomNumber()
    {
        return _RoomNumber;
    }
    __declspec(property(get = GetRoomNumber, put = SetRoomNumber)) short RoomNumber;

    void SetBedNumber(short BedNumber)
    {
        _BedNumber = BedNumber;
    }
     short GetBedNumber()
    {
        return _BedNumber;
    }
    __declspec(property(get = GetBedNumber, put = SetBedNumber)) short BedNumber;

    void SetAdmissionDate(string AdmissionDate)
    {
        _AdmissionDate = AdmissionDate;
    }
     string GetAdmissionDate()
    {
        return _AdmissionDate;
    }
    __declspec(property(get = GetAdmissionDate, put = SetAdmissionDate)) string AdmissionDate;

    void SetCheckoutDate(string CheckoutDate)
    {
        _CheckoutDate = CheckoutDate;
    }
    const string GetCheckoutDate()
    {
        return _CheckoutDate;
    }
    __declspec(property(get = GetCheckoutDate, put = SetCheckoutDate)) string CheckoutDate;

    void SetStatus(enStatus Status)
    {
        _Status = Status;
    }
    enStatus GetStatus()
    {
        return _Status;
    }
    __declspec(property(get = GetStatus, put = SetStatus)) enStatus Status;

    void SetMealPlan(enMealPlan MealPlan)
    {
        _MealPlan = MealPlan;
    }
    enMealPlan GetMealPlan()
    {
        return _MealPlan;
    }
    __declspec(property(get = GetMealPlan, put = SetMealPlan)) enMealPlan MealPlan;
    //______________________________________________ End Properties ________________________________________________________

    bool IsEmpty()
    {
        return (_Mode == enMode::eEmptyMode);
    }

    static vector<clsStudentDorm> GetStudentsDormList()
    {
        return _LoadStudentsDormDataFromFile();
    }

    static bool IsDormStudentExist(string StudentDormId)
    {

        clsStudentDorm Student = clsStudentDorm::FindByDormId(StudentDormId);
        return !(Student.IsEmpty());
    }

    static int TotalStudentsNumber()
    {

        return GetStudentsDormList().size();
    }

    enSaveResults Save()
    {
        switch (_Mode)
        {

        case enMode::eEmptyMode:
            return enSaveResults::svFaildEmptyObject;

        case enMode::eUpdateMode:
            _Update();
            return enSaveResults::svSucceeded;

        case enMode::eAddNewMode:

            if (clsStudentDorm::IsDormStudentExist(_StudentDormId))
            {
                return enSaveResults::svFaildDormStudentExist;
            }
            else
            {
                _AddNew();
                _Mode = enMode::eUpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
    }

    bool Delete()
    {
        vector <clsStudentDorm> vStudents = _LoadStudentsDormDataFromFile();
        for (clsStudentDorm& Student : vStudents)
        {
            if (Student.StudentDormId == StudentDormId)
            {
                Student._MarkedForDelete = true;
                _SaveStudentsDormDataToFile(vStudents);
                *this = _GetEmptyStudentDormObject();
                return true;
            }
        }
        return false;
    }

    static int GetStudentsCountByStatus(enStatus Status, vector <clsStudentDorm> vStudentsList)
    {

        //vector <clsStudentDorm> vStudents = GetStudentsDormList();
        int Counter=0;
        for (clsStudentDorm& Student : vStudentsList)
        {

            if (Student.Status== Status)
            {
                Counter++;
            }
        }
        return Counter;
    }

    static bool CheckOut(string StudentDormId)
    {
        
        clsStudentDorm Student= clsStudentDorm::FindByDormId(StudentDormId);
        Student.Status = enStatus::eChecked_out;
        return (Student.Save()==enSaveResults::svSucceeded) ? true : false;

    }

    static bool TransferInternal(string StudentDormId, char NewDormBuilding, short NewRoomNumber)
    {

        clsStudentDorm Student = clsStudentDorm::FindByDormId(StudentDormId);
        Student.DormBuilding = NewDormBuilding;
        Student.RoomNumber = NewRoomNumber;
        return (Student.Save() == enSaveResults::svSucceeded) ? true : false;


    }

    struct stComplaint
    {
        string StudentDormId;
        string ComplaintDate;
        enComplaintCategory ComplaintCategory;
        enComplainStatus ComplainStatus;
        string Description;
        string ResolvedDate;
        string ComplaintID ="CP" + to_string(clsUtil::RandomNumber<int>(10, 1000));

    };

    static void  RecordComplaint(stComplaint Complain)
    {
         clsUtil::AddDataLineToFile(_PrepareComplaintLine(Complain),StudentsDormComplaintsFileName);
    }

    static vector<stComplaint> GetComplaintsList()
    {

        return _LoadComplaintsFromFile();
    }

    static string GetStatusString(clsStudentDorm::enStatus status)
    {
        switch (status)
        {
        case enStatus::eActive:
            return "Active";
        case enStatus::eChecked_out:
            return "Checked out";
        case enStatus::eNoStatus:
            return "No Status";
        case enStatus::ePending:
            return "Pending";
        case enStatus::eSuspended:
            return "Suspended";
        case enStatus::eTransferred:
            return "Transferred";
        default:
            return "";

        }
    }

    static string GetMealPlanString(enMealPlan MealPlan)
    {

        switch (MealPlan)
        {
        case enMealPlan::eDinner:
            return "Dinner";
        case enMealPlan::eBreakfast:
            return "Breakfast";
        case enMealPlan::eFull:
            return "Full";
        default:
            return "eNoMeal";
            break;
        }
    }


    static string GetStudentComplainStatusString(enComplainStatus ComplainStatus)
    {
        switch (ComplainStatus)
        {
        case clsStudentDorm::eInPending:
            return "InPending";
        case clsStudentDorm::eInProgress:
            return "InProgress";
        case clsStudentDorm::eResolved:
            return "Resolved";
        case clsStudentDorm::eDismissed:
            return "Dismissed";
        default:
            return  "No CP Status";
        }

    }

    static string GetComplainCategoriesStatusString(enComplaintCategory ComplaintCategory)
    {

        switch (ComplaintCategory)
        {
        case clsStudentDorm::eMaintenance:
            return "Maintenance";
        case clsStudentDorm::eCleanliness:
            return "Cleanliness";
        case clsStudentDorm::eNoise:
            return "Noise";
        case clsStudentDorm::eFood:
            return "Food";
        case clsStudentDorm::eSecurity:
            return "Security";
        case clsStudentDorm::eOther:
            return "Other";
        default:
            return "No CG Status";
        }

    }


    static int GetStudentsCountPerDormBuilding(char DormBuilding, vector <clsStudentDorm> vStudentsList)
    {

        //vector <clsStudentDorm> vStudents = GetStudentsDormList();
        int Counter = 0;
        for (clsStudentDorm& Student : vStudentsList)
        {

            if (Student.DormBuilding == DormBuilding)
            {
                Counter++;
            }
        }
        return Counter;




    }

    static int GetStudentsCountPerRoomNumber(short  roomNumber, vector <clsStudentDorm> vStudentsList)
    {

        //vector <clsStudentDorm> vStudents = GetStudentsDormList();
        int Counter = 0;
        for (clsStudentDorm& Student : vStudentsList)
        {

            if (Student.RoomNumber == roomNumber)
            {
                Counter++;
            }
        }
        return Counter;

    }

    static int GetCountComplaintPerCategories(enComplaintCategory ComplaintCategory,vector<stComplaint>vComplains)
    {

        int Counter = 0;
        for (stComplaint& Complain : vComplains)
        {
            if (Complain.ComplaintCategory == ComplaintCategory)
            {
                Counter++;
            }
        }
        return Counter;

    }

    static int GetCountComplainPerStatus(enComplainStatus ComplainStatus, vector<stComplaint>vComplains)
    {

        int Counter = 0;
        for (stComplaint& Complain : vComplains)
        {
            if (Complain.ComplainStatus == ComplainStatus)
            {
                Counter++;
            }
        }
        return Counter;

    }




};

