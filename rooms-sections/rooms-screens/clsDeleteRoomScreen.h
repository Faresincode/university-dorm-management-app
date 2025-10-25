#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsRoom.h";
using namespace std; 


class clsDeleteRoomScreen : protected clsBase
{

private:


	static void _PrintDormRoomInfo(clsRoom Room)
	{
		cout << "\n";
		cout << "\n"<<setw(ScreenWidth) << "" << left << Green << "==========================================";
		cout << "\n"<<setw(ScreenWidth) << "" << left << Blue << "                Room Info : ";
		cout << "\n"<<setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
		cout << "\n"<<setw(ScreenWidth) << "" << left << " Residence Name    : " << Room.ResidenceName ;
		cout << "\n"<<setw(ScreenWidth) << "" << left << " Dorm Building     : " << Room.DormBuilding ;
		cout << "\n"<<setw(ScreenWidth) << "" << left << " Room Number       : " << Room.RoomNumber ;
		cout << "\n"<<setw(ScreenWidth) << "" << left << " Room Capacity     : " << Room.RoomCapacity ;
		cout << "\n"<<setw(ScreenWidth) << "" << left << " Occupied Beds     : " << Room.OccupiedBeds ;
		cout << "\n"<<setw(ScreenWidth) << "" << left << " Available Beds    : " << Room.AvailableBeds;
		cout << "\n"<<setw(ScreenWidth) << "" << left << Green << "==========================================" << White;
		cout << endl;

	}

	static void _ReadRoomInfo(clsRoom& Room)
	{

		cout <<"\n" << setw(ScreenWidth) << "" << left << "Enter Residence Name : ";
		Room.ResidenceName = clsInputValidate::ReadString();
		cout <<"\n" << setw(ScreenWidth) << "" << left << "Enter Dorm Building  : ";
		Room.DormBuilding = clsInputValidate::ReadCharacter();
		cout <<"\n" << setw(ScreenWidth) << "" << left << "Enter Room Number    : ";
		Room.RoomNumber = clsInputValidate::ReadNumber<short>();

	}

	static clsRoom _ReadRoomInfoToDelete()
	{
		clsRoom Room = clsRoom::GetUpdateRoomsObject();
		cout << setw(ScreenWidth) << "" << left <<Blue<< "Read Info To Delete "<<White<<"\n";

		_ReadRoomInfo(Room);

		while (!clsRoom::IsRoomExist(Room.ResidenceName, Room.DormBuilding, Room.RoomNumber))
		{

			cout << setw(ScreenWidth) << "" << left << "!Error Room Not Find Try Again \n";
			_ReadRoomInfo(Room);
		}

		return Room;
	}



	static void _PrintSmallRoomRecordLine(clsRoom Room)
	{

		cout << setw(41) << left << "" << Green << "| " << White << setw(25) << left << Room.ResidenceName;
		cout << Green << "| " << White << setw(16) << left << Room.DormBuilding;
		cout << Green << "| " << White << setw(16) << left << Room.RoomNumber;

	}

	static void _PrintRoomHeader()
	{

		cout << "\n" << setw(40) << left << "" << Green << "__________________________________________________________________\n\n" << White;

		cout << setw(41) << left << "" << Green << "| " << Yellow << left << setw(25) << "Residence Name";
		cout << Green << "| " << Yellow << left << setw(16) << "Dorm Building";
		cout << Green << "| " << Yellow << left << setw(16) << "Room Number";
		cout << "\n" << setw(40) << left << "" << Green << "__________________________________________________________________\n\n" << White;

	}

	static void _ShowSmallRoomsInfoTable()
	{

		vector<clsRoom>vRoomsObjects = clsRoom::GetRoomsDataList();
		_PrintRoomHeader();
		for (clsRoom& student : vRoomsObjects)
		{
			_PrintSmallRoomRecordLine(student);
			cout << endl;
		}
		cout << setw(41) << left << "" << Green << "__________________________________________________________________" << White << endl;


	}



public:

	static void DeleteDormRoomScreen()
	{
		system("cls");
		clsBase::_DrawScreenHeader("\t\tDelete Dorm Room Screen\n");
		
		if (clsInputValidate::IsSureToPerform())
		{

			_ShowSmallRoomsInfoTable();

			clsRoom Room = _ReadRoomInfoToDelete();
			clsRoom DormStudentToDelete = clsRoom::FindRoom(Room.ResidenceName,Room.DormBuilding, Room.RoomNumber);
			_PrintDormRoomInfo(DormStudentToDelete);

			cout << "\n" << setw(ScreenWidth) << "" << left << "Are you sure you want to delete the Dorm Room  Definitely (answer with [Y/N]) : ";
			if (clsInputValidate::IsAnswerIsYes())
			{
				if (DormStudentToDelete.DeleteRoom())
				{
					cout << "\n" << setw(ScreenWidth) << "" << left << Green << "Room Deleted Successfully :-)\n";
				}
				else
				{
					cout << Red << "\n" << setw(ScreenWidth) << "" << left << "\nError Room Was not Deleted\n";
				}
				cout << White << endl;
			}

		}

	}




};

