#pragma once
#include <iostream>
#include <iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUserScreen.h"
#include "Global.h"
#include "clsLoginRegister.h"
#include  "clsCurrencyExchange.h"
using namespace std;

class clsMainScreen :protected clsScreen
{
private :
	enum enMainMenuOptions {eListClient =1, eAddClient=2, eDeleteClient=3,eUpdateClient =4, eFindClient =5,eShowTransactionsMenu=6, 
	eManageUsers =7,eLoginRegister=8, eCurrencyExchange=9, eExit = 10};
	static short _ReadMainMenuOptions()
	{
		cout << setw(37) << left << " " << "Choose what do you want to do ? [1 to 10] ";
		short Choice = clsInputValidate::ReadNumberBetween(1,10,"Enter a number between 1 to 10");
		return Choice;


	}
	static  void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

		system("pause>0");
		ShowMainMenu();
	}
	static void _ShowClientsListScreen()
	{
		//cout << "\n Clients Lists will be here ! ";
		clsClientsListScreen::ShowClientsList();
	}
	static void _ShowAddClientsScreen()
	{
		clsAddNewClientScreen::_ShowAddNewClientScreen();
	}
	static void _ShowDeleteClientsScreen()
	{
		//cout << "\n Delete  Clients  will be here ! ";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _ShowUpdateClientsScreen()
	{
		//cout << "\nUpdate  Clients will be here ! ";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientsScreen()
	{
		//cout << "\nFind  Clients will be here ! ";
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionsScreen()
	{
		//cout << "\nTransactions  will be here ! ";
		clsTransactionsScreen::ShowTransactionsMenu();
	}
	static void _ShowManageUsersScreen()
	{
		//cout << "\nManage Users  will be here ! ";
		clsManageUserScreen::ShowManageUserMenu();
	}
	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegister::ShowUserRegisterMenu();
	}
	static void _ShowCurrencyExchangerScreen()
	{
		clsCurrencyExchange::ShowCurrencyExchangeScreen();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}





	static void _PerformMainMenuOptions(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case clsMainScreen::eListClient:
			system("cls");
			_ShowClientsListScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eAddClient:
			system("cls");
			_ShowAddClientsScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eDeleteClient:
			system("cls");
			_ShowDeleteClientsScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eUpdateClient:
			system("cls");
			_ShowUpdateClientsScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eFindClient:
			system("cls");
			_ShowFindClientsScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eShowTransactionsMenu:
			system("cls");
			_ShowTransactionsScreen();
			_GoBackToMainMenu();


			break;
		case clsMainScreen::eManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();


			break;
		case clsMainScreen::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();

			break;
		case clsMainScreen::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangerScreen();
			_GoBackToMainMenu();

			break;


		case clsMainScreen::eExit:
			system("cls");
			_Logout();
			break;
		default:
			break;
		}
	}

public:
	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << " " << "======================================================================\n";
		cout << setw(37) << left << " " << "\t\t\t Main Menu \n";
		cout << setw(37) << left << " " << "======================================================================\n";
		cout << setw(37) << left << " " << "\t[1] Show Client List \n";
		cout << setw(37) << left << " " << "\t[2] Add New  Client  \n";
		cout << setw(37) << left << " " << "\t[3] Delete  Client  \n";
		cout << setw(37) << left << " " << "\t[4] Update Client  \n";
		cout << setw(37) << left << " " << "\t[5] Find Client  \n";
		cout << setw(37) << left << " " << "\t[6] Transactions  \n";
		cout << setw(37) << left << " " << "\t[7] Manage User  \n";
		cout << setw(37) << left << " " << "\t[8] Login Register \n";
		cout << setw(37) << left << " " << "\t[9]Currency Exchange \n";

		cout << setw(37) << left << " " << "\t[10] Logout \n";
		cout << setw(37) << left << " " << "======================================================================\n";



		_PerformMainMenuOptions((enMainMenuOptions)_ReadMainMenuOptions());





	}
};

