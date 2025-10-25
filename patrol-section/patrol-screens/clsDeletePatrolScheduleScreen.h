#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsPatrolSchedule.h"
#include "clsGlobalRead.h"
#include "clsGlobalPrint.h"
#include "clsSchedule.h";

using namespace std;

class clsDeletePatrolScheduleScreen : protected clsBase
{

private:



    static void _PrintSpecificPatrolScheduleRecordLine(clsPatrolSchedule Patrol)
    {
        cout << setw(ScreenWidth - 20) << left << "" << Green << "| " << White << setw(15) << left << Patrol.PatrolID;
        cout << Green << "| " << White << setw(15) << left << Patrol.SecurityID;
        cout << Green << "| " << White << setw(20) << left << clsPatrolSchedule::GetPatrolStatusString(Patrol.PatrolStatus) << White;
        cout << Green << "| " << White << setw(40) << left << Patrol.PatrolLocation;

    }

    static void _PrintSpecificPatrolScheduleHeader()
    {
        cout << "\n" << setw(ScreenWidth - 21) << left << ""<< Green << "-----------------------------------------------------------------------------------------------------\n" << White;
        cout << setw(ScreenWidth - 20) << left << "" << Green << "| "<< Yellow << setw(15) << left << "Patrol ID";
        cout << Green << "| " << Yellow << setw(15) << left << "Guard ID";
        cout << Green << "| " << Yellow << setw(20) << left << "Status" << White;
        cout << Green << "| " << Yellow << setw(40) << left << "Building";

        cout <<"\n" << setw(ScreenWidth - 21) << left << "" << Green<< "-----------------------------------------------------------------------------------------------------\n" << White;
    }

    static void _PrintSmallPatrolScheduleListInfo()
    {
        vector<clsPatrolSchedule> vPatrols = clsPatrolSchedule::GetSchedulesList();

        if (vPatrols.empty())
        {
            cout << setw(ScreenWidth) << "" << left
                << Red << "No Patrol Schedules Available In the System!\n" << White;
        }
        else
        {
            _PrintSpecificPatrolScheduleHeader();
            for (clsPatrolSchedule& Patrol : vPatrols)
            {
                _PrintSpecificPatrolScheduleRecordLine(Patrol);
                cout << endl;
            }
            cout << setw(ScreenWidth - 21) << left << "" << Green << "-----------------------------------------------------------------------------------------------------\n" << White;

        }
    }

public:

    static void ShowDeletePatrolScheduleScreen()
    {
        system("cls");
         clsBase::_DrawScreenHeader("\tDelete Patrol Schedule Screen\n");

   
        if (clsInputValidate::IsSureToPerform())
        {


            _PrintSmallPatrolScheduleListInfo();

            string PatrolID = clsGlobalRead::ReadPatrolID();


            clsPatrolSchedule PatrolToDelete = clsPatrolSchedule::FindSchedule(PatrolID);
            clsGlobalPrint::PrintPatrolSchedule(PatrolToDelete);

            cout << "\n" << setw(ScreenWidth) << "" << left
                << "Are you sure you want to delete this Patrol Schedule definitely? [Y/N]: ";

            if (clsInputValidate::IsAnswerIsYes())
            {
                if (PatrolToDelete.DeleteSchedule())
                {
                    cout << "\n" << setw(ScreenWidth) << "" << left
                        << Green << "Patrol Schedule Deleted Successfully :-)\n" << White;
                }
                else
                {
                    cout << "\n" << setw(ScreenWidth) << "" << left
                        << Red << "Error: Patrol Schedule Was Not Deleted!\n" << White;
                }
            }


        }

    }





};
