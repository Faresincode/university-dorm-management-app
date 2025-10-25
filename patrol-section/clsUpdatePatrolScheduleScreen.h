#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsPatrolSchedule.h";
#include "clsGlobalPrint.h";
#include "clsGlobalRead.h";

class clsUpdatePatrolScheduleScreen : protected clsBase
{

private:


    enum enWhatToUpdate { eStatus = 1, ePatrolLocation = 2, eStartTime = 4,eEndTime=5, eAll = 6, eExit = 7 };

    static void _PerformUpdateMenuScreen(enWhatToUpdate WhatToUpdate, clsPatrolSchedule& Patrol)
    {
        switch (WhatToUpdate)
        {
        case enWhatToUpdate::eStatus:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Patrol Status: [ 1 = Scheduled, 2 = InProgress, 3 = Completed, 4 = Cancelled ]: ";
            Patrol.PatrolStatus = (clsPatrolSchedule::enPatrolStatus)clsInputValidate::ReadNumberBetween<short>(1, 4);
            break;
        }
        case enWhatToUpdate::ePatrolLocation:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Patrol Location: ";
            Patrol.PatrolLocation = clsInputValidate::ReadString();
            break;
        }
        case enWhatToUpdate::eStartTime:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left;
            Patrol.StartTime = clsGlobalRead::ReadDate("Read Patrol Start Time: ");
            break;
        }

        case enWhatToUpdate::eEndTime:
        {
            cout << "\n" << setw(ScreenWidth) << "" << left;
            Patrol.EndTime = clsGlobalRead::ReadDate("Read Patrol End Time : ");
            break;
        }

        case enWhatToUpdate::eAll:
        {
            clsGlobalRead::ReadPatrolScheduleInfo(Patrol);
            break;
        }
        case enWhatToUpdate::eExit:
            return;

        default:
            clsGlobalRead::ReadPatrolScheduleInfo(Patrol);

            break;
        }

        Patrol.LastUpdateDateTime = clsDate::GetSystemDateTimeString();
    }

    static void _ShowUpdateMenuScreen(clsPatrolSchedule& Patrol)
    {
        cout << setw(ScreenWidth) << "" << left << Green << "==============================================\n";
        cout << setw(ScreenWidth) << "" << left << Red << "    Update Patrol Schedule Menu Screen\n";
        cout << setw(ScreenWidth) << "" << left << Green << "==============================================\n" << White;

        cout << setw(ScreenWidth) << "" << left << " [1] Patrol Status\n";
        cout << setw(ScreenWidth) << "" << left << " [2] Patrol Location\n";
        cout << setw(ScreenWidth) << "" << left << " [3] Patrol Start Time \n";
        cout << setw(ScreenWidth) << "" << left << " [4] Patrol End Time\n";
        cout << setw(ScreenWidth) << "" << left << " [5] Update All\n";
        cout << setw(ScreenWidth) << "" << left << " [6] Exit\n";

        cout << setw(ScreenWidth) << "" << left << Green << "==============================================\n\n";

        cout << setw(ScreenWidth) << "" << left << Yellow << "What do you want to update (from 1 to  6)? " << White;
        _PerformUpdateMenuScreen((enWhatToUpdate)clsInputValidate::ReadNumberBetween<short>(1, 6), Patrol);
    }

public:

    static void ShowUpdatePatrolScheduleScreen()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\tUpdate Patrol Schedule Screen");

        if (clsInputValidate::IsSureToPerform())
        {

            string PatrolID = clsGlobalRead::ReadPatrolID();


            clsPatrolSchedule Patrol = clsPatrolSchedule::FindSchedule(PatrolID);

            clsGlobalPrint::PrintPatrolSchedule(Patrol);

            _ShowUpdateMenuScreen(Patrol);

            clsPatrolSchedule::enSaveResults SaveResult = Patrol.SaveSchedule();

            clsGlobalPrint::PrintResult(SaveResult, Patrol);
        }

    }

};



