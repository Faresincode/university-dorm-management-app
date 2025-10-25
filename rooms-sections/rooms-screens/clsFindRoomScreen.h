#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsRoom.h":
#include "clsGlobalPrint.h";

using namespace std;


class clsFindRoomScreen : protected clsBase
{



private:



	static void _ReadRoomInfo(clsRoom& Room)
	{

		cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Residence Name : ";
		Room.ResidenceName = clsInputValidate::ReadString();
		cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Dorm Building  : ";
		Room.DormBuilding = clsInputValidate::ReadCharacter();
		cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Room Number    : ";
		Room.RoomNumber = clsInputValidate::ReadNumber<short>();

	}

	static clsRoom _ReadAndFindRoom()
	{
		clsRoom Room = clsRoom::GetUpdateRoomsObject();
		cout << setw(ScreenWidth) << "" << left << Blue << "Read Info To Find " << White << "\n";

		_ReadRoomInfo(Room);

		while (!clsRoom::IsRoomExist(Room.ResidenceName, Room.DormBuilding, Room.RoomNumber))
		{

			cout << setw(ScreenWidth) << "" << left << "!Error Room Not Find Try Again \n";
			_ReadRoomInfo(Room);
		}

		return clsRoom::FindRoom(Room.ResidenceName,Room.DormBuilding,Room.RoomNumber);
	}



public:

	static void ShowFindRoomScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\t   Find Room Screen");
		if (clsInputValidate::IsSureToPerform())
		{
			clsGlobalPrint::PrintDormRoomInfo(_ReadAndFindRoom());


		}


	}










};

