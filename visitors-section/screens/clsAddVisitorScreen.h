
#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsVisitor.h"
#include "clsGlobalRead.h"
#include "clsGlobalPrint.h"
#include "clsUtil.h";
using namespace std;

class clsAddVisitorScreen : protected clsBase
{

private:

    static clsVisitor ReadVisitorInfo()
    {
        clsVisitor NewVisitor = clsVisitor::GetAddNewVisitorObject();

        cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "Read Visitor Info: \n\n" << White;

        NewVisitor.VisitorID = clsUtil::GenerateID("VIS");

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter First Name: ";
        NewVisitor.FirstName = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Last Name: ";
        NewVisitor.LastName = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Visit Purpose: ";
        NewVisitor.VisitPurpose = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Department Visitor Will Visit: ";
        NewVisitor.VisitedDepartment = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Room Visitor Will Visit: ";
        NewVisitor.VisitedRoom = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Security ID Who Allows Visitor: ";
        NewVisitor.SecurityID = clsInputValidate::ReadString();

        // Default visitor status is "Inside"
        NewVisitor.VisitorStatus = clsVisitor::eInside;

        NewVisitor.VisitDateTime = clsDate::GetSystemDateTimeString();
        NewVisitor.ExitDateTime = "0";

        return NewVisitor;
    }

public:

    static void ShowAddVisitorScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t\tAdd New Visitor Screen");

        if (clsInputValidate::IsSureToPerform())
        {

            clsVisitor NewVisitor = ReadVisitorInfo();

            clsVisitor::enSaveResults SaveResult = NewVisitor.SaveVisitor();

            clsGlobalPrint::PrintResult(SaveResult, NewVisitor);

        }


    }

};

