#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsVisitor.h"
#include "clsGlobalPrint.h"
#include "clsGlobalRead.h"

using namespace std;

class clsUpdateVisitorInfoScreen : protected clsBase
{

private:


    enum enWhatToUpdate
    {
        eFirstName = 1,
        eLastName = 2,
        eVisitPurpose = 3,
        eVisitedDepartment = 4,
        eVisitedRoom = 5,
        eVisitorStatus = 6,
        eAll = 7
    };

    static void ReadVisitorInfoToUpdate(clsVisitor  Visitor)
    {

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter New First Name: ";
        Visitor.FirstName = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter New Last Name: ";
        Visitor.LastName = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Visit Purpose: ";
        Visitor.VisitPurpose = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Department Visitor Will Visit: ";
        Visitor.VisitedDepartment = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Room Visitor Will Visit: ";
        Visitor.VisitedRoom = clsInputValidate::ReadString();

        cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Visitor Status as following Menu:\n";
        cout << setw(ScreenWidth) << "" << left << "[1] Inside\n";
        cout << setw(ScreenWidth) << "" << left << "[2] Exited\n";
        Visitor.VisitorStatus = (clsVisitor::enVisitorStatus)clsInputValidate::ReadNumberBetween<short>(1, 2, "Enter status [1-2]: ");

    }



    static void _PerformUpdateMenuScreen(enWhatToUpdate WhatToUpdate, clsVisitor& Visitor)
    {
        switch (WhatToUpdate)
        {
        case enWhatToUpdate::eFirstName:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter New First Name: ";
            Visitor.FirstName = clsInputValidate::ReadString();
            break;
        }

        case enWhatToUpdate::eLastName:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter New Last Name: ";
            Visitor.LastName = clsInputValidate::ReadString();
            break;
        }

        case enWhatToUpdate::eVisitPurpose:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Visit Purpose: ";
            Visitor.VisitPurpose = clsInputValidate::ReadString();
            break;
        }

        case enWhatToUpdate::eVisitedDepartment:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Department Visitor Will Visit: ";
            Visitor.VisitedDepartment = clsInputValidate::ReadString();
            break;
        }

        case enWhatToUpdate::eVisitedRoom:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Room Visitor Will Visit: ";
            Visitor.VisitedRoom = clsInputValidate::ReadString();
            break;
        }

        case enWhatToUpdate::eVisitorStatus:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Visitor Status as following Menu:\n";
            cout << setw(ScreenWidth) << "" << left << "[1] Inside\n";
            cout << setw(ScreenWidth) << "" << left << "[2] Exited\n";
            short StatusChoice = clsInputValidate::ReadNumberBetween<short>(1, 2, "Enter status [1-2]: ");
            Visitor.VisitorStatus = (clsVisitor::enVisitorStatus)StatusChoice;
            break;
        }

        case enWhatToUpdate::eAll:
            ReadVisitorInfoToUpdate(Visitor);

        default:
        {
            ReadVisitorInfoToUpdate(Visitor);
            break;
        }
        }


    }

    static void _ShowUpdateMenuScreen(clsVisitor& Visitor)
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================";
        cout << "\n" << setw(ScreenWidth) << "" << left << Red << "    Update Visitor Info Menu Screen";
        cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================" << White;

        cout << "\n" << setw(ScreenWidth) << "" << left << " [1] First Name";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [2] Last Name";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [3] Visit Purpose";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [4] Visited Department";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [5] Visited Room";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [6] Visitor Status";
        cout << "\n" << setw(ScreenWidth) << "" << left << " [7] Update All";
        cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================\n\n";

        cout << setw(ScreenWidth) << "" << left << Yellow << "What do you want to update (answer from 1 to 7): " << White;
        _PerformUpdateMenuScreen((enWhatToUpdate)clsInputValidate::ReadNumberBetween<short>(1, 7), Visitor);
    }

public:

    static void ShowUpdateVisitorInfoScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t\tUpdate Visitor Information Screen\n");

        if (clsInputValidate::IsSureToPerform())
        {

            string VisitorId =clsGlobalRead::ReadVisitorId();

            clsVisitor Visitor = clsVisitor::FindVisitor(VisitorId);
            if (Visitor.IsEmpty())
            {
                clsGlobalPrint::PrintFullVisitorInfo(Visitor);
                _ShowUpdateMenuScreen(Visitor);

                clsVisitor::enSaveResults SaveResult = Visitor.SaveVisitor();
                clsGlobalPrint::PrintResult(SaveResult, Visitor);

            }
            else
            {
                cout << "\n" << setw(ScreenWidth) << ""<<Red << left << "!Error! Is Empty Object" << endl<<White;

            }


        }


    }

};
