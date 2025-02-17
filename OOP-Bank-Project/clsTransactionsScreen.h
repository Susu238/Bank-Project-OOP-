#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactionsScreen :protected clsScreen
{
private:
	enum enTransactionsMainMenuOptions {
		eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3,eShowTransfer=4,eShowTransferLog =5, eShowMainMenu= 6
		
	};
	static short ReadTransactionsMainMenuOptions()
	{
		cout << setw(37) << left << " " << "Choose what do you want to do ? [1 to 6] ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 6, "Enter a number between 1 to 6");
		return Choice;


	}
	static  void _GoBackToTransactionsMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

		system("pause>0");
		ShowTransactionsMenu();
	}
	static void _ShowDepositScreen()
	{
		//cout << "\nDeposit  will be here ! ";
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen()
	{
		//cout << "\nWithdraw will be here ! ";
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalanceScreen()
	{
		//cout << "\nTotal Balance will be here ! ";
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _ShowTransferScreen()
	{
		//cout << "\nTotal Balance will be here ! ";
		clsTransferScreen::ShowTransferScreen();
	}
	static void _ShowTransferLogScreen()
	{
		//cout << "\nTotal Balance will be here ! ";
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _ShowEndScreen()
	{
		cout << "\nEnd Screen  will be here ! ";
	}
	static void _PerformTransactionsMainMenuOptions(enTransactionsMainMenuOptions  TransactionsMainMenuOption)
	{
		switch (TransactionsMainMenuOption)
		{
		case enTransactionsMainMenuOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMainMenu();
			break;
		case enTransactionsMainMenuOptions::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMainMenu();
			break;
		case enTransactionsMainMenuOptions::eShowTotalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMainMenu();
			break;
		case enTransactionsMainMenuOptions::eShowTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMainMenu();
			break;
		case enTransactionsMainMenuOptions::eShowTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMainMenu();
			break;

		case enTransactionsMainMenuOptions::eShowMainMenu:
		{

		}

		
		}
	}
public:
	static void ShowTransactionsMenu()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\t\t Transactions Screen");
		cout << setw(37) << left << " " << "======================================================================\n";
		cout << setw(37) << left << " " << "\t\t\tTransactions Main Menu \n";
		cout << setw(37) << left << " " << "======================================================================\n";
		cout << setw(37) << left << " " << "\t[1] Deposit \n";
		cout << setw(37) << left << " " << "\t[2] Withdraw  \n";
		cout << setw(37) << left << " " << "\t[3] Total Balance \n";
		cout << setw(37) << left << " " << "\t[4] Transfer \n";
		cout << setw(37) << left << " " << "\t[5] Transfer  Log \n";

		cout << setw(37) << left << " " << "\t[6] Main Menu \n";
		cout << setw(37) << left << " " << "======================================================================\n";
		_PerformTransactionsMainMenuOptions((enTransactionsMainMenuOptions) ReadTransactionsMainMenuOptions());

	}
};

