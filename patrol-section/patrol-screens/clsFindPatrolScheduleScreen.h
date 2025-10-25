#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsPatrolSchedule.h"
#include "clsGlobalPrint.h"
#include "clsGlobalRead.h"

using namespace std;

class clsFindPatrolScheduleScreen : protected clsBase
{

public:

	
	static void ShowFindPatrolScheduleScreen()
	{
			
		system("cls");
		clsBase::_DrawScreenHeader("\t   Find Patrol Schedule Screen");


		if (clsInputValidate::IsSureToPerform())
		{


			string PatrolID = clsGlobalRead::ReadPatrolID();


			clsPatrolSchedule Patrol = clsPatrolSchedule::FindSchedule(PatrolID);

			if (!Patrol.IsEmpty())
			{
				cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Object Found :-)\n" << White;

				clsGlobalPrint::PrintPatrolSchedule(Patrol);

			}
			else
			{
				cout << setw(ScreenWidth) << "" << left << Red << "!Error! Object Is Empty" << White << endl;
			}

		}


	}
	

};

