#pragma once
#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsBase.h";
#include "clsInputValidate.h";
#include "clsRoom.h";
#include "clsRoomsListScreen.h";
#include "clsDeleteRoomScreen.h";
#include "clsFindRoomScreen.h";
#include "clsUpdateRoomInfoScreen.h";
#include "clsAvailableRoomsScreen.h";
#include "clsAddNewRoomsScreen.h";
#include "clsGenerateRoomReportsScreen.h";
using namespace std;


class clsManageRoomsScreens :protected clsBase
{


private:

    enum enRoomMenuOptions 
    {
        eShowRoomsList = 1,
        eFindRoom = 2,
        eUpdateRoomInfo = 3,
        eDeleteRoom = 4,
        eAddNewRoom = 5,
        eShowAvailableRooms = 6,
        eGenerateRoomReports = 7,
        eExit = 8
    };

    static  void _GoBackToRoomMenu()
    {
        cout << "Press any key to go back to Main Menu...";
        system("pause>0");
        ShowManageDormRoomsMenu();
    }

    static short _ReadManageRoomsMenuOption()
    {
        cout << setw(ScreenWidth) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 8, "Enter Number between 1 to 8? ");
        return  Choice;

    }

    static void _ShowRoomsList()
    {
        clsRoomsListScreen::ShowDormRoomsList();

    }

    static void _ShowAvailableRooms()
    {

        clsAvailableRoomsScreen::ShowAvailableRoomListScreen();
    }

    static void _FindRoom()
    {

        clsFindRoomScreen::ShowFindRoomScreen();
    }

    static void _AddNewRoom()
    {
        clsAddNewRoomsScreen::ShowAddNewRoomScreen();

    }

    static void _UpdateRoomInfo()
    {
        clsUpdateRoomInfoScreen::ShowUpdateRoomScreen();

    }

    static void _DeleteRoom()
    {

        clsDeleteRoomScreen::DeleteDormRoomScreen();

    }

    static void _GenerateRoomReports()
    {

        clsGenerateRoomReportsScreen::GenerateRoomsReportScreen();
    }


    static void _PerformRoomsMenuOption(enRoomMenuOptions ManageRoomsMenuOptions)
    {
        switch (ManageRoomsMenuOptions)
        {
        case clsManageRoomsScreens::eShowRoomsList:
            system("cls");
            _ShowRoomsList();
            _GoBackToRoomMenu();
            break;

        case clsManageRoomsScreens::eShowAvailableRooms:
            system("cls");
            _ShowAvailableRooms();
            _GoBackToRoomMenu();
            break;

        case clsManageRoomsScreens::eFindRoom:
            system("cls");
            _FindRoom();
            _GoBackToRoomMenu();
            break;

        case clsManageRoomsScreens::eAddNewRoom:
            system("cls");
            _AddNewRoom();
            _GoBackToRoomMenu();
            break;

        case clsManageRoomsScreens::eUpdateRoomInfo:
            system("cls");
            _UpdateRoomInfo();
            _GoBackToRoomMenu();
            break;

        case clsManageRoomsScreens::eDeleteRoom:
            system("cls");
            _DeleteRoom();
            _GoBackToRoomMenu();
            break;

        case clsManageRoomsScreens::eGenerateRoomReports:
            system("cls");
            _GenerateRoomReports();
            _GoBackToRoomMenu();
            break;

        case clsManageRoomsScreens::eExit:
        
        
        default:
            break;
        }
    }



public:

    static void ShowManageDormRoomsMenu()
    {

        if (!clsBase::_CheckAccessRights(clsLogin::eManageRooms))
        {
            return;
        }


        system("cls");
        clsBase::_DrawScreenHeader("\t Manage Rooms Screen");

        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n";
        cout << setw(ScreenWidth) << left << "" << Red << "\tManage Dorm Rooms Menu\n";
        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;
        cout << setw(ScreenWidth) << left << "" << " [1]   Show Rooms List.\n";
        cout << setw(ScreenWidth) << left << "" << " [2]   Find Room.\n";
        cout << setw(ScreenWidth) << left << "" << " [3]   Update Room Info.\n";
        cout << setw(ScreenWidth) << left << "" << " [4]   Delete Room.\n";
        cout << setw(ScreenWidth) << left << "" << " [5]   Add New Room.\n";
        cout << setw(ScreenWidth) << left << "" << " [6]   Show Available Rooms.\n";
        cout << setw(ScreenWidth) << left << "" << " [7]   Generate Room Reports.\n";
        cout << setw(ScreenWidth) << left << "" << " [8]   Exit.\n";
        cout << setw(ScreenWidth) << left << "" << Green << "===========================================\n" << White;
        _PerformRoomsMenuOption((enRoomMenuOptions)_ReadManageRoomsMenuOption());




    }










};

