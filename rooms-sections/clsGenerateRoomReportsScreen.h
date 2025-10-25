#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsRoom.h";
#include "clsRoomsListScreen.h";
using namespace std;



class clsGenerateRoomReportsScreen : protected clsBase
{

private:

	static void ShowRoomList(vector<clsRoom>vRoomsObjects)
	{


		cout <<"\n\n" << setw(ScreenWidth) << left << "" << Green << Red << "\t    Rooms List Screen\n\n";
		clsRoomsListScreen::_PrintRoomHeader();
        for (clsRoom& student : vRoomsObjects)
        {
			clsRoomsListScreen::_PrintRoomRecordLine(student);
            cout << endl;
        }


        cout << setw(20) << left << "" << Green << "_______________________________________________________________________________________________________________________" << White << endl;

	}

	static void _DrawBuildingTableHeader()
	{
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "------------------------------------------------------------" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "| " << Yellow << setw(25) << "Residence Name" << left;
		cout << Green << "| " << Yellow << setw(16) << "Building" << left;
		cout << Green << "| " << Yellow << setw(16) << "Total Rooms" << left;
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "------------------------------------------------------------" << White;



	}

	static void _PrintBuildingTableline(clsRoom Room)
	{
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "| " << White << setw(25) << Room.ResidenceName << left;
		cout << Green << "| " << White << setw(16) << Room.DormBuilding << left;
		cout << Green << "| " << White << setw(16) <<clsRoom::RoomsCountByBuilding(Room.DormBuilding, Room.ResidenceName);

	}

	static void _PrintBuildingTable(vector<clsRoom>vRoomsObjects)
	{

		
		cout << "\n" << setw(ScreenWidth + 1) << "" << left << Blue << "Rooms Count Per Dorm Building Table : \n" << White;
		_DrawBuildingTableHeader();

		for (clsRoom& Room : vRoomsObjects)
		{
			_PrintBuildingTableline(Room);
		}

		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "------------------------------------------------------------" << White << endl;
	}


	static void _AvailableRoomListTable(vector<clsRoom>vRoomsObjects,bool available=true)
	{
		int TotalAvailableBedsCount=0;
		clsRoomsListScreen::_PrintRoomHeader();
		for (clsRoom& Room : vRoomsObjects)
		{

			if (Room.IsAvailableRoom()== available)
			{
				TotalAvailableBedsCount += Room.AvailableBeds;
				clsRoomsListScreen::_PrintRoomRecordLine(Room);
				cout << endl;

			}

		}
		cout << "\n" << setw(20) << left << "" << Green << "_______________________________________________________________________________________________________________________\n\n" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << "\t\tTotal available beds = " << TotalAvailableBedsCount << endl;

	}
	

	static void _PrintOcupancyReport()
	{
		float OcupancyRate = clsRoom::OccupancyRate();
		cout << "\n\n" << setw(ScreenWidth) << left << "" << Red << "\t\tOccupancy Rate Report\n\n" << White;
		cout << setw(ScreenWidth + 2) << left << "" << White << "Ocupancy Rate        : " << OcupancyRate << " % " << "\n";
		cout << setw(ScreenWidth + 2) << left << "" << White << "Availability Rate     : " << 100 - OcupancyRate << " % " << "\n";

	}

public:


	static void GenerateRoomsReportScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\t   Generate Rooms Report Screen");
		if (clsInputValidate::IsSureToPerform())
		{

			vector<clsRoom>vRoomsObjects = clsRoom::GetRoomsDataList();
			ShowRoomList(vRoomsObjects);

			_PrintOcupancyReport();
			_PrintBuildingTable(vRoomsObjects);
			cout <<"\n\n" << setw(ScreenWidth) << left << "" << Red << "\t\tAvailability Rooms Table" << White << "\n\n";
			_AvailableRoomListTable(vRoomsObjects);
			cout <<"\n\n" << setw(ScreenWidth) << left << "" << Red << "\t\tOccupancy Rooms Table" << White << "\n\n";
			_AvailableRoomListTable(vRoomsObjects,false);

		}



	}




};

