#pragma once
#include <iostream>
using namespace std;

class clsPerson
{

private:

    string _NationalID;
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;
    string _DateOfBirth;



protected:
    enum enGender;
    enGender _Gender;
    string _Nationality;


public:

    enum enGender {eMale=77, eFemelle = 70, eNoGender = 48 };

    clsPerson(string FirstName, string LastName,enGender Gender,string DateOfBirth,string Nationality,string Email, string Phone)
    {

        _FirstName = FirstName;
        _LastName = LastName;
        _Gender =Gender;
        _DateOfBirth =DateOfBirth;
        _Nationality =Nationality;
        _Email = Email;
        _Phone = Phone;
    }

    //Property Set and Get 
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    const string GetFirstName()
    {
        return _FirstName;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    //Property Set and Get 
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }
    const string GetLastName()
    {
        return _LastName;
    }
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;

    //Property Set and Get 
    void SetEmail(string Email)
    {
        _Email = Email;
    }
    const string GetEmail()
    {
        return _Email;
    }
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;

    //Property Set and Get 
    void SetPhone(string Phone)
    {
        _Phone = Phone;
    }
    const string GetPhone()
    {
        return _Phone;
    }
    __declspec(property(get = GetPhone, put = SetPhone)) string Phone;
    // Gender
    void SetGender(enGender Gender)
    {
        _Gender = Gender;
    }
    const enGender GetGender()
    {
        return _Gender;
    }
    __declspec(property(get = GetGender, put = SetGender)) enGender Gender;

    // Nationality
    void SetNationality(string Nationality)
    {
        _Nationality = Nationality;
    }
    const string GetNationality()
    {
        return _Nationality;
    }
    __declspec(property(get = GetNationality, put = SetNationality)) string Nationality;

    // DateOfBirth
    void SetDateOfBirth(string DateOfBirth)
    {
        _DateOfBirth = DateOfBirth;
    }
    const string GetDateOfBirth()
    {
        return _DateOfBirth;
    }
    __declspec(property(get = GetDateOfBirth, put = SetDateOfBirth)) string DateOfBirth;


    void SetNationalID(string NationalID)
    {
        _NationalID = NationalID;
    }
    const string GetNationalID()
    {
        return _NationalID;
    }
    __declspec(property(get = GetNationalID, put = SetNationalID)) string NationalID;

    //Get Full Name
    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    static string GetGenderString(enGender Gender)
    {
        switch (Gender)
        {
        case clsPerson::eMale:
            return "Male";
        case clsPerson::eFemelle:
            return "Femelle";
        case clsPerson::eNoGender:
            return "No Gender";
        default:
            return "No Gender";
            break;
        }

    }

    //virtual void Print()
    //{                                                             
    //    cout << "\n" << setw(ScreenWidth) << ""<<left << Green << "---------------------------------------------" << White;
    //    cout << "\n" << setw(ScreenWidth) << "" << left <<Red<<   "             Personal Info:";
    //    cout << "\n" << setw(ScreenWidth) << "" << left << Green<<"---------------------------------------------"<<White;
    //    cout << "\n" << setw(ScreenWidth+1) << "" << left << Blue<<"FirstName     : " <<White<< _FirstName;
    //    cout << "\n" << setw(ScreenWidth+1) << "" << left << Blue<<"LastName      : " <<White<< _LastName;
    //    cout << "\n" << setw(ScreenWidth+1) << "" << left << Blue<<"Gender        : " <<White<< GetGenderString(_Gender);
    //    cout << "\n" << setw(ScreenWidth+1) << "" << left << Blue<<"Date Of Birth : " <<White<< _DateOfBirth;
    //    cout << "\n" << setw(ScreenWidth+1) << "" << left << Blue<<"Nationality   : " <<White<< _Nationality;
    //    cout << "\n" << setw(ScreenWidth+1) << "" << left << Blue<<"Email         : " <<White<< _Email;
    //    cout << "\n" << setw(ScreenWidth+1) << "" << left << Blue<<"Phone         : " <<White<< _Phone;
    //    cout << "\n" << setw(ScreenWidth) << "" << left <<Green <<"---------------------------------------------" <<White<< endl;

    //}





};



