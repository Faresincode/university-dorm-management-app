
#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsVisitor.h"

using namespace std;

class clsVisitorLogListScreen : protected clsBase
{

private:
    friend class clsMarkVisitorExitScreen;

    static void PrintVisitorTableRecordLine(clsVisitor Visitor)
    {
        cout << setw(2) << left << "" << Green << "| " << White << setw(12) << left << Visitor.VisitorID;
        cout << Green << "| " << White << setw(20) << left << Visitor.FirstName + " " + Visitor.LastName;
        cout << Green << "| " << White << setw(20) << left << Visitor.VisitPurpose;
        cout << Green << "| " << White << setw(20) << left << Visitor.VisitedDepartment;
        cout << Green << "| " << White << setw(6 ) << left << Visitor.VisitedRoom;
        cout << Green << "| " << White << setw(8 ) << left << clsVisitor::VisitorStatusString(Visitor.VisitorStatus);
        cout << Green << "| " << White << setw(22) << left << Visitor.VisitDateTime;
        cout << Green << "| " << White << setw(22) << left << Visitor.ExitDateTime;
    }

    static void PrintVisitorTableHeader()
    {
        cout << "\n" << setw(1) << left << "" << Green<< "__________________________________________________________________________________________________________________________________________________\n\n"<< White;

        cout << setw(2) << left << "" << Green << "| " << White << setw(12) << left << "Visitor ID";
        cout << Green << "| " << White << setw(20) << left << "Full Name";
        cout << Green << "| " << White << setw(20) << left << "Visit Purpose";
        cout << Green << "| " << White << setw(20) << left << "Department";
        cout << Green << "| " << White << setw(6 ) << left << "Room";
        cout << Green << "| " << White << setw(8 ) << left << "Status";
        cout << Green << "| " << White << setw(22) << left << "Visit Time";
        cout << Green << "| " << White << setw(22) << left << "Exit Time";

        cout << "\n" << setw(1) << left << "" << Green<< "__________________________________________________________________________________________________________________________________________________\n\n"<< White;
    }

    static void PrintVisitorTable(vector<clsVisitor> vVisitors)
    {
        PrintVisitorTableHeader();

        for (clsVisitor& Visitor : vVisitors)
        {
            PrintVisitorTableRecordLine(Visitor);
            cout << endl;
        }

        cout << setw(1) << left << "" << Green<< "__________________________________________________________________________________________________________________________________________________"<< White << endl;

    }

public:

    static void ShowVisitorLogScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t     Visitor Log List");

        if (clsInputValidate::IsSureToPerform())
        {
            system("cls");
            vector<clsVisitor> vVisitors = clsVisitor::GetVisitorList();
            string Subtitle = "\t\t(" + to_string(vVisitors.size()) + ") Visitors";
            clsBase::_DrawScreenHeader("\t     Visitor Log List", Subtitle);
            if (vVisitors.empty())
            {
                cout << "\n" << setw(ScreenWidth) << left << "" <<Red<< "No Visitor Exist In This Dorm Now" << White<<endl;

            }
            else
            {
                PrintVisitorTable(vVisitors);
            }

        }



    }

};
