#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsRoom.h";
using namespace std;


class clsUpdateRoomInfoScreen : protected clsBase
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
		cout << "\n" << setw(ScreenWidth) << "" << left << " Available Beds    : " << Room.AvailableBeds;
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

		return clsRoom::FindRoom(Room.ResidenceName, Room.DormBuilding, Room.RoomNumber);
	}


	static void ReadUpdatedRoomInfo(clsRoom &Room)
	{

		cout << setw(ScreenWidth) << "" << left << Blue << "Read Info To Update " << White<<"\n";
		cout << "\n" << setw(ScreenWidth) << "" << left << Blue << "Enter New Room Capacity " << White;
		Room.RoomCapacity = clsInputValidate::ReadNumber<short>();
		cout <<"\n" << setw(ScreenWidth) << "" << left << Blue << "Enter New Occupied Beds " << White ;
		Room.OccupiedBeds = clsInputValidate::ReadNumber<short>();

	}


public:

	static void ShowUpdateRoomScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\t\tUpdate Room Screen");

		if (clsInputValidate::IsSureToPerform())
		{

			clsRoom Room = _ReadAndFindRoom();

			ReadUpdatedRoomInfo(Room);
			clsRoom::enSaveResults SaveResult;
			SaveResult = Room.Save();

			if (SaveResult == clsRoom::enSaveResults::svSucceeded)
			{
				cout << "\n" << setw(ScreenWidth) << "" << left <<Green<< "Room updated Successfully : "<<White;
				_PrintDormRoomInfo(Room);
			}
			else
			{
				cout << "\n" << setw(ScreenWidth) << "" << left  <<Red<< "! Error !  Room not Update because its Empty Object : " << White;


			}
		}


	}





};

