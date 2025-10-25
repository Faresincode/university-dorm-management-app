#pragma once

#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsInputValidate.h";
#include "clsGlobalFunction.h";
#include "Global.h";
#include <string>


using namespace std;

class clsFinance
{

private:
    
    enum enFinanceMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2 };
    enum enPaymentMethod;
    string _PaymentID;
    string _StudentDormID;
    string _PaymentDateTime;
    double _Amount;
    string _Description;
    enPaymentMethod _PaymentMethod;
    enFinanceMode _FinanceMode;
    bool MarkForDelete = false;
    enum enPaymentStatus;
    enPaymentStatus _PaymentStatus;



    static string _ConvertFinanceObjectToLine(clsFinance Finance, string Separator = "#//#")
    {
        string Line = "";
        Line += Finance.PaymentID + Separator;
        Line += Finance.StudentDormID + Separator;
        Line += Finance.PaymentDateTime + Separator;
        Line += to_string(Finance.Amount) + Separator;
        Line += Finance.Description + Separator;
        Line += to_string(Finance.PaymentMethod) + Separator;
        Line += to_string(Finance.PaymentStatus);
        return Line;
    }


    static clsFinance _ConvertFinanceLineToObject(string Line, string Separator = "#//#")
    {
        vector<string> vData = clsString::Split(Line, Separator);

        return clsFinance(enFinanceMode::eUpdateMode,
            vData[0],              // PaymentID
            vData[1],              // StudentDormID
            vData[2],              // PaymentDate
            stod(vData[3]),        // Amount
            vData[4],              // Description
            (enPaymentMethod)stoi(vData[5]),
            (enPaymentStatus)stoi(vData[6]));
    }


    static vector<clsFinance> _LoadPaymentsDataFromFile()
    {
        vector<clsFinance> vPayments;
        fstream MyFile;
        MyFile.open(PaymentsDataFileName, ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsFinance Payment = _ConvertFinanceLineToObject(Line);
                vPayments.push_back(Payment);
            }
            MyFile.close();
        }
        return vPayments;
    }

    static void _SavePaymentsDataToFile(vector<clsFinance> vPayments)
    {
        fstream MyFile;
        MyFile.open(PaymentsDataFileName, ios::out);
        if (MyFile.is_open())
        {
            for (clsFinance& P : vPayments)
            {
                if (P.MarkForDelete == false)
                {
                    MyFile << _ConvertFinanceObjectToLine(P) << endl;

                }
            }
            MyFile.close();
        }
    }



    void _AddNewPayment()
    {

        clsGlobalFunction::AddPaymentRecordToFile(_ConvertFinanceObjectToLine(*this), PaymentsDataFileName);

    }

    bool _UpdatePayment()
    {

        vector<clsFinance> vPayments = _LoadPaymentsDataFromFile();
        for (clsFinance& Pay : vPayments)
        {
            if (Pay.PaymentID == PaymentID)
            {
                Pay = *this;
                _SavePaymentsDataToFile(vPayments);
                return true;
            }


        }
        return false;
    }

    static clsFinance _GetEmptyFinanceObject()
    {
        return clsFinance(enFinanceMode::eEmptyMode, "", "", "", 0.0, "", (enPaymentMethod)0,(enPaymentStatus)0);
    }

