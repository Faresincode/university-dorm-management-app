#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsBase.h"
#include "clsInputValidate.h"
#include "clsVisitor.h";
#include "clsVisitorLogListScreen.h";


using namespace std; 



class clsMarkVisitorExitScreen : protected clsBase
{



private:



public :

	static void MarkVisitorExitScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\tMark Visitor Exit Screen");

		if (clsInputValidate::IsSureToPerform())
		{
			system("cls");
			vector<clsVisitor> vVisitors = clsVisitor::GetVisitorList();
			clsVisitorLogListScreen::PrintVisitorTable(vVisitors);
			string VisitorID = clsGlobalRead::ReadVisitorId();
			clsVisitor Visitor = clsVisitor::FindVisitor(VisitorID);
			if (!Visitor.IsEmpty())
			{
				clsGlobalPrint::PrintFullVisitorInfo(Visitor);

				cout << setw(ScreenWidth) << "" << left << "Are you sure you want to mark this visitor as exited? [Y/N] : ";
				if (clsInputValidate::IsAnswerIsYes())
				{

					Visitor.VisitorStatus = clsVisitor::enVisitorStatus::eExited;
					Visitor.ExitDateTime = clsDate::GetSystemDateTimeString();
					clsVisitor::enSaveResults SaveResult = Visitor.SaveVisitor();
					clsGlobalPrint::PrintResult(SaveResult, Visitor);
				}
			}
			else
			{
				cout << setw(ScreenWidth) << "" << left << Red << "!Error! Object Is Empty " << White << endl;

			}

		}




	}



};

