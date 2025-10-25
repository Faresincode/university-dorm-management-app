#pragma once

#include <iostream>
#include "Global.h";
#include "clsBase.h";

using namespace std;

class clsRegisterLoginScreen : protected clsBase
{

private:

	static void _DrawLoginRegisterScreenHeader()
	{

		cout << "\n" << setw(15) << "" << Green << "______________________________________________________________________________________________________________________\n\n" << White;
		cout << setw(16) << "" << left
			<< Green << "| " << Blue << setw(25) << "Login Date And Time" << left
			<< Green << "| " << Blue << setw(25) << "User Name" << left
			<< Green << "| " << Blue << setw(20) << "Password" << left
			<< Green << "| " << Blue << setw(13) << "Permissions" << left
			<< Green << "| " << Blue << setw(25) << "Logout Date And Time" << left;

		cout << "\n" << setw(15) << "" << Green << "______________________________________________________________________________________________________________________\n\n" << White;

	}


	static void _PrintUserRegisterLineRecord(clsLogin::stLoginRegister User)
	{
		cout << setw(16) << "" << left
			<< Green << "| " << White << setw(25) << User.LoginDateTime << left
			<< Green << "| " << White << setw(25) << User.Username << left
			<< Green << "| " << White << setw(20) << User.Password << left
			<< Green << "| " << White << setw(13) << User.Permissions << left
			<< Green << "| " << White << setw(25) << User.LogoutDateTime << left;
	}


	static void PrintRegisterTable(vector<clsLogin::stLoginRegister>vLoginRegisterRecord)
	{

		_DrawLoginRegisterScreenHeader();
		for (clsLogin::stLoginRegister& User : vLoginRegisterRecord)
		{
			_PrintUserRegisterLineRecord(User);
			cout << endl;
		}
		cout << setw(15) << "" << Green << "______________________________________________________________________________________________________________________\n" << White;


	}

public:
	
	
	static void RegisterLoginScreen()
	{

		if (!clsBase::_CheckAccessRights(clsLogin::enPermissions::eLoginRegister))
		{
			return;
		}

		system("cls");
		clsBase::_DrawScreenHeader("\t  Login Register Users Screen");

		if (clsInputValidate::IsSureToPerform())
		{
			system("cls");

			vector<clsLogin::stLoginRegister>vLoginRegisterRecord = clsLogin::GetRegisterLoginsList();
			string Title = "\t  Login Register Users Screen";
			string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";
			clsBase::_DrawScreenHeader(Title, SubTitle);

			if (vLoginRegisterRecord.size() == 0)
			{
				cout << setw(ScreenWidth) << "" << left << Red << "No User Login Register Available\n" << White;
			}
			else
			{
				PrintRegisterTable(vLoginRegisterRecord);
			}
		}
		


	}

};