public:
    enum enPaymentMethod { eCash = 1, eCard = 2, eBankTransfer = 3 ,NoMethod=0 };
    enum enPaymentStatus
    {
        ePending = 1,      
        eCompleted = 2,    
        eFailed = 3,       
        eRefunded = 4,     
        eCancelled = 5 ,   
        eNoStatus=0
    };




    static string PaymentStatusString(enPaymentStatus PaymentStatus)
    {

        switch (PaymentStatus)
        {
        case clsFinance::ePending:
            return "Pending";
        case clsFinance::eCompleted:
            return "Completed";
        case clsFinance::eFailed:
            return "Failed";
        case clsFinance::eRefunded:
            return "Refunded";
        case clsFinance::eCancelled:
            return "Cancelled";
        default:
            "No Status";
            break;
        }
    }

    static string PaymentMethodString(enPaymentMethod PaymentMethod)
    {
        switch (PaymentMethod)
        {
        case clsFinance::eCash:
            return "Cash";
        case clsFinance::eCard:
            return "Card";
        case clsFinance::eBankTransfer:
            return "Bank Transfer";
        default:
            return "No Method";
        }

    }

    void SetPaymentID(string PaymentID) { _PaymentID = PaymentID; }
    string GetPaymentID() const { return _PaymentID; }
    __declspec(property(get = GetPaymentID, put = SetPaymentID)) string PaymentID;

    void SetStudentDormID(string StudentDormID) { _StudentDormID = StudentDormID; }
    string GetStudentDormID() const { return _StudentDormID; }
    __declspec(property(get = GetStudentDormID, put = SetStudentDormID)) string StudentDormID;

    void SetPaymentDateTime(string PaymentDate) { _PaymentDateTime = PaymentDate; }
    string GetPaymentDateTime() const { return _PaymentDateTime; }
    __declspec(property(get = GetPaymentDateTime, put = SetPaymentDateTime)) string PaymentDateTime;

    void SetAmount(double Amount) { _Amount = Amount; }
    double GetAmount() const { return _Amount; }
    __declspec(property(get = GetAmount, put = SetAmount)) double Amount;

    void SetDescription(string Description) { _Description = Description; }
    string GetDescription() const { return _Description; }
    __declspec(property(get = GetDescription, put = SetDescription)) string Description;

    void SetPaymentMethod(enPaymentMethod PaymentMethod) { _PaymentMethod = PaymentMethod; }
    enPaymentMethod GetPaymentMethod() const { return _PaymentMethod; }
    __declspec(property(get = GetPaymentMethod, put = SetPaymentMethod)) enPaymentMethod PaymentMethod;

    void SetPaymentStatus(enPaymentStatus PaymentStatus)
    {
        _PaymentStatus = PaymentStatus;
    }
    enPaymentStatus GetPaymentStatus() const
    {
        return _PaymentStatus;
    }
    __declspec(property(get = GetPaymentStatus, put = SetPaymentStatus)) enPaymentStatus PaymentStatus;


    clsFinance(enFinanceMode FinanceMode,string PaymentID, string StudentDormID, string PaymentDate,double Amount, string Description, enPaymentMethod PaymentMethod, enPaymentStatus PaymentStatus)
    {
        _FinanceMode = FinanceMode;
        _PaymentID = PaymentID;
        _StudentDormID = StudentDormID;
        _PaymentDateTime = PaymentDate;
        _Amount = Amount;
        _Description = Description;
        _PaymentMethod = PaymentMethod;
        _PaymentStatus = PaymentStatus;
    }

        // 🧱 Empty Object Factory


    static clsFinance GetUpdateFinanceObject()
    {
        return clsFinance(enFinanceMode::eUpdateMode, "", "", "", 0.0, "", (enPaymentMethod)0, (enPaymentStatus)0);
    }

    static clsFinance GetAddNewFinanceObject()
    {
        return clsFinance(enFinanceMode::eAddNewMode , "", "", "", 0.0, "", (enPaymentMethod)0,(enPaymentStatus)0);
    }


    static clsFinance FindPayment(string PaymentID)
    {
        vector<clsFinance> vPayments = _LoadPaymentsDataFromFile();

        for (clsFinance& Pay : vPayments)
        {
            if (Pay.PaymentID == PaymentID)
            {
                return Pay;
            }
        }

        return _GetEmptyFinanceObject();
    }

    bool DeletePayment()
   {
        vector<clsFinance> vPayments = _LoadPaymentsDataFromFile();
        for (clsFinance& Pay : vPayments)
        {
            if (Pay.PaymentID == PaymentID)
            {
                Pay.MarkForDelete = true;
                _SavePaymentsDataToFile(vPayments);
                return true;
            }
    
        }
        return false;
    }

    bool IsEmpty()
    {
        return _FinanceMode == enFinanceMode::eEmptyMode;
    }



    static bool IsPaymentExist(string PaymentID)
    {
        clsFinance Finance = clsFinance::FindPayment(PaymentID);
        return !(Finance.IsEmpty());
    }

    static clsFinance FindStudent(string DormStudentId)
    {

        vector<clsFinance> vPayments = _LoadPaymentsDataFromFile();

        for (clsFinance& Pay : vPayments)
        {
            if (Pay.StudentDormID == DormStudentId)
            {
                return Pay;
            }
        }

        return _GetEmptyFinanceObject();
    }

    static bool IsStudentExist(string DormStudentId)
    {
        clsFinance Finance = clsFinance::FindStudent(DormStudentId);
        return !(Finance.IsEmpty());
    }


    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildPaymentExist = 2 };

    enSaveResults Save()
    {
        switch (_FinanceMode)
        {

        case enFinanceMode::eEmptyMode:
            return enSaveResults::svFaildEmptyObject;

        case enFinanceMode::eUpdateMode:
            _UpdatePayment();
            return enSaveResults::svSucceeded;

        case enFinanceMode::eAddNewMode:

            if (clsFinance::IsPaymentExist( PaymentID))
            {
                return enSaveResults::svFaildPaymentExist;
            }
            else
            {
                _AddNewPayment();
                _FinanceMode = enFinanceMode::eUpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
    }


    static vector<clsFinance>GetPaymentsList()
    {
        return _LoadPaymentsDataFromFile();
    }


    static vector<clsFinance> GetPaymentsByStudent(string DormStudentId)
    {
        vector<clsFinance> vPayments= clsFinance::_LoadPaymentsDataFromFile();
        vector<clsFinance>vPaymentsStudent;
        for (clsFinance& payment : vPayments)
        {
            if (payment.StudentDormID == DormStudentId)
            {
                vPaymentsStudent.push_back(payment);
            }
        }
        return vPaymentsStudent;
    }


    static int CountPaymentsSByStatus(enPaymentStatus PaymentStatus)
    {

        vector<clsFinance> vPayments = clsFinance::_LoadPaymentsDataFromFile();
        int Counter = 0;
        for (clsFinance& payment : vPayments)
        {
            if (payment.PaymentStatus == PaymentStatus)
            {
                Counter++;
            }
        }
        return Counter;


    }

    static int CountPaymentsByMethod(enPaymentMethod PaymentMethod)
    {

        vector<clsFinance> vPayments = clsFinance::_LoadPaymentsDataFromFile();
        int Counter = 0;
        for (clsFinance& payment : vPayments)
        {
            if (payment.PaymentMethod == PaymentMethod)
            {
                Counter++;
            }
        }
        return Counter;

    }


    static int CountPaymentsMade(string StudentDormId)
    {

        vector<clsFinance> vPayments = clsFinance::_LoadPaymentsDataFromFile();
        int Counter = 0;
        for (clsFinance& payment : vPayments)
        {
            if (payment.StudentDormID == StudentDormId)
            {
                Counter++;
            }
        }
        return Counter;


    }

    static double CountTotalAmountPaid(string StudentDormId)
    {
        vector<clsFinance> vPayments = clsFinance::_LoadPaymentsDataFromFile();
        int Counter = 0;
        double TotalAmount = 0;
        for (clsFinance& payment : vPayments)
        {
            if (payment.StudentDormID == StudentDormId)
            {
                TotalAmount += payment.Amount;
            }
        }
        return TotalAmount;
    }


    static string  LastPaymentDateTime(string StudentDormId)
    {
        vector<clsFinance> vPayments = clsFinance::_LoadPaymentsDataFromFile();
        int Counter = 0;
        for (clsFinance& payment : vPayments)
        {
            if (payment.StudentDormID == StudentDormId)
            {
                Counter++;
            }
        }
        return vPayments[Counter].PaymentDateTime;
    }

    struct stPaymentDateCount
    {
        short PaymentCounter;
        double TotalPaymentAmount;
        short Month;
        short Year;

    };


    static stPaymentDateCount CountPaymentsByMonthAndYear(short Month,short Year)
    {
        stPaymentDateCount PaymentsInfo;
        vector<clsFinance> vPayments = clsFinance::_LoadPaymentsDataFromFile();
        PaymentsInfo.PaymentCounter = 0;
        PaymentsInfo.TotalPaymentAmount = 0;
        string OurMonth = "", OurYear="";
        for (clsFinance& payment : vPayments)
        {
            OurMonth += payment.PaymentDateTime[3];
            OurMonth += payment.PaymentDateTime[4];
            OurYear += payment.PaymentDateTime[6];
            OurYear += payment.PaymentDateTime[7];
            OurYear += payment.PaymentDateTime[8];
            OurYear += payment.PaymentDateTime[9];

            if (stoi(OurYear) == Year && stoi(OurMonth)== Month)
            {
                PaymentsInfo.PaymentCounter++;
                PaymentsInfo.TotalPaymentAmount += payment.Amount;
            }
            OurMonth = "";
            OurYear = "";
        }
        PaymentsInfo.Month = Month;
        PaymentsInfo.Year = Year;
        return PaymentsInfo;
    
    
    }

    struct stPaymentDate 
    {
        short Day;
        short Month;
        short Year;
        short Hour;
        short Minutes;
        short Seconds;
    };

    static bool IsMonthExist(string Month, string Year,vector<string> vDateList)
    {
        string MyMonth="", MyYear="";
        for (string& Date : vDateList)
        {
            MyMonth += Date[3];
            MyMonth += Date[4];
            MyYear += Date[6];
            MyYear += Date[7];
            MyYear += Date[8];
            MyYear += Date[9];
            if (Month == MyMonth && Year == MyYear)
            {
                return true;
            }
            MyMonth = "";
            MyYear = "";
        }
        return false;
    }

    static vector <string >GetPaymentsDateTimeList()
    {
        vector<string >vDates;
        string MyMonth = "", MyYear = "";

        vector<clsFinance>vPayments = _LoadPaymentsDataFromFile();
        for (clsFinance& payment : vPayments)
        {
            MyMonth += payment.PaymentDateTime[3];
            MyMonth += payment.PaymentDateTime[4];
            MyYear += payment.PaymentDateTime[6];
            MyYear += payment.PaymentDateTime[7];
            MyYear += payment.PaymentDateTime[8];
            MyYear += payment.PaymentDateTime[9];
            if (!IsMonthExist(MyMonth, MyYear,vDates))
            {
                vDates.push_back(payment.PaymentDateTime);
            }
            MyMonth = "";
            MyYear = "";

        }
        return vDates;
    }
    
    static vector<stPaymentDate> GetFiltredPaymentsDateTimeList()
    {

        vector<string> vPaymentsDatesTime = GetPaymentsDateTimeList();
        vector<stPaymentDate>vDateTime;
        stPaymentDate sDateTime;
        for (string& Date : vPaymentsDatesTime)
        {
            sDateTime.Day = stoi(Date.substr(0, 2));
            sDateTime.Month= stoi(Date.substr(3,2));
            sDateTime.Year = stoi(Date.substr(6, 4));
            sDateTime.Hour = stoi(Date.substr(13, 2));
            sDateTime.Minutes = stoi(Date.substr(16, 2));
            sDateTime.Seconds = stoi(Date.substr(19, 2));
            vDateTime.push_back(sDateTime);
        }
        return vDateTime;

    }
    

    static stPaymentDateCount TotalValidPaymentsInfo()
    {
        vector<clsFinance> vPayments = _LoadPaymentsDataFromFile();
        stPaymentDateCount PaymentInfo;
        PaymentInfo.PaymentCounter = 0;
        PaymentInfo.TotalPaymentAmount = 0;
        for (clsFinance& Pay : vPayments)
        {

            if (Pay.PaymentStatus == enPaymentStatus::eCompleted)
            {
                PaymentInfo.PaymentCounter++;
                PaymentInfo.TotalPaymentAmount += Pay.Amount;

            }

        }
        return PaymentInfo;

    }


};

