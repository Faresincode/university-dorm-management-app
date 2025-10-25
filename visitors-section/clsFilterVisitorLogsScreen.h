
#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsBase.h"
#include "clsVisitor.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsGlobalPrint.h";
#include "clsGlobalRead.h";
#include "Global.h";

using namespace std;

class clsFilterVisitorLogsScreen : protected clsBase
{
private:

    static void GoBackToFiltredMenu()
    {

        //system("cls");
        cout << "\n\nPress any key to go Back To Filtred Menu\n\n";
        system("pause>0");
        ShowFilterVisitorLogsScreen();
    }

    enum enVisiteFiltredOption { eByVisitorsStatus = 1,eTodayVisitors=2, eByDepartment = 3, eByName = 4, eShowAll = 5, eExit = 6 };


    static void _PrintVisitorRecordLine(clsVisitor& Visitor)
    {
        cout << setw(2) << left << "" << Green << "| " << White << setw(10) << left << Visitor.VisitorID;
        cout << Green << "| " << White << setw(15) << left << Visitor.FirstName;
        cout << Green << "| " << White << setw(15) << left << Visitor.LastName;
        cout << Green << "| " << White << setw(15) << left << Visitor.VisitedDepartment;
        cout << Green << "| " << White << setw(8) << left << Visitor.VisitedRoom;
        cout << Green << "| " << White << setw(15) << left << clsVisitor::VisitorStatusString(Visitor.VisitorStatus);
        cout << Green << "| " << White << setw(22) << left << Visitor.VisitDateTime;
        cout << Green << "| " << White << setw(22) << left << Visitor.ExitDateTime;
        cout << endl;
    }

    static void _PrintTableHeader()
    {
        cout << "\n" << setw(1) << left << "" << Green<< "________________________________________________________________________________________________________________________________________________\n\n" << White;

        cout << setw(2) << left << "" << Green << "| " << White << setw(10) << left << "Visitor ID";
        cout << Green << "| " << White << setw(15) << left << "First Name";
        cout << Green << "| " << White << setw(15) << left << "Last Name";
        cout << Green << "| " << White << setw(15) << left << "Department";
        cout << Green << "| " << White << setw(8) << left << "Room";
        cout << Green << "| " << White << setw(15) << left << "Status";
        cout << Green << "| " << White << setw(22) << left << "Visit Time";
        cout << Green << "| " << White << setw(22) << left << "Exit Time";
        cout << endl;

        cout << setw(1) << left << "" << Green<< "________________________________________________________________________________________________________________________________________________\n" << White;
    }

    static void _ShowFilteredResults(vector<clsVisitor> vVisitors)
    {
        system("cls");
        string Subtitle = "\t\t(" + to_string(vVisitors.size()) + ") Visitor(s) Found";
        clsBase::_DrawScreenHeader("\tVisitor Log Filter Results", Subtitle);

        if (vVisitors.empty())
        {
            cout <<setw(ScreenWidth)<<""<<left << Red << "No matching visitor logs found!\n" << White;
            return;
        }
        _PrintTableHeader();
        for (clsVisitor& Visitor : vVisitors)
        {
            _PrintVisitorRecordLine(Visitor);
        }

        cout << setw(1) << left << "" << Green << "________________________________________________________________________________________________________________________________________________\n" << White;
    }

    static void _ShowVisitorsStatusScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\tVisitor Log Filter by status");

        cout << setw(ScreenWidth) << "" << left << "Enter Visitor status as following menu [ Entred = 1 ,Exited = 2 ]: ";
        short VisitorStatus =  (clsVisitor::enVisitorStatus)clsInputValidate::ReadNumberBetween<short>(1, 2);
        vector<clsVisitor>vFiltred= clsVisitor::GetVisitorListByStatus((clsVisitor::enVisitorStatus) VisitorStatus);
        _ShowFilteredResults(vFiltred);

    }
    
    static void _ShowTodayVisitors()
    {
        vector<clsVisitor>vFiltred = clsVisitor::GetTodayEntredVisitorsList();
        _ShowFilteredResults(vFiltred);

    }

    static void _ShowFiltredByeDepartment()
    {
        system("cls");

        clsBase::_DrawScreenHeader("\t   Filtred By Department");
         
        cout << setw(ScreenWidth) << "" << left << "Enter Visitor By Department to Visit: ";
        string  VisitorDepartment = clsInputValidate::ReadString();
        vector<clsVisitor> vFiltred = clsVisitor::GetVisitorListByVisitedDepartment(VisitorDepartment);
        _ShowFilteredResults(vFiltred);


    }
   
    static void _ShowFiltredByName()
    {
        system("cls");

        clsBase::_DrawScreenHeader("\t   Filtred By Name");
        cout << setw(ScreenWidth) << "" << left << "Enter First Name: ";
        string FirstName = clsInputValidate::ReadString();
        cout << setw(ScreenWidth) << "" << left << "Enter Last Name: ";
        string LastName = clsInputValidate::ReadString();
        vector<clsVisitor>vFiltred = clsVisitor::GetVisitorListByName(FirstName, LastName);
        _ShowFilteredResults(vFiltred);

    }

    static void _ShowFullList()
    {
       
        vector<clsVisitor>vFullList= clsVisitor::GetVisitorList();
        _ShowFilteredResults(vFullList);
    }

    static void  _PerformFiltredMenu(enVisiteFiltredOption Option )
    {
        vector<clsVisitor>vFiltred;
        switch (Option)
        {
            case enVisiteFiltredOption::eByVisitorsStatus:
            {
                system("cls");
                _ShowVisitorsStatusScreen();
                GoBackToFiltredMenu();
                break;
            }
            case enVisiteFiltredOption::eTodayVisitors:
            {
                system("cls");

                _ShowTodayVisitors();
                GoBackToFiltredMenu();
            }
            case clsFilterVisitorLogsScreen::eByDepartment:
            {
                system("cls");

                _ShowFiltredByeDepartment();
                GoBackToFiltredMenu();
                break;

            }
            case clsFilterVisitorLogsScreen::eByName:
            {
                system("cls");

                _ShowFiltredByName();
                GoBackToFiltredMenu();

                break;
            }
            case clsFilterVisitorLogsScreen::eShowAll:
            {
                system("cls");

                _ShowFullList();
                GoBackToFiltredMenu();
                break;
            }
            case clsFilterVisitorLogsScreen::eExit:
            {
                return;
                break;
            }
            default:
            {
                system("cls");
                GoBackToFiltredMenu();
                break;
            }

        }
    }

    static void _ShowFiltredMenu()
    {

        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n";
        cout << setw(ScreenWidth) << left << "" << Red << "\tFilter Options:\n";
        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;

        cout << setw(ScreenWidth) << left << "" << " [1]  By Visitor Status\n";
        cout << setw(ScreenWidth) << left << "" << " [2]  Today Visitors\n";
        cout << setw(ScreenWidth) << left << "" << " [3]  By Department\n";
        cout << setw(ScreenWidth) << left << "" << " [4]  By Name\n";
        cout << setw(ScreenWidth) << left << "" << " [5]  Show All Visitors \n";
        cout << setw(ScreenWidth) << left << "" << " [6]  Exit\n";

        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;

        cout << setw(ScreenWidth) << "" << left << "Choose an option [ From 1 To  6 ]: ";
        _PerformFiltredMenu((enVisiteFiltredOption)clsInputValidate::ReadNumberBetween<short>(1, 6));
    }

public:


    static void ShowFilterVisitorLogsScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\tFilter Visitor Logs");

        _ShowFiltredMenu();

        




    }
};

