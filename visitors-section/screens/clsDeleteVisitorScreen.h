#pragma once

#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsVisitor.h"
#include "clsInputValidate.h"
#include "clsGlobalPrint.h"

using namespace std;

class clsDeleteVisitorScreen : protected clsBase
{
private:

    static void _PrintSpecificVisitorRecordLine(clsVisitor Visitor)
    {
        cout << setw(ScreenWidth - 10) << left << "" << Green << "| " << White << setw(15) << left << Visitor.VisitorID;
        cout << Green << "| " << White << setw(25) << left << Visitor.FullName();
        cout << Green << "| " << White << setw(20) << left << Visitor.VisitedDepartment;
        cout << Green << "| " << White << setw(20) << left << Visitor.VisitedRoom;
        cout << Green << "| " << White << setw(10) << left
            << (Visitor.VisitorStatus == clsVisitor::enVisitorStatus::eInside ? "Inside" : "Exited");
    }

    static void _PrintSpecificVisitorHeader()
    {
        cout << "\n" << setw(ScreenWidth - 10) << left << "" << Green
            << "--------------------------------------------------------------------------------------------------------------\n" << White;

        cout << setw(ScreenWidth - 10) << left << "" << Green << "| " << Yellow << setw(15) << left << "Visitor ID";
        cout << Green << "| " << Yellow << setw(25) << left << "Full Name";
        cout << Green << "| " << Yellow << setw(20) << left << "Department";
        cout << Green << "| " << Yellow << setw(20) << left << "Room";
        cout << Green << "| " << Yellow << setw(10) << left << "Status" << White;

        cout << "\n" << setw(ScreenWidth - 10) << left << "" << Green
            << "--------------------------------------------------------------------------------------------------------------\n" << White;
    }

    static void _PrintSmallVisitorListInfo()
    {
        vector<clsVisitor> vVisitors = clsVisitor::GetVisitorList();

        if (vVisitors.size() == 0)
        {
            cout << setw(ScreenWidth) << "" << left << Red << "No Visitor Available In the System!\n" << White;
        }
        else
        {
            _PrintSpecificVisitorHeader();

            for (clsVisitor& visitor : vVisitors)
            {
                _PrintSpecificVisitorRecordLine(visitor);
                cout << endl;
            }

            cout << setw(ScreenWidth - 10) << left << "" << Green
                << "--------------------------------------------------------------------------------------------------------------" << White << endl;
        }
    }

    static string ReadVisitorIdToDelete()
    {
        cout << "\n" << setw(ScreenWidth) << "" << left << "Please Enter Visitor ID that you want to delete: ";
        string VisitorID = clsInputValidate::ReadString();

        while (!clsVisitor::IsVisitorExist(VisitorID))
        {
            cout << clsUtil::Yellow() << "\n" << setw(ScreenWidth) << "" << left
                << "Visitor not found, please enter a valid one or type 'exit' to cancel: " << White;

            VisitorID = clsInputValidate::ReadString();
 
        }

        return VisitorID;
    }

public:

    static void ShowDeleteVisitorScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t\tDelete Visitor Screen\n");

        if (clsInputValidate::IsSureToPerform())
        {

            _PrintSmallVisitorListInfo();

            string VisitorID = ReadVisitorIdToDelete();

            clsVisitor VisitorToDelete = clsVisitor::FindVisitor(VisitorID);
            if (!VisitorToDelete.IsEmpty())
            {

                clsGlobalPrint::PrintFullVisitorInfo(VisitorToDelete);

                cout << "\n" << setw(ScreenWidth) << "" << left<< "Are you sure you want to delete this visitor permanently? [Y/N]: ";
                if (clsInputValidate::IsAnswerIsYes())
                {
                    if (VisitorToDelete.DeleteVisitor())
                    {
                        cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Visitor Deleted Successfully :-)\n" << White;
                    }
                    else
                    {
                        cout << Red << "\n" << setw(ScreenWidth) << "" << left<< "Error: Visitor was not deleted!\n" << White << endl;
                    }
                }
            }
            else
            {
                cout << "\n" << setw(ScreenWidth) << "" << left << Red << "!Error! the object is not found \n" << White;

            }

        }




    }
};
