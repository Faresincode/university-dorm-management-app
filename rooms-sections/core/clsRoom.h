#pragma once
#include <iostream>
#include <Vector>
#include <iomanip>
#include <string>
#include "clsInputValidate.h";
#include "clsDate.h";
#include "clsUtil.h"; 
#include "Global.h";

using namespace std;


class clsRoom
{


private:
    enum enRoomMode{eEmptyMode=0,eUpdateMode=1,eAddNewMode=2};
    enRoomMode _Mode;
    bool _MarkForDelete = false;
    string _ResidenceName;
    short _RoomNumber;
    char _DormBuilding;
    short _RoomCapacity;
    short _OccupiedBeds;
    short _AvailableBeds= _RoomCapacity- _OccupiedBeds;



    static string _ConvertRoomObjectToLine(clsRoom Room)
    {
        string RoomRecord = "";
        RoomRecord += Room.ResidenceName + FileSeparator;
        RoomRecord += to_string((int)Room.DormBuilding) + FileSeparator;
        RoomRecord += to_string(Room.RoomNumber) + FileSeparator;
        RoomRecord += to_string(Room.RoomCapacity) + FileSeparator;
        RoomRecord += to_string(Room.OccupiedBeds) + FileSeparator;
        RoomRecord += to_string(Room.GetAvailableBeds());

        return RoomRecord;
    }

    static clsRoom _ConvertLineToRoomObject(string Line)
    {
        
        vector<string> vRoomData = clsString::Split(Line, FileSeparator);

        return clsRoom(enRoomMode::eUpdateMode,vRoomData[0], stoi(vRoomData[1]),stoi(vRoomData[2]),stoi(vRoomData[3]),stoi(vRoomData[4]),stoi(vRoomData[5]));
    }

    static vector<clsRoom> _LoadRoomsDataFromFile()
    {
        vector<clsRoom> vRooms;
        fstream MyFile;

        MyFile.open(RoomsDataFileName, ios::in);
        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsRoom Room = clsRoom::_ConvertLineToRoomObject(Line);
                vRooms.push_back(Room);
            }
            MyFile.close();
        }
        return vRooms;
    }

    static void _SaveRoomsDataToFile(vector<clsRoom> vRooms)
    {
        fstream MyFile;
        MyFile.open(RoomsDataFileName, ios::out);
        if (MyFile.is_open())
        {
            for (clsRoom& Room : vRooms)
            {
                if (Room._MarkForDelete == false)
                {
                     MyFile << _ConvertRoomObjectToLine(Room) << endl;

                }
            }

            MyFile.close();
        }
    }


    static clsRoom _GetEmptyRoomsObject()
    {
        return clsRoom(enRoomMode::eEmptyMode, "", ' ', 0, 0, 0, 0);
    }




