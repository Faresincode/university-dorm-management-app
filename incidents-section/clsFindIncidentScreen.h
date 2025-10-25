#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsIncidentReport.h"
#include "clsGlobalPrint.h"
#include "clsGlobalRead.h"

using namespace std;

class clsFindIncidentScreen : protected clsBase
{

public:

	static void ShowFindIncidentScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\t   Find Incident Report Screen");

		if (clsInputValidate::IsSureToPerform())
		{
			string IncidentID = clsGlobalRead::ReadIncidentID();

			clsIncidentReport Incident = clsIncidentReport::FindIncident(IncidentID);

			if (!Incident.IsEmpty())
			{
				cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Object Found :-)\n" << White;

				clsGlobalPrint::PrintIncidentInfo(Incident);

			}
			else
			{
				cout << setw(ScreenWidth) << "" << left << Red << "!Error! Object Is Empty" << White << endl;
			}


		}




	}
};



