#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsRoom.h";

using namespace std;

class clsAddNewRoomsScreen : protected clsBase
{

private:


	static void _PrintDormRoomInfo(clsRoom Room)
	{
		cout << "\n";
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================";
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "                Room Info : ";
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Residence Name    : " << Room.ResidenceName;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Dorm Building     : " << Room.DormBuilding;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Room Number       : " << Room.RoomNumber;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Room Capacity     : " << Room.RoomCapacity;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Occupied Beds     : " << Room.OccupiedBeds;
		cout << "\n" << setw(ScreenWidth) << "" << left << " Available Beds    : " << Room.GetAvailableBeds();
		cout << "\n" << setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
		cout << endl;

	}

	static void _ReadRoomInfo(clsRoom& Room)
	{

		cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Residence Name : ";
		Room.ResidenceName = clsInputValidate::ReadString();
		cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Dorm Building  : ";
		Room.DormBuilding = clsInputValidate::ReadCharacter();
		cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Room Number    : ";
		Room.RoomNumber = clsInputValidate::ReadNumber<short>();
		cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Room Capacity    : ";
		Room.RoomCapacity = clsInputValidate::ReadNumber<short>();
		cout << "\n" << setw(ScreenWidth) << "" << left << "Enter Occupied Room Number    : ";
		Room.OccupiedBeds = clsInputValidate::ReadNumberBetween<short>(0, Room.RoomCapacity);


	}

	static clsRoom _ReadNewRoom()
	{
		clsRoom Room = clsRoom::GetAddNewRoomsObject();
		cout << setw(ScreenWidth) << "" << left << Blue << "Read New Room " << White << "\n";

		_ReadRoomInfo(Room);

		while (clsRoom::IsRoomExist(Room.ResidenceName, Room.DormBuilding, Room.RoomNumber))
		{

			cout << setw(ScreenWidth) << "" << left << "!Error Room is already	Exist Try Again \n";
			_ReadRoomInfo(Room);
		}

		return Room;
	}



public :

	static void ShowAddNewRoomScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\t    Add New Room Screen");
		if (clsInputValidate::IsSureToPerform())
		{

			clsRoom Room = _ReadNewRoom();

			clsRoom::enSaveResults SaveResult;
			SaveResult = Room.Save();
			if (SaveResult == clsRoom::enSaveResults::svSucceeded)
			{

				cout << "\n" << setw(ScreenWidth) << "" << left <<Green<< "Room Added Successfully : ";
				_PrintDormRoomInfo(Room);

			}
			else
			{
				cout << "\n" << setw(ScreenWidth) << "" << left << Red<< "! Error ! Room Not Added the room is	already exist  : ";

			}
		}

			
	}




};

