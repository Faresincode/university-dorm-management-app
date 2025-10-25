
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

class clsFindVisitorScreen : protected clsBase
{


public:

    static void ShowFindVisitorScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t   Find Visitor Screen");

        if (clsInputValidate::IsSureToPerform())
        {

            string VisitorID = clsGlobalRead::ReadVisitorId();

            clsVisitor Visitor = clsVisitor::FindVisitor(VisitorID);

            if (!Visitor.IsEmpty())
            {
                cout << "\n";
                clsGlobalPrint::PrintFullVisitorInfo(Visitor);
            }
            else
            {
                cout << "\n" << setw(ScreenWidth) << left << ""<< Red << "Visitor with ID (" << VisitorID << ") was not found!"<< White << endl;
            }

        }

    }

};
