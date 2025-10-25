#pragma once
#include <iostream>
#include <vector>
#include "clsBase.h";
#include "clsPatrolSchedule.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsGlobalPrint.h"
#include "clsViewAllPatrolSchedulesScreen.h";

class clsViewPatrolLogsScreen : protected clsBase
{



private:




public:

    static void ShowViewPatrolLogsScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t  Patrol Logs List");


        if (clsInputValidate::IsSureToPerform())
        {
            system("cls");

            vector<clsPatrolSchedule> vPatrolLogs = clsPatrolSchedule::GetSchedulesList();
            string SubTitle = "\t\t(" + to_string(vPatrolLogs.size()) + ") Patrol Logs";

            clsBase::_DrawScreenHeader("\t  Patrol Logs List", SubTitle);

            clsViewAllPatrolSchedulesScreen::_PrintPatrolTable(vPatrolLogs);

            vector<clsPatrolSchedule> vCompletedPatrolLogs = clsPatrolSchedule::GetScheduleListByStatus(clsPatrolSchedule::enPatrolStatus::eCompleted);

            cout << "\n\n" << setw(ScreenWidth) << left << "" << Green << "Completed Patroles Schedules\n\n" << White;
            clsViewAllPatrolSchedulesScreen::_PrintPatrolTable(vCompletedPatrolLogs);

        }





 
    }





};

