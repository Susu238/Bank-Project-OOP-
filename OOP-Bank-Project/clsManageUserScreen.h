#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsUsersList.h"
#include "clsAddUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"



using namespace std;

class clsManageUserScreen :protected clsScreen
{
private:
	enum enManageUserMainMenuOptions {
		eUserList = 1, eAddUser = 2, eUpdateUser = 3, eDeleteUser = 4, eFindUser=5,eMainMeu=6

	};
	static short ReadManageUserMainMenuOptions()
	{
		cout << setw(37) << left << " " << "Choose what do you want to do ? [1 to 6] ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 6, "Enter a number between 1 to 6");
		return Choice;


	}
	static  void _GoBackToManageUserMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

		system("pause>0");
		ShowManageUserMenu();
	}
	static void _ShowUserListScreen()
	{
		//cout << "\nUser list will be here ! ";
		clsUsersList::ShowUsersList();
	}
	static void _ShowAddUserScreen()
	{
		//cout << "\n Add User will be here ! ";
		clsAddUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowUpdateUserScreen()
	{
		//cout << "\nUpdate User  will be here ! ";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _ShowFindUserScreen()
	{
		//cout << "\nFind User  will be here ! ";
		clsFindUserScreen::ShowFindUserScreen();
	}
	static void _ShowDeleteUserScreen()
	{
		//cout << "\nDelete User  will be here ! ";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}


	static void _ShowEndScreen()
	{
		cout << "\nEnd Screen  will be here ! ";
	}
	static void _PerformManageUserMainMenuOptions(enManageUserMainMenuOptions  ManageUserMainMenuOption)
	{
		switch (ManageUserMainMenuOption)
		{
		case enManageUserMainMenuOptions::eUserList:
			system("cls");
			_ShowUserListScreen();
			_GoBackToManageUserMainMenu();
			break;
		case enManageUserMainMenuOptions::eAddUser:
			system("cls");
			_ShowAddUserScreen();
			_GoBackToManageUserMainMenu();
			break;
		case enManageUserMainMenuOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUserMainMenu();
			break;
		case enManageUserMainMenuOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUserMainMenu();
			break;

		}
		case enManageUserMainMenuOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUserMainMenu();
			break;

		}
		case enManageUserMainMenuOptions::eMainMeu:
		{

		}



		}
	}
public:
	static void ShowManageUserMenu()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\t\t Manage User Screen ");
		cout << setw(37) << left << " " << "======================================================================\n";
		cout << setw(37) << left << " " << "\t\t\tManage User  Main Menu \n";
		cout << setw(37) << left << " " << "======================================================================\n";
		cout << setw(37) << left << " " << "\t[1] Users List \n";
		cout << setw(37) << left << " " << "\t[2] Add User \n";
		cout << setw(37) << left << " " << "\t[3] Update User \n";
		cout << setw(37) << left << " " << "\t[4] Delete User\n";

		cout << setw(37) << left << " " << "\t[5] Find User \n";

		cout << setw(37) << left << " " << "\t[6] Main Menu \n";
		cout << setw(37) << left << " " << "======================================================================\n";
		_PerformManageUserMainMenuOptions((enManageUserMainMenuOptions)ReadManageUserMainMenuOptions());

	}
};

