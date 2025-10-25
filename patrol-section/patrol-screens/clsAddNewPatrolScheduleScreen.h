#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsPatrolSchedule.h"
#include "clsGlobalPrint.h"
#include "clsGlobalRead.h"
#include "clsDate.h"
#include "clsUtil.h";

using namespace std;

class clsAddNewPatrolScheduleScreen : protected clsBase
{

private:

	static string GenerateNewPatrolId()
	{
		string PatrolID = clsUtil::GenerateID("PAT");
		while (clsPatrolSchedule::IsScheduleExist(PatrolID))
		{
			PatrolID = clsUtil::GenerateID("PAT");
		}

		return PatrolID;
	}


public:

	
	static void ShowAddNewPatrolScheduleScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\t Add New Patrol Schedule Screen");

		if (clsInputValidate::IsSureToPerform())
		{


			clsPatrolSchedule NewPatrol = clsPatrolSchedule::GetAddNewPatrolScheduleObject("");

			NewPatrol.PatrolID = GenerateNewPatrolId();
			NewPatrol.SecurityID = clsGlobalRead::ReadSecurityID();

			clsGlobalRead::ReadPatrolScheduleInfo(NewPatrol);

			clsPatrolSchedule::enSaveResults SaveResult = NewPatrol.SaveSchedule();

			clsGlobalPrint::PrintResult(SaveResult, NewPatrol);

		}

	}
	

};
