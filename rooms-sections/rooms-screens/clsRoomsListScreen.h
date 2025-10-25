#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsRoom.h";
using namespace std;

class clsRoomsListScreen : protected clsBase
{


private:


    friend class clsGenerateRoomReportsScreen;

    static void _PrintRoomRecordLine(clsRoom Room)
    {
        cout << setw(21) << left << "" << Green << "| " << White << setw(25) << left << Room.ResidenceName;
        cout << Green << "| " << White << setw(16) << left << Room.DormBuilding;
        cout << Green << "| " << White << setw(16) << left << Room.RoomNumber;
        cout << Green << "| " << White << setw(16) << left << Room.RoomCapacity;
        cout << Green << "| " << White << setw(16) << left << Room.OccupiedBeds;
        cout << Green << "| " << White << setw(16) << left << Room.AvailableBeds;




    }

    static void _PrintRoomHeader()
    {

        cout << "\n" << setw(20) << left << "" << Green << "_______________________________________________________________________________________________________________________\n\n" << White;

        cout << setw(21) << left << "" << Green << "| " << Yellow << left << setw(25) << "Residence Name";
        cout << Green << "| " << Yellow<< left << setw(16) << "Dorm Building";
        cout << Green << "| " << Yellow<< left << setw(16) << "Room Number";
        cout << Green << "| " << Yellow<< left << setw(16) << "Room Capacity";
        cout << Green << "| " << Yellow<< left << setw(16) << "Occupied Beds";
        cout << Green << "| " << Yellow<< left << setw(16) << "Available Beds";
        cout << "\n" << setw(20) << left << "" << Green << "_______________________________________________________________________________________________________________________\n\n" << White;

    }




public:



    static void ShowDormRoomsList()
    {
        system("cls");
        clsBase::_DrawScreenHeader("\t   Dorm Students List Screen");


        if (clsInputValidate::IsSureToPerform())
        {
            system("cls");
            vector<clsRoom>vRoomsObjects = clsRoom::GetRoomsDataList();
            string SubTitle = "\t      (" + to_string(vRoomsObjects.size()) + ") Dorm Students";
            clsBase::_DrawScreenHeader("\t   Dorm Students List Screen", SubTitle);

            _PrintRoomHeader();
            for (clsRoom& student : vRoomsObjects)
            {
                _PrintRoomRecordLine(student);
                cout << endl;
            }


            cout << setw(20) << left << "" << Green << "_______________________________________________________________________________________________________________________" << White << endl;

        }


    }



};

