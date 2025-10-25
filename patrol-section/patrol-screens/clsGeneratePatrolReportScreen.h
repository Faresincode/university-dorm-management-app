#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "clsBase.h"
#include "clsPatrolSchedule.h"
#include "clsGlobalPrint.h"

using namespace std;

class clsGeneratePatrolReportScreen : protected clsBase
{
private:

    static void _PrintReportSummary(vector<clsPatrolSchedule> vSchedules)
    {


        clsPatrolSchedule::stSchedules Schedule = clsPatrolSchedule::CountStatusScheduleList();

        
        cout << "\n" << setw(ScreenWidth) << left <<"" << Green << "==========================================" << White;
        cout << "\n" << setw(ScreenWidth) << left <<"" << Yellow << "          Patrol Summary Report" << White;
        cout <<"\n"<< setw(ScreenWidth) << left <<"" << Green << "==========================================" << White;
        cout <<"\n"<< setw(ScreenWidth) << left << "" << " Total Patrols       : " << vSchedules.size();
        cout <<"\n"<< setw(ScreenWidth) << left << "" << " Completed           : " << Schedule.Completed;
        cout <<"\n"<< setw(ScreenWidth) << left << "" << " Pending             : " << Schedule.eScheduled ;
        cout <<"\n"<< setw(ScreenWidth) << left << "" << " In Progress         : " << Schedule.eInProgress ;
        cout <<"\n"<< setw(ScreenWidth) << left << "" << " Missed              : " << Schedule.eMissed ;
        cout <<"\n" << setw(ScreenWidth) << left << "" <<" Cancelled           : " << Schedule.Cancelled;
        cout << "\n" << setw(ScreenWidth) << left << "" << Green << "==========================================" << White << endl;
    }

public:
    static void ShowGeneratePatrolReportScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\tGenerate Patrol Report Screen");
        if (clsInputValidate::IsSureToPerform())
        {

            vector<clsPatrolSchedule> vSchedules = clsPatrolSchedule::GetSchedulesList();

            _PrintReportSummary(vSchedules);


        }




        
    }
};