public:

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildRoomExist = 2 };

    // Constructor
    clsRoom(enRoomMode Mode,string ResidenceName, char DormBuilding ,short RoomNumber, short RoomCapacity,short OccupiedBeds, short AvailableBeds)
    {
        _Mode = Mode;
        _ResidenceName = ResidenceName;
        _DormBuilding = DormBuilding;
        _RoomNumber = RoomNumber;
        _RoomCapacity = RoomCapacity;
        _OccupiedBeds = OccupiedBeds;
        _AvailableBeds = AvailableBeds;
    }
    // Setters
    void SetResidenceName(string ResidenceName) 
    {
        _ResidenceName = ResidenceName; 
    }
    void SetRoomNumber(short RoomNumber) 
    {
        _RoomNumber = RoomNumber;
    }
    void SetDormBuilding(char DormBuilding)
    { 
        _DormBuilding = DormBuilding;
    }
    void SetRoomCapacity(short RoomCapacity) 
    { 
        _RoomCapacity = RoomCapacity; 
    }
    void SetOccupiedBeds(short OccupiedBeds)
    {
        _OccupiedBeds = OccupiedBeds;
    }
    void SetAvailableBeds(short AvailableBeds)
    {
        _AvailableBeds = AvailableBeds;
    }


    // Getters
    string GetResidenceName() const 
    { 
        return _ResidenceName; 
    }
    short GetRoomNumber() const 
    {
        return _RoomNumber;
    }
    char GetDormBuilding() const 
    { 
        return _DormBuilding;
    }
    short GetRoomCapacity() const 
    { 
        return _RoomCapacity; 
    }
    short GetOccupiedBeds() const
    {
        return _OccupiedBeds;
    }

    short GetAvailableBeds() const
    {
        return _RoomCapacity - _OccupiedBeds;
    }


    __declspec(property(get = GetResidenceName, put = SetResidenceName)) string ResidenceName;
    __declspec(property(get = GetRoomNumber, put = SetRoomNumber)) short RoomNumber;
    __declspec(property(get = GetDormBuilding, put = SetDormBuilding)) char DormBuilding;
    __declspec(property(get = GetRoomCapacity, put = SetRoomCapacity)) short RoomCapacity;
    __declspec(property(get = GetOccupiedBeds, put = SetOccupiedBeds)) short OccupiedBeds;
    __declspec(property(get = GetAvailableBeds , put=SetAvailableBeds)) short AvailableBeds;




    static vector<clsRoom> GetRoomsDataList()
    {
        return clsRoom::_LoadRoomsDataFromFile();
    }



    static clsRoom GetAddNewRoomsObject()
    {
        return clsRoom(enRoomMode::eAddNewMode, "", ' ', 0, 0, 0, 0);
    }

    static clsRoom GetUpdateRoomsObject()
    {
        return clsRoom(enRoomMode::eUpdateMode, "", ' ', 0, 0, 0, 0);
    }

    static clsRoom FindRoom(string ResidenceNameToFind, char DormBuildingToFind, short RoomNumberToFind)
    {

        vector<clsRoom>vRoomsData = clsRoom::GetRoomsDataList();
        for (clsRoom& Room : vRoomsData)
        {

            if (Room.ResidenceName == ResidenceNameToFind && Room.DormBuilding == DormBuildingToFind && Room.RoomNumber == RoomNumberToFind)
                return Room;

        }
        return clsRoom::_GetEmptyRoomsObject();
    }

    bool IsEmpty()
    {
        return _Mode == enRoomMode::eEmptyMode;
    }

    static bool IsRoomExist(string ResidenceName, char DormBuilding, short RoomNumber)
    {
        clsRoom Room = clsRoom::FindRoom(ResidenceName, DormBuilding, RoomNumber);
        return !(Room.IsEmpty());
    }

    static void _AddRoomLineToFile(string Line)
    {
        fstream MyFile;
        MyFile.open(RoomsDataFileName, ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << Line << endl;
            MyFile.close();
        }
    }


    void _AddNewRoom()
    {
        _AddRoomLineToFile(_ConvertRoomObjectToLine(*this));
     
    }



    bool DeleteRoom()
    {

        vector <clsRoom>vRoomsObjects = clsRoom::_LoadRoomsDataFromFile();

        for (clsRoom& Room : vRoomsObjects)
        {
            if (Room.ResidenceName == ResidenceName && Room.DormBuilding == DormBuilding && Room.RoomNumber == RoomNumber)
            {
                Room._MarkForDelete = true;
                clsRoom::_SaveRoomsDataToFile(vRoomsObjects);
                return true;
            
            }

        }

        return false;
    }

    bool _UpdateRoom()
    {

        vector<clsRoom>vRoomsObjects = clsRoom::_LoadRoomsDataFromFile();
        for(clsRoom &Room: vRoomsObjects)
        {
            if (Room.ResidenceName == ResidenceName && Room.DormBuilding == DormBuilding && Room.RoomNumber == RoomNumber)
            {
                Room = *this;
                clsRoom::_SaveRoomsDataToFile(vRoomsObjects);
                return true;
            }
        
        }
        return false;
    }


    enSaveResults Save()
    {
        switch (_Mode)
        {

        case enRoomMode::eEmptyMode:
            return enSaveResults::svFaildEmptyObject;

        case enRoomMode::eUpdateMode:
            _UpdateRoom();
            return enSaveResults::svSucceeded;

        case enRoomMode::eAddNewMode:

            if (clsRoom::IsRoomExist(ResidenceName,DormBuilding,RoomNumber))
            {
                return enSaveResults::svFaildRoomExist;
            }
            else
            {
                _AddNewRoom();
                _Mode = enRoomMode::eUpdateMode;
                return enSaveResults::svSucceeded;
            }
        }
    }

    bool IsAvailableRoom()
    {
        return AvailableBeds != 0;
    }

    static int TotalOccupancyCount()
    {
        vector<clsRoom> vRoomsObjects = clsRoom::_LoadRoomsDataFromFile();
        int TotalOccupancyBeds = 0;

        for (clsRoom& Room : vRoomsObjects)
        {
            TotalOccupancyBeds += Room.OccupiedBeds;

        }
        return TotalOccupancyBeds;

    }

    static int TotalCapacityCount()
    {
        vector<clsRoom> vRoomsObjects = clsRoom::_LoadRoomsDataFromFile();
        int TotalCapacityBeds = 0;

        for (clsRoom& Room : vRoomsObjects)
        {
            TotalCapacityBeds += Room.RoomCapacity;

        }
        return TotalCapacityBeds;

    }

    static float OccupancyRate()
    {

        return ((float)TotalOccupancyCount() / (float)TotalCapacityCount()) * 100;

    }

    static int RoomsCountByBuilding(char DormBuildingToFind,string ResidenceName)
    {
        vector<clsRoom>vRoomsObjects = clsRoom::_LoadRoomsDataFromFile();
        int Counter = 0;
        for (clsRoom& Room : vRoomsObjects)
        {
            if (Room.DormBuilding == DormBuildingToFind)
            {
                Counter++;
            }
        }
        return Counter;
    }


};

